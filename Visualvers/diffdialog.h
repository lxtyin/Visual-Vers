
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
     //构造函数中传入差异内容，传入应用差异时的源和目标
    explicit diffDialog(vector<string> &diff, const string &name,
                        const string &f = "", const string &t = "", QWidget *parent = nullptr);
    ~diffDialog() override;

private:
    Ui::diffDialog *ui;
};


#endif //DIFFDIALOG_H
