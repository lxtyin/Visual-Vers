
#include "diffdialog.h"
#include "ui_diffDialog.h"
#include "command.h"

diffDialog::diffDialog(vector<string> &diff, const string &name, QWidget *parent) :
    QDialog(parent), ui(new Ui::diffDialog)
{
    ui->setupUi(this);
    // 第一行的样式在ui中设置好，后面的在构造函数中添上

    connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::close);

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
}

diffDialog::~diffDialog() {
    delete ui;
}
