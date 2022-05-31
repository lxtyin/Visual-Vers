/********************************************************************************
** Form generated from reading UI file 'diffdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFDIALOG_H
#define UI_DIFFDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_diffDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *diffListWidget;
    QPushButton *closeButton;
    QPushButton *applyButton;

    void setupUi(QDialog *diffDialog)
    {
        if (diffDialog->objectName().isEmpty())
            diffDialog->setObjectName(QStringLiteral("diffDialog"));
        diffDialog->resize(398, 529);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(14);
        diffDialog->setFont(font);
        verticalLayout = new QVBoxLayout(diffDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        diffListWidget = new QListWidget(diffDialog);
        QBrush brush(QColor(224, 227, 238, 255));
        brush.setStyle(Qt::BDiagPattern);
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setWeight(75);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(diffListWidget);
        __qlistwidgetitem->setFont(font1);
        __qlistwidgetitem->setBackground(brush);
        diffListWidget->setObjectName(QStringLiteral("diffListWidget"));
        diffListWidget->setFont(font);

        verticalLayout->addWidget(diffListWidget);

        closeButton = new QPushButton(diffDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(100, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        closeButton->setFont(font2);
        closeButton->setStyleSheet(QLatin1String("#closeButton{\n"
"	padding:3px;\n"
"	background-color: rgb(154, 154, 154);\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#closeButton:hover{\n"
"	background-color: rgb(211, 255, 152);\n"
"	padding:3px;\n"
"	\n"
"	color: black;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#closeButton:pressed{\n"
"	background-color:rgb(140, 163, 163);\n"
"	padding:3px;\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}"));

        verticalLayout->addWidget(closeButton);

        applyButton = new QPushButton(diffDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setMinimumSize(QSize(100, 50));
        applyButton->setFont(font2);
        applyButton->setStyleSheet(QLatin1String("#applyButton{\n"
"	padding:3px;\n"
"	background-color: rgb(154, 154, 154);\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#applyButton:hover{\n"
"	background-color: rgb(211, 255, 152);\n"
"	padding:3px;\n"
"	\n"
"	color: black;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#applyButton:pressed{\n"
"	background-color:rgb(140, 163, 163);\n"
"	padding:3px;\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}"));

        verticalLayout->addWidget(applyButton);


        retranslateUi(diffDialog);

        QMetaObject::connectSlotsByName(diffDialog);
    } // setupUi

    void retranslateUi(QDialog *diffDialog)
    {
        diffDialog->setWindowTitle(QApplication::translate("diffDialog", "\345\217\230\346\233\264\345\206\205\345\256\271", Q_NULLPTR));

        const bool __sortingEnabled = diffListWidget->isSortingEnabled();
        diffListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = diffListWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("diffDialog", "main.cpp", Q_NULLPTR));
        diffListWidget->setSortingEnabled(__sortingEnabled);

        closeButton->setText(QApplication::translate("diffDialog", "\347\241\256\350\256\244", Q_NULLPTR));
        applyButton->setText(QApplication::translate("diffDialog", "\345\272\224\347\224\250\345\210\260\345\267\245\344\275\234\345\214\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class diffDialog: public Ui_diffDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFDIALOG_H
