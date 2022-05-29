
#include "Node.h"
#include "command.h"
#include "CommitNodeButton.h"
#include <fstream>

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

CommitNode::CommitNode(string _comment, string _id, CommitNode *fa1, CommitNode *fa2):
comment(move(_comment)), TreeNode(move(_id), ""), lastCommitNode{fa1, fa2}, myButton(new CommitNodeButton(this))
{
    if(fa1 == nullptr) dep = 1;
    else if(fa2 == nullptr) dep = fa1->dep + 1;
    else{
        if(fa1->dep < fa2->dep) swap(fa1, fa2);//令fa[0] dep// 更大
        dep = fa1->dep + 1;
    }

    if(fa1 != nullptr) fa1->nextCommit.push_back(this);
    if(fa2 != nullptr) fa2->nextCommit.push_back(this);
}

CommitNode* CommitNode::rootCommit = nullptr;
CommitNode::CommitNode(string _comment, TreeNode *_tnode, CommitNode *fa1, CommitNode *fa2):
comment(move(_comment)), TreeNode(*_tnode), lastCommitNode{fa1, fa2}, myButton(new CommitNodeButton(this))
{
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

