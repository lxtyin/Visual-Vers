
// 存放一些供用户直接使用的方法
#ifndef OPERATOR_H
#define OPERATOR_H

#include <bits/stdc++.h>
#include "command.h"
#include "Node.h"
#include "Branch.h"
#include "ModifyItem.h"

void readAllNodes();
void readSubNode(TreeNode *p, const string &path);
void readCommit(CommitNode *p);
void readAllCommits();

void readBranch();
void loadBranch();

void readAvatar(string &s);
void loadAvatar(string &s);

//---------------------------------------------------------------------------------//

Node* commitFile(const string &path, const string &name);
CommitNode* getCommitLca(CommitNode *a, CommitNode *b);
void loadNode(const string &path, Node *node);
void compareAndSwitch(const string &path, TreeNode *from, TreeNode *to);
bool compareAndMerge(const string &path, TreeNode *lca, TreeNode *work, TreeNode *tar, vector<ModifyItem*> &diff, int option = 0);

void diffWithNode(TreeNode *from, const string &path, vector<ModifyItem*> &result);
bool getDiffBetween(const string &path1, const string &path2, vector<string> &result);

//---------------------------------------------------------------------------------//

bool isFileNode(const string &id);
bool isTreeNode(const string &id);
bool isCommitNode(const string &id);

void init();
bool commitAllWork(const string &comment);
bool forceLoad(CommitNode *target);
bool forceLoad(const string &id);
void restore();

bool switchToNode(CommitNode *target);
bool switchToNode(const string &id);
bool switchToBranch(const string &brname);

bool pullFromCommit(CommitNode *target, const string &comment, vector<ModifyItem*> &diff, int option = 0);
bool pullFromBranch(const string &brname, const string &comment, vector<ModifyItem*> &diff, int option = 0);

bool createBranch(const string &brname);


#endif //OPERATOR_H
