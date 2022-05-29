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
        ContextMenu->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(ContextMenu);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        diffWithNodeButton = new QPushButton(ContextMenu);
        diffWithNodeButton->setObjectName(QStringLiteral("diffWithNodeButton"));
        diffWithNodeButton->setEnabled(true);
        diffWithNodeButton->setMinimumSize(QSize(140, 40));
        diffWithNodeButton->setStyleSheet(QStringLiteral(""));
        diffWithNodeButton->setCheckable(false);

        verticalLayout->addWidget(diffWithNodeButton);

        pullFromCommitButton = new QPushButton(ContextMenu);
        pullFromCommitButton->setObjectName(QStringLiteral("pullFromCommitButton"));
        pullFromCommitButton->setEnabled(true);
        pullFromCommitButton->setMinimumSize(QSize(140, 40));
        pullFromCommitButton->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(pullFromCommitButton);

        switchToNodeButton = new QPushButton(ContextMenu);
        switchToNodeButton->setObjectName(QStringLiteral("switchToNodeButton"));
        switchToNodeButton->setEnabled(true);
        switchToNodeButton->setMinimumSize(QSize(140, 40));

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
