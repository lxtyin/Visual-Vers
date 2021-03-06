/*
 * 此类为各种节点，文件信息的内部存储类
 * 其中CommitNode表示一个提交记录，也为一个版本的文件根节点。
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
using namespace std;

//所有节点的抽象类
class Node {
public:
    string id, name;

    Node(string _id, string _name):
        id(move(_id)), name(move(_name)){}
    virtual void save() = 0; //保存/更新节点到磁盘
    virtual int getType() = 0; //获取类型

    bool isTreeNode();
    bool isFileNode();
    bool isCommitNode();
};

//树节点，对应文件夹
class TreeNode: public Node {
public:
    vector<Node*> son; //文件树下的子节点

    TreeNode(string _id, string _name):
        Node(move(_id), move(_name)){}
    void appendSon(Node *node);

    void save() override;
    int getType() override;
};

//文件节点，对应单个文件
class FileNode: public Node {
public:
    FileNode(string _id, string _name):
        Node(move(_id), move(_name)){}
    void save() override; //避免成为抽象类，实际FileNode的存放不在此处进行（因为我设计一个FileNode不关注其所在路径，仅关注内容）
    int getType() override; //type: 1 file, 2 Tree, 4 commit
};


class CommitNodeButton; //前置声明

//提交记录节点，同时作为一次提交的文件树根节点
class CommitNode: public TreeNode {
public:
    static CommitNode *rootCommit; //记录所有提交记录的根节点（最早的空版本，在readAllCommit时指定）

    CommitNodeButton *myButton; //每个提交节点和一个button关联，创建CommitNode时自动创建button

    CommitNode *lastCommitNode[2]; //版本树上的父节点
    vector<CommitNode*> nextCommit; //版本树上的子节点
    string avatar;  //头像（用户）
    string time;    //提交时间
    string comment; //评论
    int dep;        //深度

    CommitNode(string _comment, string _id, CommitNode *fa1, CommitNode *fa2 = nullptr);//可能有两个父提交
    CommitNode(string _comment, TreeNode *_tnode, CommitNode *fa1, CommitNode *fa2 = nullptr); //直接由Treenode转换而来
    ~CommitNode();
    void save() override;
    int getType() override;
};

extern map<string, Node*> nodePool; //id索引

#endif //NODE_H
