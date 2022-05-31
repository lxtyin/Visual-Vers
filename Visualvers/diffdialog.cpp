
#include "diffdialog.h"
#include "ui_diffDialog.h"
#include "command.h"
#include <QDebug>

diffDialog::diffDialog(vector<string> &diff, const string &name,
    const string &f, const string &t, QWidget *parent):
    QDialog(parent), ui(new Ui::diffDialog)
{
    ui->setupUi(this);
    // 第一行的样式在ui中设置好，后面的在构造函数中添上

    ui->diffListWidget->item(0)->setText(Str2Q(name));

    QFont font;
    font.setFamily(QStringLiteral("Consolas"));
    font.setPointSize(14);
    QBrush add(QColor(219, 255, 208, 255));
    add.setStyle(Qt::SolidPattern);
    QBrush del(QColor(255, 205, 205, 255));
    del.setStyle(Qt::SolidPattern);

    for(string &str: diff){
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem;
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setText(Str2Q(str));
        if(str[0] == '+') __qlistwidgetitem->setBackground(add);
        else if(str[0] == '-') __qlistwidgetitem->setBackground(del);
        else __qlistwidgetitem->setBackground(Qt::NoBrush);
        ui->diffListWidget->addItem(__qlistwidgetitem);
    }

    this->show();
    connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::close);

    //允许开启一个按钮，按下时将sfrom的内容应用到sto
    if(t.empty()){
        delete ui->applyButton;
    }else{
        connect(ui->applyButton, &QPushButton::clicked, [&](){
            if(f.empty()) DeleteAny(t); //f是空 则将删除应用到t
            else CopyAFile(f, t);
            accept();
        });
    }
}

diffDialog::~diffDialog() {
    delete ui;
}
