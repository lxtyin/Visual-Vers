
#ifndef BRANCH_H
#define BRANCH_H

#include "Node.h"
#include <map>

//分支 即为CommitNode指针
class Branch {
public:
    CommitNode *position;
    string name, id;

    Branch(string _name, CommitNode *_position): name(move(_name)), position(_position){
        if(position != nullptr) id = position->id;
    }
    void moveTo(CommitNode *_pos);
};

extern map<string, Branch*> branch;  //name索引
extern Branch* currentBranch;

#endif //BRANCH_H
