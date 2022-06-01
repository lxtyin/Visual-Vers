#ifndef COMMITNODEBUTTON_H
#define COMMITNODEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QContextMenuEvent>
#include <set>
using namespace std;

class CommitNode; //前置声明

class CommitNodeButton : public QPushButton {
    Q_OBJECT
    static set<CommitNodeButton*> allbut; //静态存放所有按钮
public:

    CommitNode *myNode; //对应的CommitNode，和数据层衔接
    float xPos, yPos;   //所处位置，与myPainterWidget衔接
    float occupyHeight; //这个按钮后续占用的总高度，部署前计算。

    CommitNodeButton(CommitNode *_node, QWidget *parent = nullptr);
    ~CommitNodeButton();

    void setImage(QString _img);         //设置图片
    void setPosition(float _x, float _y);//设置位置

protected:
    void contextMenuEvent(QContextMenuEvent *ev); //右键事件，和contextMenu衔接

public slots:
    void beclicked(); //点击事件
};

#endif // COMMITNODEBUTTON_H
