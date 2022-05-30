/********************************************************************************
** Form generated from reading UI file 'startdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTDIALOG_H
#define UI_STARTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StartDialog
{
public:
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *openButton;
    QPushButton *newButton;
    QLabel *label_2;

    void setupUi(QDialog *StartDialog)
    {
        if (StartDialog->objectName().isEmpty())
            StartDialog->setObjectName(QStringLiteral("StartDialog"));
        StartDialog->resize(436, 451);
        label = new QLabel(StartDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 360, 80));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/img/title.png")));
        listWidget = new QListWidget(StartDialog);
        QBrush brush(QColor(134, 152, 255, 255));
        brush.setStyle(Qt::BDiagPattern);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font1);
        __qlistwidgetitem->setBackground(brush);
        QBrush brush1(QColor(134, 152, 255, 255));
        brush1.setStyle(Qt::BDiagPattern);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setFont(font1);
        __qlistwidgetitem1->setBackground(brush1);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 150, 401, 271));
        listWidget->setSpacing(5);
        openButton = new QPushButton(StartDialog);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(310, 90, 101, 41));
        openButton->setStyleSheet(QString::fromUtf8("#openButton{\n"
"	padding:3px;\n"
"	background-color: rgb(226, 255, 253);\n"
"	color: rgb(95, 95, 95); \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"	\n"
"	font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	\n"
"}\n"
"#openButton:hover{\n"
"	background-color:rgb(139, 255, 242);\n"
"	color: rgb(0, 0, 0);\n"
"	padding:3px;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"	font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        newButton = new QPushButton(StartDialog);
        newButton->setObjectName(QStringLiteral("newButton"));
        newButton->setGeometry(QRect(190, 90, 111, 41));
        newButton->setStyleSheet(QString::fromUtf8("#newButton{\n"
"	padding:3px;\n"
"	background-color: rgb(226, 255, 253);\n"
"	color: rgb(95, 95, 95); \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"	\n"
"	font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	\n"
"}\n"
"#newButton:hover{\n"
"	background-color:rgb(139, 255, 242);\n"
"	color: rgb(0, 0, 0);\n"
"	padding:3px;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"	font: 75 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        label_2 = new QLabel(StartDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 100, 101, 31));
        label_2->setStyleSheet(QStringLiteral("font: 14pt \"Adobe Devanagari\";"));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(StartDialog);

        QMetaObject::connectSlotsByName(StartDialog);
    } // setupUi

    void retranslateUi(QDialog *StartDialog)
    {
        StartDialog->setWindowTitle(QApplication::translate("StartDialog", "VisualVers", Q_NULLPTR));
        label->setText(QString());

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("StartDialog", "C:\\user/10923\\windows\\destop", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("StartDialog", "C:\\Users\\86186\\Desktop\\Qt", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

        openButton->setText(QApplication::translate("StartDialog", "\346\211\223\345\274\200", Q_NULLPTR));
        newButton->setText(QApplication::translate("StartDialog", "\346\226\260\345\273\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("StartDialog", "\346\234\200\350\277\221\351\241\271\347\233\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StartDialog: public Ui_StartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTDIALOG_H
