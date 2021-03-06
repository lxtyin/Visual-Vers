
#include "command.h"
#include "ModifyItem.h"
#include "operator.h"
#include "diffdialog.h"
#include "widget.h"
#include <QMessageBox>
#include <QObject>

ModifyItem::ModifyItem(char _type, const string &_info, const string &_p1, const string &_p2, QListWidget *parent):
    type(_type), info(_info), path1(_p1), path2(_p2), QListWidgetItem(parent)
{
    // 三种样式
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    if(_type == '+'){
        QBrush brush1(QColor(189, 250, 186, 255));
        brush1.setStyle(Qt::Dense2Pattern);
        setFont(font);
        setBackground(brush1);
    }
    if(_type == '-'){
        QBrush brush2(QColor(255, 138, 138, 255));
        brush2.setStyle(Qt::Dense6Pattern);
        setFont(font);
        setBackground(brush2);
    }
    if(_type == '*'){
        QBrush brush3(QColor(161, 197, 255, 255));
        brush3.setStyle(Qt::BDiagPattern);
        setFont(font);
        setBackground(brush3);
    }

    applyTar = "";
    //若info为路径，自动去除ROOT_PATH部分
    bool hasRoot = true;
    for(int i=0;i<ROOT_PATH.size();i++){
        if(i >= info.size() || info[i] != ROOT_PATH[i]){
            hasRoot = false;
            break;
        }
    }
    if(hasRoot) info = info.substr(ROOT_PATH.size()+1, 100);
    string txt = "   " + info;
    txt[0] = type;
    setText(Str2Q(txt));
}

void ModifyItem::beclicked(){
    bool f1 = (judgePath(path1) == FILE_PATH);
    bool f2 = (judgePath(path2) == FILE_PATH);
    if(!f1 && !f2) return; //可能因未及时刷新导致文件不存在

    if((f1 && !isTextFile(path1)) || (f2 && !isTextFile(path2))){
        int res = QMessageBox::question(MainWidget, "提示", "这并不是一个文本格式文件，"
                                                          "可能无法查看您需要的内容，继续吗？", QMessageBox::Yes, QMessageBox::No);
        if(res == QMessageBox::No) return;
    }

    vector<string> result;
    getDiffBetween(path1, path2, result);
    if(applyTar.empty()){
        diffDialog *dlg = new diffDialog(result, info, "", "", MainWidget);
        dlg->exec();
    }else{//可应用到工作区的
        diffDialog *dlg = new diffDialog(result, info, path2, applyTar, MainWidget);
        if(dlg->exec() == QDialog::Accepted){ //应用到目标
            for(auto *it: linkItem) delete it;
            delete this;
        }
    }
}
