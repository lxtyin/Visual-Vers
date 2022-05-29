/*
 * 此类为整个窗口的类，其中ui采用单例
*/
#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"
#include <QWidget>
#include <unordered_set>

class CommitNode; //前置声明

class Widget : public QWidget
{
    Q_OBJECT
public:
    static Widget *ins;
    Ui::Widget *ui; // ui设置为单例

    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void updateGraph();
    float putButton(CommitNode *p, float xPos, float yPos, std::unordered_set<CommitNode*> &vis);

public slots:
    bool on_freshButton_clicked();
    void on_commitButton_clicked();
    void on_closeButton_clicked();
    void on_switchToNodeButton_clicked();
//    void on_switchToBranchButton_clicked();
//    void on_createBranchButton_clicked();
    void on_pullFromCommitButton_clicked();
    void on_restoreButton_clicked();
    void on_diffWithNodeButton_clicked();

    void on_workSpaceWidget_itemDoubleClicked(QListWidgetItem *item);
};


#define MainWidget Widget::ins
#define MainUI Widget::ins->ui

#endif // WIDGET_H