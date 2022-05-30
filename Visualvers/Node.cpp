
#include "Node.h"
#include "command.h"
#include "CommitNodeButton.h"
#include <fstream>
#include <QDateTime>

using namespace std;


void TreeNode::appendSon(Node *node) {
    son.push_back(node);
}

void TreeNode::save() {
    CreateFolder(DATA_PATH_ + id);
    vector<string> lines;
    for(auto v: son){
        lines.push_back(v->name);
        lines.push_back(v->id);
    }
    loadFile(DATA_PATH_ + id + "\\" + name + ".tree", lines);
}

void FileNode::save() {} //摆设

//创建时默认使用当前avatar，需要更改另外操作
//time也默认使用当前时间，需要更改另外操作（一般读入时需要更改
CommitNode::CommitNode(string _comment, string _id, CommitNode *fa1, CommitNode *fa2):
  comment(move(_comment)), TreeNode(move(_id), ""),
  lastCommitNode{fa1, fa2}, myButton(new CommitNodeButton(this))
{
    avatar = MainWidget->curAvatar;
    time = Q2Str(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm"));
    if(fa1 == nullptr) dep = 1;
    else if(fa2 == nullptr) dep = fa1->dep + 1;
    else{
        if(fa1->dep < fa2->dep) swap(fa1, fa2);//令fa[0] dep 更大，绘图时按照最长路，故取较大父亲的深度
        dep = fa1->dep + 1;
    }

    if(fa1 != nullptr) fa1->nextCommit.push_back(this);
    if(fa2 != nullptr) fa2->nextCommit.push_back(this);
}

CommitNode* CommitNode::rootCommit = nullptr;
CommitNode::CommitNode(string _comment, TreeNode *_tnode, CommitNode *fa1, CommitNode *fa2):
  comment(move(_comment)), TreeNode(*_tnode),
  lastCommitNode{fa1, fa2}, myButton(new CommitNodeButton(this))
{
    avatar = MainWidget->curAvatar;
    time = Q2Str(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm"));
    if(fa1 == nullptr) dep = 1;
    else if(fa2 == nullptr) dep = fa1->dep + 1;
    else{
        if(fa1->dep < fa2->dep) swap(fa1, fa2);
        dep = fa1->dep + 1;
    }

    if(fa1 != nullptr) fa1->nextCommit.push_back(this);
    if(fa2 != nullptr) fa2->nextCommit.push_back(this);
}
CommitNode::~CommitNode() {
    delete myButton;
}

void CommitNode::save() {
    CreateFolder(DATA_PATH_ + id);
    TreeNode::save();

    vector<string> lines;
    lines.push_back(comment);
    lines.push_back(avatar);
    lines.push_back(time);
    lines.push_back(int2str(dep));

    if(lastCommitNode[0] != nullptr) lines.push_back(lastCommitNode[0]->id);
    if(lastCommitNode[1] != nullptr) lines.push_back(lastCommitNode[1]->id);
    loadFile(COMMIT_PATH_ + id, lines);
}

int FileNode::getType() { return 1; }
int TreeNode::getType() { return 2; }
int CommitNode::getType() { return 2|4; }

bool Node::isFileNode() { return getType() & 1;}
bool Node::isTreeNode() { return getType() & 2;}
bool Node::isCommitNode() { return getType() & 4;}


map<string, Node*> nodePool; //id索引

