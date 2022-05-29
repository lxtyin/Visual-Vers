/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myPainterWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    myPainterWidget *scrollAreaWidgetContents;
    QLabel *currentFlag;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *idLabel;
    QLabel *commitbyLabel;
    QLabel *committimeLabel;
    QDateTimeEdit *commitTime;
    QLabel *commentLabel;
    QTextEdit *commentTextEdit;
    QPushButton *switchToNodeButton;
    QPushButton *pullFromCommitButton;
    QPushButton *diffWithNodeButton;
    QHBoxLayout *horizontalLayout;
    QListWidget *workSpaceWidget;
    QVBoxLayout *verticalLayout_4;
    QPushButton *freshButton;
    QPushButton *restoreButton;
    QPushButton *closeButton;
    QPushButton *commitButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1143, 691);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(false);
        font.setWeight(50);
        Widget->setFont(font);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setSpacing(15);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        scrollArea = new QScrollArea(Widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(800, 500));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new myPainterWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 498));
        currentFlag = new QLabel(scrollAreaWidgetContents);
        currentFlag->setObjectName(QStringLiteral("currentFlag"));
        currentFlag->setGeometry(QRect(150, 160, 60, 60));
        currentFlag->setPixmap(QPixmap(QString::fromUtf8(":/images/img/flag.png")));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        idLabel = new QLabel(Widget);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        idLabel->setMinimumSize(QSize(300, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        idLabel->setFont(font1);

        verticalLayout->addWidget(idLabel);

        commitbyLabel = new QLabel(Widget);
        commitbyLabel->setObjectName(QStringLiteral("commitbyLabel"));
        commitbyLabel->setFont(font1);

        verticalLayout->addWidget(commitbyLabel);

        committimeLabel = new QLabel(Widget);
        committimeLabel->setObjectName(QStringLiteral("committimeLabel"));
        committimeLabel->setFont(font1);

        verticalLayout->addWidget(committimeLabel);

        commitTime = new QDateTimeEdit(Widget);
        commitTime->setObjectName(QStringLiteral("commitTime"));
        commitTime->setEnabled(false);

        verticalLayout->addWidget(commitTime);

        commentLabel = new QLabel(Widget);
        commentLabel->setObjectName(QStringLiteral("commentLabel"));
        commentLabel->setFont(font1);

        verticalLayout->addWidget(commentLabel);

        commentTextEdit = new QTextEdit(Widget);
        commentTextEdit->setObjectName(QStringLiteral("commentTextEdit"));
        commentTextEdit->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(commentTextEdit);


        verticalLayout_2->addLayout(verticalLayout);

        switchToNodeButton = new QPushButton(Widget);
        switchToNodeButton->setObjectName(QStringLiteral("switchToNodeButton"));
        switchToNodeButton->setEnabled(false);

        verticalLayout_2->addWidget(switchToNodeButton);

        pullFromCommitButton = new QPushButton(Widget);
        pullFromCommitButton->setObjectName(QStringLiteral("pullFromCommitButton"));
        pullFromCommitButton->setEnabled(false);

        verticalLayout_2->addWidget(pullFromCommitButton);

        diffWithNodeButton = new QPushButton(Widget);
        diffWithNodeButton->setObjectName(QStringLiteral("diffWithNodeButton"));
        diffWithNodeButton->setEnabled(false);
        diffWithNodeButton->setCheckable(false);

        verticalLayout_2->addWidget(diffWithNodeButton);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        workSpaceWidget = new QListWidget(Widget);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(189, 250, 186, 255));
        brush1.setStyle(Qt::Dense2Pattern);
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(workSpaceWidget);
        __qlistwidgetitem->setFont(font2);
        __qlistwidgetitem->setBackground(brush1);
        __qlistwidgetitem->setForeground(brush);
        QBrush brush2(QColor(255, 138, 138, 255));
        brush2.setStyle(Qt::Dense6Pattern);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(workSpaceWidget);
        __qlistwidgetitem1->setFont(font2);
        __qlistwidgetitem1->setBackground(brush2);
        QBrush brush3(QColor(161, 197, 255, 255));
        brush3.setStyle(Qt::BDiagPattern);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(workSpaceWidget);
        __qlistwidgetitem2->setFont(font2);
        __qlistwidgetitem2->setBackground(brush3);
        new QListWidgetItem(workSpaceWidget);
        new QListWidgetItem(workSpaceWidget);
        new QListWidgetItem(workSpaceWidget);
        new QListWidgetItem(workSpaceWidget);
        new QListWidgetItem(workSpaceWidget);
        new QListWidgetItem(workSpaceWidget);
        workSpaceWidget->setObjectName(QStringLiteral("workSpaceWidget"));

        horizontalLayout->addWidget(workSpaceWidget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        freshButton = new QPushButton(Widget);
        freshButton->setObjectName(QStringLiteral("freshButton"));
        freshButton->setMinimumSize(QSize(150, 40));

        verticalLayout_4->addWidget(freshButton);

        restoreButton = new QPushButton(Widget);
        restoreButton->setObjectName(QStringLiteral("restoreButton"));
        restoreButton->setMinimumSize(QSize(150, 40));

        verticalLayout_4->addWidget(restoreButton);

        closeButton = new QPushButton(Widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(150, 40));
        closeButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(202, 255, 194);\n"
"}\n"
""));

        verticalLayout_4->addWidget(closeButton);


        horizontalLayout->addLayout(verticalLayout_4);

        commitButton = new QPushButton(Widget);
        commitButton->setObjectName(QStringLiteral("commitButton"));
        commitButton->setMinimumSize(QSize(150, 150));
        QFont font3;
        font3.setPointSize(15);
        commitButton->setFont(font3);

        horizontalLayout->addWidget(commitButton);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        currentFlag->setText(QString());
        idLabel->setText(QApplication::translate("Widget", "ID\357\274\232", Q_NULLPTR));
        commitbyLabel->setText(QApplication::translate("Widget", "CommitBy\357\274\232", Q_NULLPTR));
        committimeLabel->setText(QApplication::translate("Widget", "CommitTime\357\274\232", Q_NULLPTR));
        commentLabel->setText(QApplication::translate("Widget", "Comment\357\274\232", Q_NULLPTR));
        switchToNodeButton->setText(QApplication::translate("Widget", "\345\210\207\346\215\242\345\267\245\344\275\234\345\214\272\345\210\260\346\255\244\350\212\202\347\202\271", Q_NULLPTR));
        pullFromCommitButton->setText(QApplication::translate("Widget", "\344\273\216\346\255\244\350\212\202\347\202\271\346\213\211\345\217\226/\345\220\210\345\271\266", Q_NULLPTR));
        diffWithNodeButton->setText(QApplication::translate("Widget", "\345\257\271\346\257\224\346\255\244\350\212\202\347\202\271\344\270\216\345\267\245\344\275\234\345\214\272", Q_NULLPTR));

        const bool __sortingEnabled = workSpaceWidget->isSortingEnabled();
        workSpaceWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = workSpaceWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Widget", "+ /asdasdasdaf", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = workSpaceWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Widget", "-  /gkuhhvkhbu", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = workSpaceWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Widget", "*  /sadasdasdsd", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = workSpaceWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Widget", "\346\226\260\345\273\272\351\241\271\347\233\256", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem4 = workSpaceWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("Widget", "\346\226\260\345\273\272\351\241\271\347\233\256", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem5 = workSpaceWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("Widget", "\346\226\260\345\273\272\351\241\271\347\233\256", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem6 = workSpaceWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("Widget", "\346\226\260\345\273\272\351\241\271\347\233\256", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem7 = workSpaceWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("Widget", "\346\226\260\345\273\272\351\241\271\347\233\256", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem8 = workSpaceWidget->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("Widget", "\346\226\260\345\273\272\351\241\271\347\233\256", Q_NULLPTR));
        workSpaceWidget->setSortingEnabled(__sortingEnabled);

        freshButton->setText(QApplication::translate("Widget", "\345\210\267\346\226\260", Q_NULLPTR));
        restoreButton->setText(QApplication::translate("Widget", "\346\222\244\351\224\200\346\233\264\346\224\271", Q_NULLPTR));
        closeButton->setText(QApplication::translate("Widget", "\344\270\213\347\217\255", Q_NULLPTR));
        commitButton->setText(QApplication::translate("Widget", "\346\217\220\344\272\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
