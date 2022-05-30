//
// 此脚本主要处理文件相关指令，进行utf-gbk转换
// 还有一些通用函数
#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
#include <direct.h>
#include "command.h"
#include "widget.h"
#include <sys/stat.h>
#include <QMessageBox>

string ROOT_PATH = "";

bool doCmd(const string &cmd, string &res) {
    FILE *pipe = _popen(utf2gbk(cmd).c_str(), "r");
    if (!pipe)
        return false;

    char data[128];
    while (fgets(data, 127, pipe)) {
        res += data;
    }
    _pclose(pipe);
    return true;
}
bool doCmd(const string &cmd){
    string res;
    return doCmd(cmd, res);
}

//复制文件
bool CopyAFile(const string &a, const string &b){
    return CopyFile(utf2gbk(a).c_str(), utf2gbk(b).c_str(), false);
}

//删除任意文件/夹
void DeleteAny(const string &a){
    if(judgePath(a) == 1) doCmd("rd /s /q \"" + a + "\"");
    else DeleteFile(utf2gbk(a).c_str());
}
void CreateFolder(const string &a){ _mkdir(utf2gbk(a).c_str());}

//判断文件为空
bool isempty(const string &path){
    FILE *fp = fopen(utf2gbk(path).c_str(), "r");
    fgetc(fp);
    bool res = feof(fp);
    fclose(fp);
    return res;
}

//判断一个工作区路径的类型
int judgePath(const string &path){
    struct stat info{};
    if(stat(utf2gbk(path).c_str(), &info) != 0) return EMPTY_PATH;
    if(info.st_mode & S_IFDIR) return FOLDER_PATH;
    return FILE_PATH;
}

//列出目录下所有文件名，是否应用过滤(.ignore)
vector<string> fileList(const string &path, bool filter){
    vector<string> res;
    if(judgePath(path) != FOLDER_PATH) return res;
    _finddata_t fileinfo{};
    long fp = _findfirst(utf2gbk(path+"\\*").c_str(), &fileinfo);
    while(fp != -1){
        string str = gbk2utf(fileinfo.name);
        if(str != "." && str != ".." && str != ".git" && str != ".vvs" && (!filter || true)){ //filter..
            res.push_back(str);
        }
        if(_findnext(fp, &fileinfo)) break;
    }
    return res;
}

//读取一个文件，将按行填充至lines
void readFile(const string &path, vector<string> &lines){
    ifstream fin(utf2gbk(path));
    string str;
    while(getline(fin, str)){
        lines.push_back(str);
    }
    fin.close();
}

//将lines内容写入文件
void loadFile(const string &path, vector<string> &lines){
    ofstream fout(utf2gbk(path));
    for(auto &s: lines){
        fout << s << '\n';
    }
    fout.close();
}

//判断一个文件是否为字符文件
bool isTextFile(const string &path){
    ifstream fin(utf2gbk(path));
    char c;
    int w = 0, cnt = 0;
    while(fin >> c){
        cnt++;
        if(c < 7 || (13 < c && c < 32)) return false;
        else if(c == 9 || c == 10 || c == 13 || 32 <= c) w++;
    }
    fin.close();
    if(cnt == 0) return true;
    return w > 0;
}

void Hint(const string &info, QWidget *parent){
    QMessageBox::information(parent, "提示", info.c_str(), QMessageBox::Ok);
}

void Warning(const string &info, QWidget *parent){
    QMessageBox::warning(parent, "提示", info.c_str(), QMessageBox::Ok);
}

void Error(const string &info, QWidget *parent){
    QMessageBox::critical(parent, "提示", info.c_str(), QMessageBox::Ok);
}

//把名字混进哈希值
void mergeHash(string &hs, const string &name){
    int milen = min(hs.size(), name.size());
    for(int i=0;i<milen;i++){
        hs[i] = abs(hs[i] * name[i]) % 26 + 'a';
    }
}

//获取一个文件的哈希值（ID）（仅内容+名称，路径无关），末端加入标记位（'f'或't'标记这是一个文件id还是文件夹id）
string getHash(const string &path, const string &name, const char tag){
    //空文件求md5会报错，特判
    string res;
    if(isempty(path)) res = "\n" + EMPTY_HASH + "\n";
    else doCmd("certutil -hashfile \"" + path + "\" MD5", res);
    string hs;
    int _n = 0;
    for(int i=0;i<(int)res.size() && _n < 2;i++){
        if(res[i] == '\n') _n++;
        else if(_n == 1) hs += res[i];
    }
    mergeHash(hs, name);
    return hs + tag;
}

int str2int(const string &str){
    int res = 0;
    for(char c: str){
        res = res * 10 + c - '0';
    }
    return res;
}
string int2str(int x){
    string res;
    while(x > 0){
        res += char('0' + x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
QString Str2Q(const string &str){
    return QString::fromStdString(str);
}
string Q2Str(const QString &qstr){
    return qstr.toStdString();
}
string gbk2utf(const string & gbkStr) {
    string outUtf8;
    int n = MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, nullptr, 0);
    auto *str1 = new WCHAR[n];
    MultiByteToWideChar(CP_ACP, 0, gbkStr.c_str(), -1, str1, n);
    n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, nullptr, 0, nullptr, nullptr);
    char *str2 = new char[n];
    WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, nullptr, nullptr);
    outUtf8 = str2;
    delete[]str1;
    str1 = nullptr;
    delete[]str2;
    str2 = nullptr;
    return outUtf8;
}

string utf2gbk(const string &utf8Str) {
    string outGBK;
    int n = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, nullptr, 0);
    auto *str1 = new WCHAR[n];
    MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, str1, n);
    n = WideCharToMultiByte(CP_ACP, 0, str1, -1, nullptr, 0, nullptr, nullptr);
    char *str2 = new char[n];
    WideCharToMultiByte(CP_ACP, 0, str1, -1, str2, n, nullptr, nullptr);
    outGBK = str2;
    delete[] str1;
    str1 = nullptr;
    delete[] str2;
    str2 = nullptr;
    return outGBK;
}
