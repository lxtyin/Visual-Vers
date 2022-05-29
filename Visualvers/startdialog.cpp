#include "startdialog.h"
#include "ui_startdialog.h"
#include <QFileDialog>
#include "operator.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
    ui->listWidget->clear();
    QBrush brush(QColor(134, 152, 255, 255)); //样式
    brush.setStyle(Qt::BDiagPattern);
    QFont font1;
    font1.setPointSize(12);
    font1.setBold(true);
    font1.setWeight(75);

    readFile("recent.txt", lines);
    for(string &str: lines){
        cout << str;
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(ui->listWidget);
        __qlistwidgetitem->setFont(font1);
        __qlistwidgetitem->setBackground(brush);
        __qlistwidgetitem->setText(Str2Q(str));
    }

    connect(ui->listWidget, &QListWidget::itemDoubleClicked, [&](QListWidgetItem *item){
        //打开一个最近仓库
        ROOT_PATH = Q2Str(item->text());
        if(judgePath(REPO_PATH) == EMPTY_PATH){
            Error("项目不存在，可能被移动或移除！", this);
            delete item;
        }else openRepo();
    });
    connect(ui->openButton, &QPushButton::clicked, [&](){
        //打开本地仓库
        QString rootpath = QFileDialog::getExistingDirectory(this, "打开一个已有的仓库", "..");
        if(rootpath.isEmpty()) return;
        ROOT_PATH = Q2Str(rootpath.replace('/', '\\'));
        if(judgePath(REPO_PATH) == EMPTY_PATH){
            Error("这并不是一个仓库！", this);
        }else openRepo();
    });
    connect(ui->newButton, &QPushButton::clicked, [&](){
        //新建一个仓库
        QString rootpath = QFileDialog::getExistingDirectory(this, "选择仓库目录", "..");
        if(rootpath.isEmpty()) return;
        ROOT_PATH = Q2Str(rootpath.replace('/', '\\'));
        init();
        openRepo();
    });
}

StartDialog::~StartDialog() {
    delete ui;
}

void StartDialog::openRepo(){ //ROOT_PATH已经确定，打开目录
    //更新recent.txt
    auto tmp = lines;
    lines.clear();
    lines.push_back(ROOT_PATH);
    for(string &str: tmp){
        if(str != ROOT_PATH) lines.push_back(str);
    }
    loadFile("recent.txt", lines);
    accept();
}
