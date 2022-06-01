#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <QDialog>

namespace Ui {
class ContextMenu;
}
class CommitNodeButton;

class ContextMenu : public QDialog
{
    Q_OBJECT
    CommitNodeButton *but;
public:
    explicit ContextMenu(CommitNodeButton *_but, QWidget *parent = 0);
    ~ContextMenu();

public slots:
    void on_switchToNodeButton_clicked();       //切换到节点按钮
    void on_pullFromCommitButton_clicked();     //拉取合并按钮
    void on_diffWithNodeButton_clicked();       //对比差异按钮
private:
    Ui::ContextMenu *ui;
};

#endif // CONTEXTMENU_H
