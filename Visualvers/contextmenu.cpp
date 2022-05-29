#include "contextmenu.h"
#include "ui_contextmenu.h"
#include "widget.h"
#include "CommitNodeButton.h"
#include "command.h"
#include "Node.h"
#include "Branch.h"
#include "ModifyItem.h"
#include "operator.h"
#include <QInputDialog>
#include <QDebug>

ContextMenu::ContextMenu(CommitNodeButton *_but, QWidget *parent) :
    QDialog(parent, Qt::Popup), but(_but),
    ui(new Ui::ContextMenu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    bool ok = (but->myNode != currentBranch->position); //设置一系列按钮是否可用
    ui->switchToNodeButton->setEnabled(ok);
    ui->pullFromCommitButton->setEnabled(ok);
    ui->diffWithNodeButton->setEnabled(ok);
}

//和某节点对比
void ContextMenu::on_diffWithNodeButton_clicked(){
    // 和刷新部分同理
    MainUI->workSpaceWidget->clear();
    vector<ModifyItem*> diff;
    diffWithNode(but->myNode, ROOT_PATH , diff);

    MainUI->workSpaceWidget->addItem(("*** 当前工作区与节点 " +
        but->myNode->id + " 对比 ***").c_str());

    if(diff.empty()){
        MainUI->workSpaceWidget->addItem("没有任何差异");
    }else for(auto itm: diff){
        MainUI->workSpaceWidget->addItem(itm);
    }
    accept();
}

//拉取合并按钮
void ContextMenu::on_pullFromCommitButton_clicked() {
    if(!isWorkSpaceClean){
        Error("工作区有未提交的修改内容，请先提交或撤销");
        accept();
        return;
    }
    bool ok;
    QString str =  QInputDialog::getText(this, "提交", "为本次合并输入comment:", QLineEdit::Normal, "", &ok);
    if(ok){
        vector<ModifyItem*> diff;
        ok = pullFromCommit(but->myNode, Q2Str(str), diff, 0);
        if(!ok){
            Warning("合并失败：存在一些冲突，您可以在下方框中查看产生冲突的文件，随后手动修改或强制合并。");
            MainUI->workSpaceWidget->clear();
            for(auto itm: diff) MainUI->workSpaceWidget->addItem(itm);
        }else{
            Hint("没有发生冲突，合并成功！");
            currentBranch->position->myButton->clicked();
            MainWidget->updateGraph();
            MainWidget->on_freshButton_clicked();
        }
    }
    accept();
}

//切换工作区按钮
void ContextMenu::on_switchToNodeButton_clicked() {
    if(!isWorkSpaceClean){
        Error("工作区有未提交的修改内容，请先提交或撤销");
        accept();
        return;
    }
    switchToNode(but->myNode);
    but->clicked();
    MainWidget->updateGraph();
    MainWidget->on_freshButton_clicked();
    accept();
}

ContextMenu::~ContextMenu()
{
    delete ui;
}
