# Visual-Vers



#### 简介

Visual-Vers是一款仿照git制作的版本控制软件，且在git的基础上加上了可视化的用户操作界面，应用意义在于补全git在可视化方面的不足。

它比git更简单，更容易上手，更能用图像界面形象展示版本关系，能帮助新人更好的入门版本控制，让版本控制工具大众化。

目前百度上能找到的大多git可视化工具，都和git desktop差不多，只是显示了节点信息或是做了差异对比，而没有显示各个版本节点、分支之间的继承推进关系。而本项目则完成了这一任务。



#### 功能

本项目实现了git的大部分基础功能，包括：

- 版本提交、记录
- 版本回滚
- 撤销变更
- 分支操作
- 版本合并
- 版本差异对比
- 文件变更对比
- 用户、时间记录

另外实现了git不具备的图形界面：

- 版本继承关系图显示
- 提交用户、提交时间、评论记录显示

因时间和技术原因，git远程仓库服务端没能完成，但本项目**具备实现分布式的可拓展性**，将在接下来说明。





#### 原理简介

##### 文件系统

版本控制实际上一个文件系统，其中总的来看有两个树形结构。每个版本都是一棵文件树，文件树的根节点又构成了一棵版本继承树（因为版本合并操作的存在，版本继承树准确来说是一个DAG（有向无环图））

各个版本的文件树之间可以共享节点来节省空间。

##### 项目变更发现

这里指在整个工作区中，找到所有用户修改过的文件（相对于上个版本）并罗列呈现，和下面的“文件变更发现”有所区别。

文件树中的每个节点都有一个哈希值，利用此哈希值可以快速判断两个节点是否相同。

git也是依赖哈希判断文件是否相同的，但它只关注文件内容，将文件名放置在TreeNode（即保存它的文件夹）中，而本项目则将文件内容和文件名称放在一起去获取哈希值，这样做的优势在于：git判断两个节点是否相同必须依赖上下文，而本项目具体存储的节点完全是“路径无关”的，可以做到散列存储。

##### 文件变更发现

这里指的是对某个具体的文件，找出其修改内容（具体增删了哪些字符）

对应git当中的git diff功能，它的抽象问题是求两个字符串之间的最小编辑次数，将删除和插入视作一次编辑，修改视作删除+插入。

求变更方案的第一原则是编辑次数最小，它可以通过求最长公共子序列完成，复杂度为 $O(n^2)$，更优的解法是myers算法，同样为动态规划解法，复杂度为$O(nd)$，d为修改次数。本项目使用myers完成。

参考资料：https://zhuanlan.zhihu.com/p/67024353

##### 有向图绘制

本项目的图形界面使用Qt制作，有向图绘制尝试了dagre布局算法

https://www.yuque.com/antv/g6-blog/xxp5nl

但我还没有完全理解这个算法，项目中目前使用的一个比较简陋的dp：

从根节点开始dfs布局，从底向上依次排版，每个点依据各个子节点需要宽度来布局，然后返回当前点所需要的宽度。



#### 逻辑结构

##### Node

Node类为所有节点的抽象类。

FileNode类继承自Node，表示一个**文件节点**，对应一个具体文件。

TreeNode类继承自Node，表示一个**树节点**，对应一个文件夹，其中包含一个指向所有子节点（Node*，可以是文件节点或另一个树节点）的邻接表`son`。

CommitNode类继承自TreeNode，表示一个**提交节点**，或者说**版本节点**，其中除了继承自TreeNode的子目录邻接表外，还有指向下个版本的邻接表`nextCommit`，以及指向上个版本的指针 `lastCommitNode`。各种版本节点的信息（如提交者，评论，提交时间等）都保存在CommitNode中。

###### ID

每个节点都具有一个ID，FileNode的ID等于它的MD5哈希值和文件名混合，TreeNode的ID是其所有子节点哈希值以及本文件夹名的混合，CommitNode的ID同TreeNode的ID。

项目仓库中根据此ID存储各个节点（具体见物理结构），项目启动时，所有节点都被读到一个map中，通过ID索引。

Node结构是本项目最核心的逻辑结构，关于提交，回滚等具体实现见下文。

##### Branch

分支类主要包含了一个CommitNode的指针，其实仅仅只是一个版本节点的标记，因为我们图形化界面的特点，其实不需要特别的分支标记就能完成分支操作，或者说，在我们的逻辑结构下，其实每个节点都是一个分支。

代码中完成了各种分支的增删改查操作，但应用到实际界面上的其实只有一个“当前节点”分支，指向用户当前所处的版本。

##### CommitNodeButton

版本节点按钮，继承自QPushButton，作为Node树到用户界面的衔接。

每个CommitNode在构造时都会同时构造一个CommitNodeButton，CommitNodeButton也包含其对应的CommitNode指针，它们是一一对应的关系。

CommitNodeButton负责显示在用户界面上，在用户点击时将版本节点具体的信息以及操作接口显示给用户。

##### ModifyItem

修改记录项，继承自QListWidgetItem，在**项目变更发现**时将每一条文件的变更都记录为一条ModifyItem，能够显示在界面的列表中，同时包含修改记录对应的具体文件路径，用户双击时，进行相应的**文件变更发现**并显示。





#### 物理结构

在要管理的项目根目录下会有一个.vvs文件夹，作为版本库（对应.git）

其目录结构如下：

- .vvs

  - commits文件夹

    - 许多无拓展名的文件，每个文件存放一个CommitNode（提交记录节点），其文件名为ID，其中的内容格式为：
      - 第一行：评论
      - 第二行：提交者
      - 第三行：提交时间
      - 第四行：深度
      - 第五、六行：父版本（可能存在两个父版本）

  - data文件夹

    - 许多文件夹，每个文件夹存放一个Node（包括CommitNode），其文件夹名为ID，其中的内容：

      - 若为FileNode，则内部直接存储这个文件的拷贝。

      - 若为TreeNode（CommitNode），则内容为一个.tree后缀的文件，其名称为文件夹名（若为CommitNode则为空）
        - 其中包括若干行，每两行表示一个子节点，第一行为子节点的名称，第二行为子节点的ID。

  - .branch文件，其中有若干行，每两行为一个分支（实际上只用到一个分支），第一行为分支名，第二行为分支指向的CommitNode的ID

上述是被管理的项目目录下的文件，在此软件的运行目录下还有几个资源文件，主要存放用户偏好等等：

- avatars文件夹，存放使用过的各个头像（在本项目中头像和用户名具有相同意义，可以辨别用户）
- userAvatars.txt，存放用户当前使用的头像
- recent.txt，按顺序记录用户打开的仓库路径，后续可以直接打开“最近项目“



#### 具体实现

（没写完 不想写了555.....)



有command.cpp和operator.cpp两个工具脚本，其中包含了本项目诸多操作的Api，用于简化代码。

command负责文件操作，包含了文件的增删查改移，路径判断，哈希值获取等函数，还包括大部分全局常量的定义。

```C++
//command.h
extern string ROOT_PATH;									//各种常量定义
#define REPO_PATH (ROOT_PATH + "\\.vvs")
#define DATA_PATH (REPO_PATH + "\\data")
#define DATA_PATH_ (REPO_PATH + "\\data\\")
#define COMMIT_PATH (REPO_PATH + "\\commits")
#define COMMIT_PATH_ (REPO_PATH + "\\commits\\")
#define BRANCH_FILE_PATH (REPO_PATH + "\\.branch")

#define DEFAULT_AVATAR ":/images/img/default.png"

const string EMPTY_HASH = "00000000000000000000000000000000";
const string ROOT_ID = "yemmm000000000000000000000000000t";

bool doCmd(const string &cmd, string &res);				    //各种命令行Api，文件操作
bool doCmd(const string &cmd);
bool CopyAFile(const string &a, const string &b);
void DeleteAny(const string &a);
void CreateFolder(const string &a);

const int FOLDER_PATH = 1;									//路径判断和路径宏
const int FILE_PATH = 2;
const int EMPTY_PATH = 0;
bool isempty(const string &path);
int judgePath(const string &path);

vector<string> fileList(const string &path, bool filter = true); //更高级的文件操作
void readFile(const string &path, vector<string> &lines);
void loadFile(const string &path, vector<string> &lines);
bool isTextFile(const string &path);

void Hint(const string &info, QWidget *parent = MainWidget);   //提示Api
void Warning(const string &info, QWidget *parent = MainWidget);
void Error(const string &info, QWidget *parent = MainWidget);

void mergeHash(string &hs, const string &name); 				//哈希值获取
string getHash(const string &path, const string &name, const char tag);

int str2int(const string &str);									//常用类型转换
string int2str(int x);
QString Str2Q(const string &str);
string Q2Str(const QString &qstr);
string gbk2utf(const string &gbkStr);							//为了windows文件操作
string utf2gbk(const string &utf8Str);
// 中文处理方式：
// 整个项目采用utf-8
// 仅面向windows，文件存取操作时转换到gbk
// 对所有文件操作封装
// 其中GBK和utf-8的转换代码来源网络
```

operator负责更具体的操作Api，如：

```c++
//operator.h
void readAllNodes();								 //各种读取，从磁盘到内存
void readSubNode(TreeNode *p, const string &path);
void readCommit(CommitNode *p);
void readAllCommits();

void readBranch();
void loadBranch();

void readAvatar(string &s);
void loadAvatar(string &s);
//-------------------------------------------------------------------------// 下面是主要的处理函数，但不是面向用户的，大多是递归调用

//提交一个工作区路径（可能是文件或者目录），返回产生的Node
Node* commitFile(const string &path, const string &name);
//获取两个CommitNode的最近公共祖先
CommitNode* getCommitLca(CommitNode *a, CommitNode *b);
//在工作区某处加载某个节点的内容（递归调用
void loadNode(const string &path, Node *node);
//对比工作区某处和某个节点，将工作区切换过去
void compareAndSwitch(const string &path, TreeNode *from, TreeNode *to);
//对比工作区某处和某个节点，将对方拉过来，返回是否冲突，将冲突内容写入diff（后面的option可以选冲突对应方式 返回冲突/应用目标/应用当前）
bool compareAndMerge(const string &path, TreeNode *lca, TreeNode *work, TreeNode *tar, vector<ModifyItem*> &diff, int option = 0);
//项目变更发现，差异写入diff
void diffWithNode(TreeNode *from, const string &path, vector<ModifyItem*> &result);
//文件变更发现，写入result
bool getDiffBetween(const string &path1, const string &path2, vector<string> &result);

//--------------------------------------------------------------------------// 下面是面向用户的Api
//判断一个ID对应的Node类型
bool isFileNode(const string &id);
bool isTreeNode(const string &id);
bool isCommitNode(const string &id);

void init();									//初始化版本库
bool commitAllWork(const string &comment);      //提交工作区所有内容
bool forceLoad(CommitNode *target);				//强制切换到某个节点（丢失工作区未提交的内容）
bool forceLoad(const string &id);
void restore();									//放弃工作区所有未提交的内容

bool switchToNode(CommitNode *target);			//切换到某个节点
bool switchToNode(const string &id);			
bool switchToBranch(const string &brname);		

bool pullFromCommit(CommitNode *target, const string &comment, vector<ModifyItem*> &diff, int option = 0);	//拉取合并某个节点
bool pullFromBranch(const string &brname, const string &comment, vector<ModifyItem*> &diff, int option = 0);

bool createBranch(const string &brname);		//创建分支（没用）
```

下面给出各种操作的数据流和算法描述：



##### 提交

数据流：按钮点击 - Widget/输入评论 - operator/commitAllWork - commitFile - 检查版本重复 - Widget/刷新绘图区，diff列表

主体操作在 commitFile这一部分：

```c++
Node* commitFile(const string &path, const string &name);
```

它是一个递归函数，从工作区根目录开始扫描：

- 扫到叶子节点（单个文件）
  - 计算其哈希值，若在nodePool（保存所有Node的map，ID作为索引）中没有同样的哈希值：创建该文件的一个新版本，文件复制到.vvs仓库中，返回新建的FileNode
  - 否则返回nodePool中已有的Node。

- 扫到非叶子节点：
  - 先临时创建一个.tree文件，递归扫描每一个子节点
  - 将每个子节点的返回Node的ID和name写入.tree
  - 所有子节点都完成后，直接取这个.tree文件的哈希值作为树节点ID
  - 同样在nodePool中检测，若不重复则创建，返回，重复则直接返回nodePool中的。

最后返回的Node在commitAllWork中接收检查，检查是否和历史某个版本重复（因为是依赖哈希值ID索引，存在版本重复时就会有歧义），若重复则拒绝提交并将当前分支切换到发生重复的地方；没什么问题则将最后返回的Node提升为CommitNode，创建一个新的版本节点。



##### 撤销

数据流：按钮点击 - Widget/确认撤销 - operator/restore - forceLoad(当前版本) - loadNode - Widget/刷新diff列表

撤销和强制转移都采用一个非常暴力的方法：将工作区整个删除，再从版本库中加载指定版本的内容。



##### 回滚

数据流：按钮点击 - ContextMenu/检查工作区是否干净 - operator/switchToNode- compareAndSwitch - loadNode - Widget/刷新绘图区，diff列表

主体操作在compareAndSwitch这一部分

```c++
void compareAndSwitch(const string &path, TreeNode *from, TreeNode *to);
```

它是一个递归函数，参数给出工作区路径，转移前的节点，转移去的节点，做的工作是对比from和to之间的不同，在工作区路径下作出相应的更改。

执行前检查了工作区，保证没有未提交的内容，也就是保证了执行时工作区和from节点始终是一样的。

对比时，扫描from和to的每个子节点，**分类讨论**：

- 对于FileNode：
  - 只一方有：from有则整个文件夹从工作区中移除，to有则loadNode到工作区
  - 双方都有但不同：从to中拷贝到工作区并覆盖

- 对于TreeNode：
  - 只一方有：from有则整个文件夹从工作区中移除，to有则loadNode到工作区
  - 双方都有：递归解决

如此即切换到了指定的to版本下，不仅是回滚，也可以在分支（分叉）间任意移动或是向前加载



##### 合并

数据流：按钮点击 - ContextMenu/检查工作区是否干净 - operator/pullFromCommit - getCommitLca - compareAndMerge返回diff - 



##### 对比





