
#ifndef DIFFDIALOG_H
#define DIFFDIALOG_H

#include <string>
#include <vector>
#include <QDialog>
using namespace std;

namespace Ui { class diffDialog; }

class diffDialog : public QDialog {
Q_OBJECT

public:
    explicit diffDialog(vector<string> &diff, const string &name, QWidget *parent = nullptr);
    ~diffDialog() override;

private:
    Ui::diffDialog *ui;
};


#endif //DIFFDIALOG_H
