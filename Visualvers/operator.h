
#ifndef OPERATOR_H
#define OPERATOR_H

#include <bits/stdc++.h>
#include "command.h"
#include "Node.h"
#include "Branch.h"
#include "ModifyItem.h"

void readAllNodes();                            //读取项目仓库中所有节点（硬盘到内存）
void readSubNode(TreeNode *p);                  //读取一个TreeNode下所有子节点
void readCommit(CommitNode *p);                 //读取一个版本的所有子节点
void readAllCommits();                          //读取所有版本

void readBranch();                              //读写分支
void loadBranch();

void readAvatar(string &s);                     //读写头像
void loadAvatar(string &s);

//---------------------------------------------------------------------------------//
//递归处理部分

Node* commitFile(const string &path, const string &name);                    //提交工作区路径下的文件，当前执行到path
void loadNode(const string &path, Node *node);                               //加载node及其子节点到工作区path处
void compareAndSwitch(const string &path, TreeNode *from, TreeNode *to);     //将工作区从from切换到to，当前处于path
bool compareAndMerge(const string &path, TreeNode *lca, TreeNode *work,      //合并work与tar，其公共祖先为lca，冲突结果写入diff，当前处于path
                     TreeNode *tar, vector<ModifyItem*> &diff, int option = 0);

void diffWithNode(TreeNode *from, const string &path, vector<ModifyItem*> &result);     //对比，将from节点到工作区path的修改内容写入result

//---------------------------------------------------------------------------------//

bool isFileNode(const string &id);
bool isTreeNode(const string &id);
bool isCommitNode(const string &id);

CommitNode* getCommitLca(CommitNode *a, CommitNode *b);                 //获取两个版本的Lca

void init();
bool commitAllWork(const string &comment);
bool forceLoad(CommitNode *target);
bool forceLoad(const string &id);
void restore();

bool switchToNode(CommitNode *target);
bool switchToNode(const string &id);
bool switchToBranch(const string &brname);
bool getDiffBetween(const string &path1, const string &path2, vector<string> &result);  //对比两个文件，将它们的具体修改内容（具体道行）写入result

bool pullFromCommit(CommitNode *target, const string &comment, vector<ModifyItem*> &diff, int option = 0);
bool pullFromBranch(const string &brname, const string &comment, vector<ModifyItem*> &diff, int option = 0);

bool createBranch(const string &brname);


#endif //OPERATOR_H
