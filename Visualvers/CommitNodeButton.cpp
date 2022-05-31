#include "CommitNodeButton.h"
#include "widget.h"
#include "Node.h"
#include "Branch.h"
#include "command.h"
#include "contextmenu.h"

//CommitNodeButton* CommitNodeButton::currentCommitNodeButton = nullptr;
set<CommitNodeButton*> CommitNodeButton::allbut;
CommitNodeButton::CommitNodeButton(CommitNode *_node, QWidget *parent) :
occupyHeight(0), QPushButton(parent), xPos(0), yPos(0) {

    myNode = _node;
    allbut.insert(this);
    setText("");
    setImage(":/images/img/CButtonUp.png");

    connect(this, &CommitNodeButton::clicked, this, &CommitNodeButton::beclicked);
}

CommitNodeButton::~CommitNodeButton(){
    allbut.erase(this);
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
//    if(currentCommitNodeButton != nullptr) currentCommitNodeButton->setImage(":/images/img/CButtonUp.png");
//    currentCommitNodeButton = this;
    for(CommitNodeButton* x: allbut){
        if(x->myNode->avatar == myNode->avatar){
            x->setImage(":/images/img/CButtonLight.png");
        }else{
            x->setImage(":/images/img/CButtonUp.png");
        }
    }
    setImage(":/images/img/CButtonDown.png");
    MainUI->idLabel->setText(Str2Q("ID:  \t" + myNode->id));
    MainUI->commentTextEdit->setText(Str2Q(myNode->comment));
    MainUI->timeLabel->setText(Str2Q("Time:\t" + myNode->time));

    QPixmap pix(Str2Q(myNode->avatar));
    MainUI->curAvatar->setPixmap(pix.scaled(MainUI->curAvatar->size(),
                                            Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void CommitNodeButton::contextMenuEvent(QContextMenuEvent *ev){
    beclicked();
    ContextMenu *menu = new ContextMenu(this, MainWidget);
    menu->move(ev->globalPos());
    menu->open();
}


