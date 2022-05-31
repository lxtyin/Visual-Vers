#include "widget.h"
#include "ui_widget.h"
#include "CommitNodeButton.h"
#include "Node.h"
#include "operator.h"
#include "CommitNodeButton.h"
#include <QPainter>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QScrollBar>
#include <QDebug>

Widget* Widget::ins = nullptr;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ins = this;
    ui->setupUi(this);
    ui->userAvatar->installEventFilter(this);
    ui->currentFlag->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    updateAvatar();
}

Widget::~Widget() {
    delete ui;
}

void Widget::updateAvatar(){ //更新显示的头像
    string path = curAvatar;
    if(judgePath(path) == EMPTY_PATH) path = DEFAULT_AVATAR;
    QPixmap pix(Str2Q(path));
    ui->userAvatar->setPixmap(pix.scaled(ui->userAvatar->size(), //保持宽高比，平滑缩放
                                         Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

//事件过滤器，处理两个头像的交互
bool Widget::eventFilter(QObject *watched, QEvent *event){
    if(watched == ui->userAvatar){
        if(event->type() == QEvent::MouseButtonDblClick){
            // 更改头像
            QString path = QFileDialog::getOpenFileName(this, "选择一张头像", QDir::currentPath(),
                                                        "图片文件(*.jpg *.png)");
            if(!path.isEmpty()){
                string str = Q2Str(path);
                curAvatar = "avatars\\" + str.substr(str.find_last_of('/')+1, 100);
                CopyAFile(str, curAvatar);
                updateAvatar();
                loadAvatar(curAvatar);
            }
        }
    }
}

void Widget::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    updateGraph();
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
    auto hbar = ui->scrollArea->horizontalScrollBar();
    hbar->setValue(hbar->maximum());
}

// ----------- button ------------- //

//刷新并返回当前工作区状态（是否干净）
#define isWorkSpaceClean on_freshButton_clicked()
bool Widget::on_freshButton_clicked(){
    // 列出具体修改内容，先只在文件层面上，不具体到修改那几行
    // 用+, -, * 表示新增，删除，修改
    // 具体到单个文件的修改，对整个文件夹的修改也会逐个列出所有文件
    // 双击单个文件项则启动diff，按行列出具体修改内容
    // 因不及时刷新可能导致找不到，需提示刷新
//    CommitNodeButton::currentCommitNodeButton->beclicked();
    ui->workSpaceWidget->clear();
    vector<ModifyItem*> diff;
    diffWithNode(currentBranch->position, ROOT_PATH, diff);

    if(diff.empty()){
        ui->workSpaceWidget->addItem("没有未提交的修改！");
        return true;
    }else{
        for(auto itm: diff) ui->workSpaceWidget->addItem(itm);
        return false;
    }
}

//提交按钮
void Widget::on_commitButton_clicked() {
    bool ok;
    QString str = QInputDialog::getText(this, "提交", "请输入comment:", QLineEdit::Normal, "", &ok);
    if(ok){
        commitAllWork(Q2Str(str));
        currentBranch->position->myButton->clicked();
        updateGraph();
        on_freshButton_clicked();
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
