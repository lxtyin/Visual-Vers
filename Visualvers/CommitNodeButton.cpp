#include "CommitNodeButton.h"
#include "widget.h"
#include "Node.h"
#include "Branch.h"
#include "command.h"
#include <QDebug>

CommitNodeButton* CommitNodeButton::currentCommitNodeButton = nullptr;
CommitNodeButton::CommitNodeButton(CommitNode *_node, QWidget *parent) :
occupyHeight(0), QPushButton(parent), xPos(0), yPos(0) {

    myNode = _node;
    setText("");
    setImage(":/images/img/CButtonUp.png");

    connect(this, &CommitNodeButton::clicked, this, &CommitNodeButton::beclicked);
}

void CommitNodeButton::setImage(QString _img) {
    QPixmap pixmap;

    pixmap.load(_img);
    setFixedSize(pixmap.width(), pixmap.height());
    setStyleSheet("QPushButton{border:0px}");
    setIcon(pixmap);
    setIconSize(QSize(pixmap.width(), pixmap.height()));
}

void CommitNodeButton::setPosition(float _x, float _y) {
    xPos = _x, yPos = _y;
    move(_x, _y);
}

void CommitNodeButton::beclicked() {
    if(currentCommitNodeButton != nullptr) currentCommitNodeButton->setImage(":/images/img/CButtonUp.png");
    currentCommitNodeButton = this;

//    setImage(":/images/img/CButtonDown.png");
    MainUI->idLabel->setText(Str2Q("Id:" + myNode->id));
    MainUI->commentTextEdit->setText(Str2Q(myNode->comment));

//    cout << (myNode == nullptr) << ' ' << (currentBranch == nullptr) << '\n';
//    return;
    bool ok = (myNode != currentBranch->position); //设置右边一系列按钮是否可用
    MainUI->switchToNodeButton->setEnabled(ok);
    MainUI->pullFromCommitButton->setEnabled(ok);
    MainUI->diffWithNodeButton->setEnabled(ok);
}
