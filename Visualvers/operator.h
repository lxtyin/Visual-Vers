
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
//面向用户部分

bool isFileNode(const string &id);                                     //判断一个id对应的节点类型
bool isTreeNode(const string &id);
bool isCommitNode(const string &id);

CommitNode* getCommitLca(CommitNode *a, CommitNode *b);                 //获取两个版本的Lca

void init();                                                            //初始化项目仓库
bool commitAllWork(const string &comment);                              //提交工作区所有内容
bool forceLoad(CommitNode *target);                                     //强制转换到节点
bool forceLoad(const string &id);
void restore();                                                         //撤销工作区内容

bool switchToNode(CommitNode *target);                                  //切换工作区到节点
bool switchToNode(const string &id);
bool switchToBranch(const string &brname);

//对比两个文件，将它们的具体修改内容（具体道行）写入result
bool getDiffBetween(const string &path1, const string &path2, vector<string> &result);
//从某节点拉取合并
bool pullFromCommit(CommitNode *target, const string &comment, vector<ModifyItem*> &diff, int option = 0);
bool pullFromBranch(const string &brname, const string &comment, vector<ModifyItem*> &diff, int option = 0);
//创建分支
bool createBranch(const string &brname);


#endif //OPERATOR_H
