
#include "Node.h"
#include "Branch.h"

void Branch::moveTo(CommitNode *_pos) {
    position = _pos;
    id = _pos->id;
}

map<string, Branch*> branch;//name索引
Branch* currentBranch = nullptr;

