// 存放一些供用户直接使用的方法

#include "operator.h"
using namespace std;


//读取data下所有id，加入nodesPool，但只加入空指针（仅表示存在），需要时再加载完整内容
void readAllNodes(){
    nodePool.clear();
    for(string &str: fileList(DATA_PATH, false)){
        nodePool[str] = nullptr;
    }
}

//递归读取一个节点的子树，补全TreeNode和FileNode中的信息
void readSubNode(TreeNode *p, const string &path){
    vector<string> lines;
    readFile(DATA_PATH_ + p->id + "\\" + p->name + ".tree", lines);

    for(int i=0;i<lines.size();i+=2){
        string &vnm = lines[i], &vid = lines[i+1];
        if(nodePool[vid] != nullptr){
            p->appendSon(nodePool[vid]);
            continue;
        }
        if(vid.back() == 'f'){
            FileNode *node = new FileNode(vid, vnm);
            nodePool[vid] = node;
            p->appendSon(node);
        }else{
            TreeNode *node = new TreeNode(vid, vnm);
            nodePool[vid] = node;
            readSubNode(node, path+"\\"+vnm);
            p->appendSon(node);
        }
    }
}

//读取已经建立的CommitNode的一整棵子树
void readCommit(CommitNode *p){
    readSubNode(p, ROOT_PATH);
}

//读取commits目录下所有内容，建立所有commitNode节点之间的完整信息（不包括子树的完整信息）
void readAllCommits(){
    for(string &str: fileList(COMMIT_PATH, false)){
        //先全部建立对象
        nodePool[str] = new CommitNode("", str, nullptr, nullptr);
    }
    CommitNode::rootCommit = dynamic_cast<CommitNode*>(nodePool[ROOT_ID]);

    for(string &str: fileList(COMMIT_PATH, false)){
        auto *it = dynamic_cast<CommitNode*>(nodePool[str]);

        readCommit(it);//暂且

        vector<string> lines;
        readFile(COMMIT_PATH_+str, lines);
        while(lines.size() < 6) lines.push_back("");
        it->comment = lines[0];
        it->avatar = lines[1];
        it->time = lines[2];
        it->dep = str2int(lines[3]);
        string faid1 = lines[4], faid2 = lines[5];
        auto *f1 = nodePool[faid1], *f2 = nodePool[faid2];
        if(f1 != nullptr){
            it->lastCommitNode[0] = dynamic_cast<CommitNode*>(f1);
            dynamic_cast<CommitNode*>(f1)->nextCommit.push_back(it);
        }
        if(f2 != nullptr){
            it->lastCommitNode[1] = dynamic_cast<CommitNode*>(f2);
            dynamic_cast<CommitNode*>(f2)->nextCommit.push_back(it);
        }
    }
}

//读取branch，需先readAllCommits
void readBranch(){
    branch.clear();
    bool tag = false;
    vector<string> lines;
    readFile(BRANCH_FILE_PATH, lines);
    for(int i=0;i<lines.size();i+=2){
        string nm = lines[i], id = lines[i+1];
        branch[nm] = new Branch(nm, dynamic_cast<CommitNode*>(nodePool[id]));
        if(!tag) currentBranch = branch[nm], tag = true;
    }
}

//写入branch文件
void loadBranch(){
    vector<string> lines;
    lines.push_back(currentBranch->name);
    lines.push_back(currentBranch->id);

    for(auto &p: branch){
        if(p.second != currentBranch) {
            lines.push_back(p.second->name);
            lines.push_back(p.second->id);
        }
    }
    loadFile(BRANCH_FILE_PATH, lines);
}

//读取初始的用户头像
void readAvatar(string &tar){
    vector<string> lines;
    readFile("userAvatars.txt", lines);
    tar = lines[0];
}

//将当前用户头像保存，这两个函数仅对userAvatars文件修改
void loadAvatar(string &avt){
    vector<string> lines;
    lines.push_back(avt);
    loadFile("userAvatars.txt", lines);
}

//---------------------------------------------------------------------------------//

//提交一个文件/夹，创建需要的节点，返回Node，文件夹的哈希值即其.tree的哈希值
Node* commitFile(const string &path, const string &name){

    if(judgePath(path) == FILE_PATH){//判断是否为文件
        string hs = getHash(path, name, 'f');
        if(!nodePool.count(hs)){
            auto *it = new FileNode(hs, name);
            nodePool[hs] = it;
            CreateFolder(DATA_PATH_ + hs);
            CopyAFile(path, DATA_PATH_ + hs + "\\" + name);
//            it->save();
        }
        return nodePool[hs];
    }

    auto *it = new TreeNode("", name);
    vector<string> treeInfo;//文件夹的.tree内容
    for(string &str: fileList(path)){
        Node *vnode = commitFile(path + "\\" + str, str);
        treeInfo.push_back(str);
        treeInfo.push_back(vnode->id);
        it->appendSon(vnode);
    }
    string _tree = name + ".tree";
    loadFile(_tree, treeInfo);
    string hs = getHash(_tree, _tree, 't');
    DeleteAny(_tree);

    it->id = hs;
    if(!nodePool.count(hs)){
        nodePool[hs] = it;
        it->save();
//        cout << "updated: " << path << '\n';
    }else delete it;
    return nodePool[hs];
}

//根据两个commit获取其LCA
CommitNode* getCommitLca(CommitNode *a, CommitNode *b){
    while(a != b){
        if(a->dep > b->dep) a = a->lastCommitNode[0];
        else b = a->lastCommitNode[0];
    }
    return a;
}

//在工作区某处下载某个节点的内容
void loadNode(const string &path, Node *node){
    if(node->isTreeNode()){
        string subdir =  path + "\\" + node->name;
        CreateFolder(subdir);

        TreeNode *tree = dynamic_cast<TreeNode*>(node);
        for(Node *v: tree->son) loadNode(subdir, v);
    }else{
        CopyAFile(DATA_PATH_+node->id+"\\"+node->name, path+"\\"+node->name);
    }
}

//比较两个版本，将工作区从from（工作区对应TreeNode，需clean）切换至to
//path是工作区当前路径，后面两个是节点，执行时要求都是TreeNode，若有FileNode则直接处理掉
void compareAndSwitch(const string &path, TreeNode *from, TreeNode *to){

    map<string, Node*> fid;//from下，各个路径对应的子对象，用路径名索引，因为一个目录下不允许存在文件夹和某个文件同名
    for(Node *v: from->son){
        fid[v->name] = v;
    }

    for(Node *v: to->son){
        if(fid.count(v->name)){
            if(fid[v->name] != v){ //同路径但不指向同一子对象
                if(v->isTreeNode() && fid[v->name]->isTreeNode()){
                    //有相同子目录，但内容不同，递归合并
                    compareAndSwitch(path+"\\"+v->name, dynamic_cast<TreeNode*>(fid[v->name]),
                                     dynamic_cast<TreeNode*>(v));
                }else{
                    //说明存在同路径，但指向内容不同，其中一方为单个文件，直接整个替换
                    DeleteAny(path+"\\"+v->name);
                    loadNode(path, v);
                }
            }
            fid.erase(v->name);//处理过
        }else{
            //原无，目标有，直接下载
            loadNode(path, v);
        }
    }

    for(auto &p: fid){
        //原有，目标无，直接删除
        DeleteAny(path + "\\" + p.first);
    }
}

//三端合并，将tar内容合并到work处（工作区对应TreeNode，需clean），对冲突部分给出提示和标记
//返回是否正常（无冲突），执行时要求都是TreeNode，若有FileNode则直接处理掉，可为nullptr，表示某一版本此处为空
bool compareAndMerge(const string &path, TreeNode *lca, TreeNode *work, TreeNode *tar, vector<ModifyItem*> &diff, int option){
    map<string, Node*> X, Y, Z;
    set<string> ALL;

    if(lca != nullptr) for(Node *v: lca->son){
            X[v->name] = v;
            ALL.insert(v->name);
        }

    if(work != nullptr) for(Node *v: work->son){
            Y[v->name] = v;
            ALL.insert(v->name);
        }

    if(tar != nullptr) for(Node *v: tar->son){
            Z[v->name] = v;
            ALL.insert(v->name);
        }

    bool res = true;
    for(string dir: ALL){

        string vpath = path+"\\"+dir;
        //大力枚举所有情况
        Node *Xvt, *Yvt, *Zvt; //三个版本下 dir路径对应的子对象
        Xvt = X.count(dir) ? X[dir] : nullptr; //X:lca
        Yvt = Y.count(dir) ? Y[dir] : nullptr; //Y:work
        Zvt = Z.count(dir) ? Z[dir] : nullptr; //Z:tar

        //处理方式
        auto hint = [&](char type1, char type2, const string &info){
            //提示冲突，指出双方做的操作，将双方的修改量都插入diff (节点p1->节点p2)
            //也包括提示文字的插入
            ModifyItem *item1 = new ModifyItem(' ', vpath + "发生冲突");
            ModifyItem *item2 = new ModifyItem(' ', info);
            string pa1 = Xvt ? DATA_PATH_ + Xvt->id + "\\" + Xvt->name : "";
            string pa2 = Yvt ? DATA_PATH_ + Yvt->id + "\\" + Yvt->name : "";
            string pa3 = Zvt ? DATA_PATH_ + Zvt->id + "\\" + Zvt->name : "";
            ModifyItem *item3 = new ModifyItem(type2, vpath + "[当前]", pa1, pa2);
            ModifyItem *item4 = new ModifyItem(type1, vpath + "[目标]", pa1, pa3);
            diff.emplace_back(item1);
            diff.emplace_back(item2);
            diff.emplace_back(item3);
            diff.emplace_back(item4);
            item4->applyTar = vpath;
            item4->linkItem.push_back(item1);
            item4->linkItem.push_back(item2);
            item4->linkItem.push_back(item3);
        };
        auto copy = [&](){CopyAFile(DATA_PATH_+Zvt->id+"\\"+dir, vpath);};
        auto delt = [&](){DeleteAny(vpath);};
        auto replace = copy;
        auto pass = [](){;};

        if(Xvt == nullptr){
            if(Yvt == nullptr){
                if(Zvt == nullptr){
                    pass();
                }else{
                    copy();
                }
            }else{
                if(Zvt == nullptr){
                    pass();
                }else{
                    if(Yvt == Zvt) pass();
                    else{
                        //warn; 双方都新建，但内容不一致
                        if(Yvt->isTreeNode() && Zvt->isTreeNode()){
                            //同名目录，但内容有所不一致，且祖先不存在此目录，递归解决
                            res &= compareAndMerge(vpath, nullptr,
                                                   dynamic_cast<TreeNode*>(Yvt),
                                                   dynamic_cast<TreeNode*>(Zvt), diff, option);
                        }else{
                            //单个文件问题 直接解决
                            //warn: 各自创建了不同的内容
                            hint('+', '+', "双方建立了同名文件，但内容不同。");
                            res = false;
                        }
                    }
                }
            }
        }else{
            if(Yvt == nullptr){
                if(Zvt == nullptr){
                    pass();
                }else{
                    if(Zvt == Xvt) pass();
                    else{
                        //warn; 目标修改，自己删除
                        hint('*', '-', "[目标]修改了此文件，但[当前]删除了此文件。");
                        res = false;
                    }
                }
            }else{
                if(Zvt == nullptr){
                    if(Yvt == Xvt) delt();
                    else{
                        //warn; 自己修改，目标删除
                        hint('-', '*', "[当前]修改了此文件，但[目标]删除了此文件。");
                        res = false;
                    };
                }else{
                    if(Xvt == Zvt && Xvt == Yvt) pass();
                    else{
                        if(Yvt->isTreeNode() && Zvt->isTreeNode()){
                            //文件夹有所不一致，递归解决
                            res &= compareAndMerge(vpath,
                                                   dynamic_cast<TreeNode*>(Xvt),
                                                   dynamic_cast<TreeNode*>(Yvt),
                                                   dynamic_cast<TreeNode*>(Zvt), diff, option);
                        }else{
                            //单个文件问题 直接解决
                            if(Xvt == Yvt) replace();
                            else if(Xvt == Zvt) pass();
                            else if(Yvt == Zvt) pass();
                            else{
                                //warn; 单个文件的修改内容不一致
                                hint('*', '*', "双方作出了不同的修改。");
                                res = false;
                            }
                        }
                    }
                }
            }
        }
    }
    return res;
}

// 将当前工作区和某节点进行对比，返回节点到工作区的修改量（文件级），传至result，参数允许为空或不合法，表示纯新增或纯删除
void diffWithNode(TreeNode *from, const string &path, vector<ModifyItem*> &result){
    if(!from && judgePath(path) != FOLDER_PATH) return;

    auto add = [&](char type, const string &name, Node *p1 = nullptr, const string &p2 = ""){ //将修改量插入diff(节点p1->工作区path2)
        string pa1 = p1 ? DATA_PATH_ + p1->id + "\\" + p1->name : "";
        result.emplace_back(new ModifyItem(type, name, pa1, p2));
    };
    //判空文件夹
    if(!from && fileList(path).empty()){
        add('+', path + "[空文件夹]");
        return;
    }
    if(judgePath(path) != FOLDER_PATH && from->son.empty()){
        add('-', path + "[空文件夹]");
        return;
    }

    map<string, Node*> vid;//from下各个路径对应的子对象
    if(from != nullptr){
        for(Node *v: from->son) vid[v->name] = v;
    }

    for(string &str: fileList(path)){
        string vpath = path + "\\" + str;
        if(vid.count(str)){
            Node *v = vid[str];
            if(v->isFileNode() && judgePath(vpath) == FILE_PATH){
                //均为文件，返回 修改（*）
                if(v->id != getHash(vpath, str, 'f')) add('*', vpath, v, vpath);
            }else{
                //至少一方是文件夹，那么递归解决，不论另一方如何
                diffWithNode(dynamic_cast<TreeNode *>(v), vpath, result); //不合法自然nullptr
                if(v->isFileNode()) add('-', vpath, v, vpath);
                if(judgePath(vpath) == FILE_PATH) add('+', vpath, nullptr, vpath);
            }
            vid.erase(str);
        }else{
            // 新增
            if(judgePath(vpath) == FOLDER_PATH) diffWithNode(nullptr, vpath, result);
            else add('+', vpath, nullptr, vpath);
        }
    }
    for(auto &p: vid){
        // 删除
        string vpath = path+"\\"+p.second->name;
        if(p.second->isTreeNode()) diffWithNode(dynamic_cast<TreeNode*>(p.second), vpath, result);
        else add('-', vpath, p.second, "");
    }
}

// 对比两个文件，推测出从1到2的修改，填入result, 允许输入"" 表示1或2不存在，只一方增或减
int fd[2003][4003];
int ld[2003][4003];
bool getDiffBetween(const string &path1, const string &path2, vector<string> &result){

    int n1 = 0, n2 = 0;
    vector<string> s1, s2;
    vector<int> hs1, hs2;
    if(!path1.empty()){
        readFile(path1, s1);
        n1 = s1.size();
        hs1.resize(n1);
        for(int i=0;i<s1.size();i++){
            for(int c: s1[i]) hs1[i] = hs1[i] * 233 + c;
        }
    }
    if(!path2.empty()){
        readFile(path2, s2);
        n2 = s2.size();
        hs2.resize(n2);
        for(int i=0;i<s2.size();i++){
            for(int c: s2[i]) hs2[i] = hs2[i] * 233 + c;
        }
    }

    auto f = [&](int x, int y)->int&{ return fd[x][y+2000];};
    auto l = [&](int x, int y)->int&{ return ld[x][y+2000];};
    f(0, 0) = 0;
    while(f(0, 0) < min(n1, n2) && hs1[f(0, 0)] == hs2[f(0, 0)]){
        result.push_back("*  " + s1[f(0, 0)]);
        f(0, 0)++;
    }

    int ust = 0, ued = 0;
    for(int d=1;d<=n1+n2;d++){
        int st = max(-d, -n2); if((st+d) % 2 == 1) st++;
        int ed = min(d, n1); if((d-ed) % 2 == 1) ed--;
        for(int k=st;k<=ed;k+=2){
            f(d, k) = 0;
            if(k < ued && f(d-1, k+1) >= f(d, k)){
                f(d, k) = f(d-1, k+1);
                l(d, k) = k + 1;
            }
            if(k > ust && f(d-1, k-1)+1 >= f(d, k)){
                f(d, k) = f(d-1, k-1) + 1;
                l(d, k) = k - 1;
            }

            int x = f(d, k), y = x - k;
            while(x < n1 && y < n2 && hs1[x] == hs2[y]) x++, y++, f(d, k)++;
            if(x == n1 && y == n2){
                int pk[d+1];
                pk[d] = k;
                for(int i=d-1;i>=0;i--){
                    pk[i] = l(i+1, pk[i+1]);
                }
                for(int i=0;i<d;i++){
                    if(pk[i+1] < pk[i]){
                        x = f(i, pk[i]), y = x - pk[i];
                        result.push_back("+  " + s2[y]);
                        while(x < f(i+1, pk[i+1])){
                            result.push_back("*  " + s1[x]);
                            x++;
                        }
                    }else{
                        x = f(i, pk[i]), y = x - pk[i];
                        result.push_back("-  " + s1[x]);
                        x++;
                        while(x < f(i+1, pk[i+1])){
                            result.push_back("*  " + s1[x]);
                            x++;
                        }
                    }
                }

                return true;
            }
        }
        ust = st, ued = ed;
    }
    return true; //应该用不到
}

//---------------------------------------------------------------------------------//
//以下是面向用户的api，参数应当可读

bool isFileNode(const string &id){
    return nodePool.count(id) && (nodePool[id]->isFileNode());
}
bool isTreeNode(const string &id){
    return nodePool.count(id) && (nodePool[id]->isTreeNode());
}
bool isCommitNode(const string &id){
    return nodePool.count(id) && (nodePool[id]->isCommitNode());
}

//清空 仅对data,node,branch等清空，不动工作区
void init(){

    DeleteAny(REPO_PATH);

    CreateFolder(REPO_PATH);
    CreateFolder(DATA_PATH);
    CreateFolder(COMMIT_PATH);

    //初始化最开始的CommitNode
    CommitNode("init", ROOT_ID, nullptr).save();

    //创建一个master分支
    vector<string> s = {"master", ROOT_ID};
    loadFile(BRANCH_FILE_PATH, s);
}

//提交当前目录下所有内容
bool commitAllWork(const string &comment){
    TreeNode *root = dynamic_cast<TreeNode*>(commitFile(ROOT_PATH, ""));

    if(root->id == currentBranch->id){
        Hint("没有内容需要提交！");
        return false;
    }else if(root->isCommitNode()){ //已经是提交节点 说明与先前的重复
        Hint("历史存在完全相同版本，即将转移");
        currentBranch->moveTo(dynamic_cast<CommitNode*>(root));
        loadBranch();
        return false;
    }else{
        CommitNode *commit = new CommitNode(comment, root, currentBranch->position);
        delete root;
        nodePool[commit->id] = commit;
        currentBranch->moveTo(commit);
        commit->save();
        loadBranch();
        return true;
    }
}

//强制将工作区切换到某次提交处（抛弃现有内容）
bool forceLoad(CommitNode *target){
    for(string &str: fileList(ROOT_PATH)){
        DeleteAny(ROOT_PATH+"\\"+str);
    }
    loadNode(ROOT_PATH, target);//从这个节点重新加载
    return true;
}
bool forceLoad(const string &id){
    if(!isCommitNode(id)){
        Error("No such commit.");
        return false;
    }
    return forceLoad(dynamic_cast<CommitNode*>(nodePool[id]));
}

//撤销未提交的更新
void restore(){
    forceLoad(currentBranch->position);//暂时先这样
}

//将当前工作区（带分支）切换到某次提交处
bool switchToNode(CommitNode *target){
    compareAndSwitch(ROOT_PATH, currentBranch->position, target);//...
    currentBranch->moveTo(target);
    loadBranch();
    return true;
}
bool switchToNode(const string &id){
    if(!isCommitNode(id)){
        Error("No such commit.");
        return false;
    }
    return switchToNode(dynamic_cast<CommitNode*>(nodePool[id]));
}

//将当前工作区切换到某个branch处，当前分支也要因此切换
bool switchToBranch(const string &brname){
    if(!branch.count(brname)){
        Error("No such branch.");
        return false;
    }
    compareAndSwitch(ROOT_PATH, currentBranch->position, branch[brname]->position);//..
    currentBranch = branch[brname];
    loadBranch();
//    cout << "Current branch has become " << brname << '\n';
    return true;
}

//拉取，合并，选项-0：自由合并，冲突提示； 1：冲突时优先当前； 2：冲突时优先目标
bool pullFromCommit(CommitNode *target, const string &comment, vector<ModifyItem*> &diff, int option){
    auto *lca = getCommitLca(currentBranch->position, target);
    bool res = compareAndMerge(ROOT_PATH, lca, currentBranch->position, target, diff, option);
    if(res){
        //没有冲突
        TreeNode *root = dynamic_cast<TreeNode*>(commitFile(ROOT_PATH, ""));
        if(root->isCommitNode()){ //和历史版本重复
            Hint("历史存在完全相同版本，即将转移");
            currentBranch->moveTo(dynamic_cast<CommitNode*>(root));
            loadBranch();
            return true;
        }else{
            //成功合并 产生两个父亲的新节点
            CommitNode *commit = new CommitNode(comment, root, currentBranch->position, target);
            delete root;
            nodePool[commit->id] = commit;
            currentBranch->moveTo(commit);
            commit->save();
            loadBranch();
            return true;
        }
    }else{
        restore(); //合并失败，撤销更改，重新选择
        return false;
    }
}
bool pullFromBranch(const string &brname, const string &comment, vector<ModifyItem*> &diff, int option){
    if(!branch.count(brname)){
        Error("No such branch.");
        return false;
    }
    return pullFromCommit(branch[brname]->position, comment, diff, option);
}

//在当前节点下创建新分支
bool createBranch(const string &brname){
    if(branch.count(brname)){
        Error("Branch " + brname + " already exist.");
        return false;
    }
    branch[brname] = new Branch(brname, currentBranch->position);
    loadBranch();
    return true;
}
