#include "widget.h"
#include <QApplication>
#include "command.h"
#include "operator.h"
#include "startdialog.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    StartDialog st; //初始界面 选择仓库目录
    if(st.exec() == QDialog::Rejected) return 0;

    Widget w;
    readAllNodes();
    readAllCommits();
    readBranch();

    w.show();
    w.updateGraph();
    w.on_freshButton_clicked();

    int ret = a.exec();

    //回收内存，实际new的对象全都在几个map里
    for(auto pi: nodePool) delete pi.second;
    for(auto pi: branch) delete pi.second;

    return ret;
}
