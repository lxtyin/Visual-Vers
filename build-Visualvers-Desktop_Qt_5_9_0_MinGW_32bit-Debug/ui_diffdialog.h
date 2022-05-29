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
#include <QtWidgets/QHBoxLayout>
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
    QHBoxLayout *horizontalLayout;
    QPushButton *closeButton;

    void setupUi(QDialog *diffDialog)
    {
        if (diffDialog->objectName().isEmpty())
            diffDialog->setObjectName(QStringLiteral("diffDialog"));
        diffDialog->resize(500, 700);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(14);
        diffDialog->setFont(font);
        verticalLayout = new QVBoxLayout(diffDialog);
        verticalLayout->setSpacing(25);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 25);
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(55, -1, 55, -1);
        closeButton = new QPushButton(diffDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(100, 50));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


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

        closeButton->setText(QApplication::translate("diffDialog", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class diffDialog: public Ui_diffDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFDIALOG_H
