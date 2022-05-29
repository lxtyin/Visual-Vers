#include "widget.h"
#include <QApplication>
#include "command.h"
#include "operator.h"
#include "startdialog.h"
#include <windows.h>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    AllocConsole();    //为调用进程分配一个新的控制台
    ShowWindow(GetConsoleWindow(), SW_HIDE);    //隐藏自己创建的控制台解决黑款闪烁问题

    StartDialog st; //初始界面 选择仓库目录
    if(st.exec() == QDialog::Rejected) return 0;

    Widget w;
    readAllNodes(); //读取
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
