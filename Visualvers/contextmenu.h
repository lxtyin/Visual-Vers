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
    void on_switchToNodeButton_clicked();
    void on_pullFromCommitButton_clicked();
    void on_diffWithNodeButton_clicked();
private:
    Ui::ContextMenu *ui;
};

#endif // CONTEXTMENU_H
