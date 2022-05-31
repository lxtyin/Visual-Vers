
#ifndef BRANCH_H
#define BRANCH_H

#include "Node.h"
#include <map>

//分支 即为CommitNode指针
class Branch {
public:
    CommitNode *position; //指向的CommitNode
    string name, id;      //快捷获取指向的CommitNode的name和id

    Branch(string _name, CommitNode *_position): name(move(_name)), position(_position){
        if(position != nullptr) id = position->id;
    }
    void moveTo(CommitNode *_pos); //切换指向的目标
};

extern map<string, Branch*> branch;  //name索引
extern Branch* currentBranch;        //当前分支

#endif //BRANCH_H
