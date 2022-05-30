
#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <QString>
#include <vector>
#include "widget.h"
using namespace std;

//#define ROOT_PATH ("D:\\repo")
extern string ROOT_PATH;									//各种常量定义
#define REPO_PATH (ROOT_PATH + "\\.vvs")
#define DATA_PATH (REPO_PATH + "\\data")
#define DATA_PATH_ (REPO_PATH + "\\data\\")
#define COMMIT_PATH (REPO_PATH + "\\commits")
#define COMMIT_PATH_ (REPO_PATH + "\\commits\\")
#define BRANCH_FILE_PATH (REPO_PATH + "\\.branch")

#define DEFAULT_AVATAR ":/images/img/default.png"

const string EMPTY_HASH = "00000000000000000000000000000000";
const string ROOT_ID = "yemmm000000000000000000000000000t";

bool doCmd(const string &cmd, string &res);				    //各种命令行Api，文件操作
bool doCmd(const string &cmd);
bool CopyAFile(const string &a, const string &b);
void DeleteAny(const string &a);
void CreateFolder(const string &a);

const int FOLDER_PATH = 1;									//路径判断和路径宏
const int FILE_PATH = 2;
const int EMPTY_PATH = 0;
bool isempty(const string &path);
int judgePath(const string &path);

vector<string> fileList(const string &path, bool filter = true); //更高级的文件操作
void readFile(const string &path, vector<string> &lines);
void loadFile(const string &path, vector<string> &lines);
bool isTextFile(const string &path);

void Hint(const string &info, QWidget *parent = MainWidget);   //提示Api
void Warning(const string &info, QWidget *parent = MainWidget);
void Error(const string &info, QWidget *parent = MainWidget);

void mergeHash(string &hs, const string &name); 				//哈希值获取
string getHash(const string &path, const string &name, const char tag);

int str2int(const string &str);									//常用类型转换
string int2str(int x);
QString Str2Q(const string &str);
string Q2Str(const QString &qstr);
string gbk2utf(const string &gbkStr);							//为了windows文件操作
string utf2gbk(const string &utf8Str);

// 中文处理方式：
// 整个项目的字符串采用utf-8
// 仅面向windows，文件存取操作时转换到gbk
// 对所有文件操作封装
// 其中GBK和utf-8的转换代码来源网络

#endif //COMMAND_H
