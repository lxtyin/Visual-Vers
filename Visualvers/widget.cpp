#include "widget.h"
#include "ui_widget.h"
#include "CommitNodeButton.h"
#include "Node.h"
#include "operator.h"
#include "CommitNodeButton.h"
#include <QPainter>
#include <QInputDialog>
#include <QMessageBox>
#include <QScrollBar>

Widget* Widget::ins = nullptr;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ins = this;
    ui->setupUi(this);
    ui->currentFlag->setAttribute(Qt::WA_TransparentForMouseEvents, true);
}

Widget::~Widget()
{
    delete ui;
}

//更新版本图，dp计算每个节点后续所需要的总高度
void calcuMaxHeight(CommitNode *p, unordered_set<CommitNode*> &vis){
    vis.insert(p);

    int height = 0;
    for(auto *v: p->nextCommit){
        if(vis.count(v)) continue;
        calcuMaxHeight(v, vis);
        height += v->myButton->occupyHeight;
    }
    p->myButton->occupyHeight = max(80, height);
}

//放置CommitNodeButton，返回放的最远的按钮位置
float Widget::putButton(CommitNode *p, float xPos, float yPos, unordered_set<CommitNode*> &vis){
    vis.insert(p);

    float res = xPos;
    p->myButton->setPosition(xPos, yPos);
    p->myButton->setParent(ui->scrollAreaWidgetContents);
    p->myButton->show();
    float nowH = yPos - p->myButton->occupyHeight / 2;

    float buttonH = p->myButton->height(), buttonW = p->myButton->width();

    for(auto *v: p->nextCommit){
        auto *vb = v->myButton;
        float h = vb->occupyHeight;
        if(!vis.count(v)){
            res = max(res, putButton(v, xPos + 150, nowH + h / 2, vis));
            nowH += h;
        }
        //确定连线端点
        QPoint p1, p2;
        if(abs(xPos - vb->xPos) < buttonW){
            p1.setX(xPos + buttonW/2);
            p2.setX(vb->xPos + buttonW/2);
        }else if(xPos < vb->xPos){
            p1.setX(xPos + buttonW);
            p2.setX(vb->xPos);
        }else{
            p1.setX(xPos);
            p2.setX(vb->xPos + buttonW);
        }
        if(abs(yPos - vb->yPos) < buttonH){
            p1.setY(yPos + buttonH/2);
            p2.setY(vb->yPos + buttonH/2);
        }else if(yPos < vb->yPos){
            p1.setY(yPos + buttonH);
            p2.setY(vb->yPos);
        }else{
            p1.setY(yPos);
            p2.setY(vb->yPos + buttonH);
        }
        ui->scrollAreaWidgetContents->addLine(QLineF(p1, p2));
    }
    return res;
}

//绘制节点树形图（根据已存下来的CommitNode内容
void Widget::updateGraph(){
    ui->scrollAreaWidgetContents->clearContents();
    unordered_set<CommitNode*> vis; //unordered_set自动将指针变量转换为地址值
    calcuMaxHeight(CommitNode::rootCommit, vis);
    vis.clear();

//    QPixmap pixmap;
//    pixmap.load(":/images/img/flag.png");
//    ui->currentFlag->setPixmap(pixmap);

    float mxH = CommitNode::rootCommit->myButton->occupyHeight;
    float mxW = putButton(CommitNode::rootCommit, 50, max(float(ui->scrollArea->height()), mxH) / 2, vis);

    ui->currentFlag->move(currentBranch->position->myButton->xPos,
                          currentBranch->position->myButton->yPos);
    ui->currentFlag->raise();
    ui->scrollAreaWidgetContents->setMinimumSize(mxW + 300, mxH + 100);
    ui->scrollArea->update();
//    QScrollBar *hbar = ui->scrollArea->horizontalScrollBar();
//    hbar->setValue(hbar->value()); //滚动到末尾？没作用
}

// ----------- button ------------- //

//刷新并返回当前工作区状态（是否干净）
#define isWorkSpaceClean on_freshButton_clicked()
bool Widget::on_freshButton_clicked(){
    // 列出具体修改内容，先只在文件层面上，不具体到修改那几行
    // 用+, -, * 表示新增，删除，修改
    // 对于整个新增或删除的文件夹，仅用一条+或-表示，*一定对应的是单个文件的修改
    // 双击列表项中，文件夹的+或-，则去工作区中找到此目录将其展开一层； 双击单个文件项则启动diff，按行列出具体修改内容
    // 因不及时刷新可能导致找不到，需提示刷新
    ui->workSpaceWidget->clear();
    vector<ModifyItem*> diff;
    diffWithNode(currentBranch->position, ROOT_PATH, diff);

    if(diff.empty()){
        ui->workSpaceWidget->addItem("工作区很干净，没有任何未提交的修改");
        return true;
    }else{
        for(auto itm: diff) ui->workSpaceWidget->addItem(itm);
        return false;
    }
}

//和某节点对比
void Widget::on_diffWithNodeButton_clicked(){
    // 和刷新部分同理
    ui->workSpaceWidget->clear();
    vector<ModifyItem*> diff;
    diffWithNode(CommitNodeButton::currentCommitNodeButton->myNode, ROOT_PATH , diff);

    ui->workSpaceWidget->addItem(("*** 当前工作区与节点 " +
        CommitNodeButton::currentCommitNodeButton->myNode->id + " 对比 ***").c_str());

    if(diff.empty()){
        ui->workSpaceWidget->addItem("没有任何差异");
    }else for(auto itm: diff){
        ui->workSpaceWidget->addItem(itm);
    }
}

//提交按钮
void Widget::on_commitButton_clicked() {
    bool ok;
    QString str = QInputDialog::getText(this, "提交", "请输入comment:", QLineEdit::Normal, "", &ok);
    if(ok){
        if(commitAllWork(Q2Str(str))){
            currentBranch->position->myButton->clicked();
            updateGraph();
            on_freshButton_clicked();
        }
    }
}

//切换工作区按钮
void Widget::on_switchToNodeButton_clicked() {
    if(!isWorkSpaceClean){
        Error("工作区有未提交的修改内容，请先提交或撤销");
        return;
    }
    if(CommitNodeButton::currentCommitNodeButton != nullptr){
        switchToNode(CommitNodeButton::currentCommitNodeButton->myNode);
        CommitNodeButton::currentCommitNodeButton->clicked();
        updateGraph();
        on_freshButton_clicked();
    }
}

//拉取合并按钮
void Widget::on_pullFromCommitButton_clicked() {
    if(!isWorkSpaceClean){
        Error("工作区有未提交的修改内容，请先提交或撤销");
        return;
    }
    if(CommitNodeButton::currentCommitNodeButton != nullptr){
        bool ok;
        QString str =  QInputDialog::getText(this, "提交", "为本次合并输入comment:", QLineEdit::Normal, "", &ok);
        if(ok){
            vector<ModifyItem*> diff;
            ok = pullFromCommit(CommitNodeButton::currentCommitNodeButton->myNode, Q2Str(str), diff, 0);
            if(!ok){
                Warning("合并失败：存在一些冲突，您可以在下方框中查看产生冲突的文件，随后手动修改或强制合并。");
                ui->workSpaceWidget->clear();
                for(auto itm: diff) ui->workSpaceWidget->addItem(itm);
            }else{
                Hint("没有发生冲突，合并成功！");
                currentBranch->position->myButton->clicked();
                updateGraph();
                on_freshButton_clicked();
            }
        }
    }
}

//撤销工作区更改按钮
void Widget::on_restoreButton_clicked() {
    auto res = QMessageBox::question(this, "确认", "你可能会丢失工作区未保存的更改，确定继续吗？");
    if(res == QMessageBox::Yes){
        restore();
        on_freshButton_clicked();
    }
}

void Widget::on_closeButton_clicked() {
    close();
}

void Widget::on_workSpaceWidget_itemDoubleClicked(QListWidgetItem *item) {
    auto it = dynamic_cast<ModifyItem*>(item);
    if(it != nullptr) it->beclicked();
}