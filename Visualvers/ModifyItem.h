//
// Created by lx_tyin on 2022/4/29.
//

#ifndef MODIFYITEM_H
#define MODIFYITEM_H

#include <string>
#include <QWidget>
#include <QListWidgetItem>
using namespace std;

class ModifyItem: public QListWidgetItem{
public:
    vector<QListWidgetItem*> linkItem; //相关联项
    char type;   //+, -, *三种样式, ' '表无样式
    string info; //显示内容，实际链接都是path，info为路径时，自动去除前面的RootPath
    string path1, path2; //产生diff的两个文件，path1->path2
    string applyTar; //强制更新目标，若不为空则允许应用path2->applyTar

    ModifyItem(char _type, const string &_info, const string &_p1 = "", const string &_p2 = "", QListWidget *parent = nullptr);
    void beclicked();
};


#endif //MODIFYITEM_H
