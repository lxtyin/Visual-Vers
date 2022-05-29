#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>
#include "command.h"

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT
    vector<string> lines;
public:
    explicit StartDialog(QWidget *parent = 0);
    ~StartDialog();

    void openRepo();
private:
    Ui::StartDialog *ui;
};

#endif // STARTDIALOG_H
