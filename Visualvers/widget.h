/*
 * 此类为整个窗口的类，其中ui采用单例
*/
#ifndef WIDGET_H
#define WIDGET_H
#include <cstring>
#include "ui_widget.h"
#include <QWidget>
#include <unordered_set>

class CommitNode; //前置声明

class Widget : public QWidget
{
    Q_OBJECT
public:
    static Widget *ins;// 单例
    Ui::Widget *ui;
    std::string curAvatar; //当前用户头像

    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void updateGraph(); //计算并刷新绘图区
    void updateAvatar();//更新用户头像
    //在某处放置按钮（CommitNodeButton）
    float putButton(CommitNode *p, float xPos, float yPos, std::unordered_set<CommitNode*> &vis);

protected:
    bool eventFilter(QObject *watched, QEvent *event); //事件过滤器处理头像点击事件
    void resizeEvent(QResizeEvent *event);             //窗口变化事件

public slots:
    bool on_freshButton_clicked();                     //刷新建交互
    void on_commitButton_clicked();                    //提交按钮交互
    void on_closeButton_clicked();                     //关闭按钮交互
//    void on_switchToBranchButton_clicked();
//    void on_createBranchButton_clicked();
    void on_restoreButton_clicked();                   //撤销按钮交互

    void on_workSpaceWidget_itemDoubleClicked(QListWidgetItem *item); //diff列表项查看
};

//便捷使用
#define MainWidget Widget::ins
#define MainUI Widget::ins->ui
#define isWorkSpaceClean MainWidget->on_freshButton_clicked()

#endif // WIDGET_H
