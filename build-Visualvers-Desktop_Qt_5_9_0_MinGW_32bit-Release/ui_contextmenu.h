/********************************************************************************
** Form generated from reading UI file 'contextmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTEXTMENU_H
#define UI_CONTEXTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ContextMenu
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *diffWithNodeButton;
    QPushButton *pullFromCommitButton;
    QPushButton *switchToNodeButton;

    void setupUi(QDialog *ContextMenu)
    {
        if (ContextMenu->objectName().isEmpty())
            ContextMenu->setObjectName(QStringLiteral("ContextMenu"));
        ContextMenu->resize(210, 181);
        ContextMenu->setStyleSheet(QLatin1String("#ContextMenu{\n"
"border: 2px #555555;\n"
"border-style: outset;\n"
"}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(ContextMenu);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        diffWithNodeButton = new QPushButton(ContextMenu);
        diffWithNodeButton->setObjectName(QStringLiteral("diffWithNodeButton"));
        diffWithNodeButton->setEnabled(false);
        diffWithNodeButton->setMinimumSize(QSize(140, 40));
        diffWithNodeButton->setStyleSheet(QLatin1String("#diffWithNodeButton{\n"
"	background-color:rgb(239, 255, 254);\n"
"	color: rgb(102, 102, 102);   \n"
"	border-radius: 15px;  \n"
"	border: 2px #555555;\n"
"	border-style: outset;\n"
"}\n"
"\n"
"#diffWithNodeButton:hover{\n"
"	background-color:rgb(226, 255, 253);\n"
"	color: rgb(58, 58, 58);   \n"
"	border-radius: 15px;  \n"
"	border: 2px rgb(206, 206, 206);\n"
"	border-style: outset;\n"
"}\n"
"#diffWithNodeButton:disabled{\n"
"	background-color:rgb(243, 255, 255);\n"
"	color: rgb(207, 207, 207);   \n"
"	border-radius: 15px;  \n"
"	border: 2px rgb(206, 206, 206);\n"
"	border-style: outset;\n"
"}"));
        diffWithNodeButton->setCheckable(false);

        verticalLayout->addWidget(diffWithNodeButton);

        pullFromCommitButton = new QPushButton(ContextMenu);
        pullFromCommitButton->setObjectName(QStringLiteral("pullFromCommitButton"));
        pullFromCommitButton->setEnabled(false);
        pullFromCommitButton->setMinimumSize(QSize(140, 40));
        pullFromCommitButton->setStyleSheet(QLatin1String("#pullFromCommitButton{\n"
"	background-color:rgb(239, 255, 254);\n"
"	color: rgb(102, 102, 102);   \n"
"	border-radius: 15px;  \n"
"	border: 2px #555555;\n"
"	border-style: outset;\n"
"}\n"
"\n"
"#pullFromCommitButton:hover{\n"
"	background-color:rgb(226, 255, 253);\n"
"	color: rgb(58, 58, 58);   \n"
"	border-radius: 15px;  \n"
"	border: 2px rgb(206, 206, 206);\n"
"	border-style: outset;\n"
"}\n"
"#pullFromCommitButton:disabled{\n"
"	background-color:rgb(243, 255, 255);\n"
"	color: rgb(207, 207, 207);   \n"
"	border-radius: 15px;  \n"
"	border: 2px rgb(206, 206, 206);\n"
"	border-style: outset;\n"
"}"));

        verticalLayout->addWidget(pullFromCommitButton);

        switchToNodeButton = new QPushButton(ContextMenu);
        switchToNodeButton->setObjectName(QStringLiteral("switchToNodeButton"));
        switchToNodeButton->setEnabled(false);
        switchToNodeButton->setMinimumSize(QSize(140, 40));
        switchToNodeButton->setStyleSheet(QLatin1String("#switchToNodeButton{\n"
"	background-color:rgb(239, 255, 254);\n"
"	color: rgb(102, 102, 102);   \n"
"	border-radius: 15px;  \n"
"	border: 2px #555555;\n"
"	border-style: outset;\n"
"}\n"
"\n"
"#switchToNodeButton:hover{\n"
"	background-color:rgb(226, 255, 253);\n"
"	color: rgb(58, 58, 58);   \n"
"	border-radius: 15px;  \n"
"	border: 2px rgb(206, 206, 206);\n"
"	border-style: outset;\n"
"}\n"
"#switchToNodeButton:disabled{\n"
"	background-color:rgb(243, 255, 255);\n"
"	color: rgb(207, 207, 207);   \n"
"	border-radius: 15px;  \n"
"	border: 2px rgb(206, 206, 206);\n"
"	border-style: outset;\n"
"}"));

        verticalLayout->addWidget(switchToNodeButton);


        retranslateUi(ContextMenu);

        QMetaObject::connectSlotsByName(ContextMenu);
    } // setupUi

    void retranslateUi(QDialog *ContextMenu)
    {
        ContextMenu->setWindowTitle(QApplication::translate("ContextMenu", "Dialog", Q_NULLPTR));
        diffWithNodeButton->setText(QApplication::translate("ContextMenu", "\345\257\271\346\257\224\346\255\244\350\212\202\347\202\271\344\270\216\345\267\245\344\275\234\345\214\272", Q_NULLPTR));
        pullFromCommitButton->setText(QApplication::translate("ContextMenu", "\344\273\216\346\255\244\350\212\202\347\202\271\346\213\211\345\217\226/\345\220\210\345\271\266", Q_NULLPTR));
        switchToNodeButton->setText(QApplication::translate("ContextMenu", "\345\210\207\346\215\242\345\267\245\344\275\234\345\214\272\345\210\260\346\255\244\350\212\202\347\202\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ContextMenu: public Ui_ContextMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTEXTMENU_H
