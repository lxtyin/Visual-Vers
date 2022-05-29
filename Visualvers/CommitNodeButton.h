#ifndef COMMITNODEBUTTON_H
#define COMMITNODEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QContextMenuEvent>

class CommitNode; //前置声明

class CommitNodeButton : public QPushButton {
    Q_OBJECT
public:
    static CommitNodeButton *currentCommitNodeButton;

    CommitNode *myNode;
    float xPos, yPos;
    float occupyHeight; //这个按钮后续占用的总高度，部署前计算。

    explicit CommitNodeButton(CommitNode *_node, QWidget *parent = nullptr);
    void setImage(QString _img);
    void setPosition(float _x, float _y);

protected:
    void contextMenuEvent(QContextMenuEvent *ev);

public slots:
    void beclicked();
};

#endif // COMMITNODEBUTTON_H
