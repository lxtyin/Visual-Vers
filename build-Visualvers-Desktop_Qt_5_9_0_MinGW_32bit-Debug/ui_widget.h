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
    QListWidget *workSpaceWidget;
    QScrollArea *scrollArea;
    myPainterWidget *scrollAreaWidgetContents;
    QLabel *currentFlag;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *commitButton;
    QPushButton *restoreButton;
    QPushButton *freshButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *commentTextEdit;
    QLabel *curAvatar;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *idLabel;
    QDateTimeEdit *commitTime;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *closeButton;
    QLabel *Avatar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1125, 743);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(false);
        font.setWeight(50);
        Widget->setFont(font);
        workSpaceWidget = new QListWidget(Widget);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(189, 250, 186, 255));
        brush1.setStyle(Qt::Dense2Pattern);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(workSpaceWidget);
        __qlistwidgetitem->setFont(font1);
        __qlistwidgetitem->setBackground(brush1);
        __qlistwidgetitem->setForeground(brush);
        QBrush brush2(QColor(255, 138, 138, 255));
        brush2.setStyle(Qt::Dense6Pattern);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(workSpaceWidget);
        __qlistwidgetitem1->setFont(font1);
        __qlistwidgetitem1->setBackground(brush2);
        QBrush brush3(QColor(161, 197, 255, 255));
        brush3.setStyle(Qt::BDiagPattern);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(workSpaceWidget);
        __qlistwidgetitem2->setFont(font1);
        __qlistwidgetitem2->setBackground(brush3);
        new QListWidgetItem(workSpaceWidget);
        new QListWidgetItem(workSpaceWidget);
        new QListWidgetItem(workSpaceWidget);
        new QListWidgetItem(workSpaceWidget);
        new QListWidgetItem(workSpaceWidget);
        new QListWidgetItem(workSpaceWidget);
        workSpaceWidget->setObjectName(QStringLiteral("workSpaceWidget"));
        workSpaceWidget->setGeometry(QRect(10, 69, 431, 661));
        workSpaceWidget->setStyleSheet(QStringLiteral("background-color: rgb(217, 217, 217);"));
        scrollArea = new QScrollArea(Widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(440, 230, 663, 500));
        scrollArea->setMinimumSize(QSize(0, 500));
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new myPainterWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 661, 498));
        scrollAreaWidgetContents->setStyleSheet(QStringLiteral("#scrollAreaWidgetContents{background-color: rgb(217, 217, 217);}"));
        currentFlag = new QLabel(scrollAreaWidgetContents);
        currentFlag->setObjectName(QStringLiteral("currentFlag"));
        currentFlag->setGeometry(QRect(70, 130, 60, 60));
        currentFlag->setPixmap(QPixmap(QString::fromUtf8(":/images/img/flag.png")));
        currentFlag->setAlignment(Qt::AlignCenter);
        scrollArea->setWidget(scrollAreaWidgetContents);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 24, 431, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        commitButton = new QPushButton(layoutWidget);
        commitButton->setObjectName(QStringLiteral("commitButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(commitButton->sizePolicy().hasHeightForWidth());
        commitButton->setSizePolicy(sizePolicy);
        commitButton->setMinimumSize(QSize(141, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Adobe Devanagari"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        commitButton->setFont(font2);
        commitButton->setStyleSheet(QLatin1String("#commitButton{\n"
"	padding:3px;\n"
"	background-color: rgb(88, 88, 88);\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	image: url(:/images/img/submit_white.png) 13dp 13dp;\n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#commitButton:hover{\n"
"	background-color: rgb(225, 225, 225);\n"
"	color: rgb(95, 95, 95);\n"
"	padding:3px;\n"
"	\n"
"	image: url(:/images/img/submit_black.png);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#commitButton:pressed{\n"
"	background-color:rgb(140, 163, 163);\n"
"	padding:3px;\n"
"	image: url(:/images/img/submit_white.png);\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}"));
        commitButton->setIconSize(QSize(3, 3));

        horizontalLayout->addWidget(commitButton);

        restoreButton = new QPushButton(layoutWidget);
        restoreButton->setObjectName(QStringLiteral("restoreButton"));
        restoreButton->setMinimumSize(QSize(141, 40));
        restoreButton->setStyleSheet(QLatin1String("#restoreButton{\n"
"	background-color: rgb(88, 88, 88);\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	\n"
"	image: url(:/images/img/back_white.png);\n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#restoreButton:hover{\n"
"	background-color: rgb(225, 225, 225);\n"
"	color: rgb(95, 95, 95);\n"
"	\n"
"	\n"
"	image: url(:/images/img/back_black.png);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#restoreButton:pressed{\n"
"	background-color:rgb(140, 163, 163);\n"
"	image: url(:/images/img/back_white.png);\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}"));
        restoreButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(restoreButton);

        freshButton = new QPushButton(layoutWidget);
        freshButton->setObjectName(QStringLiteral("freshButton"));
        freshButton->setMinimumSize(QSize(141, 40));
        freshButton->setStyleSheet(QLatin1String("#freshButton{\n"
"	background-color: rgb(88, 88, 88);\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	padding:3px;\n"
"	image: url(:/images/img/reflash_white.png);\n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#freshButton:hover{\n"
"	background-color: rgb(225, 225, 225);\n"
"	color: rgb(95, 95, 95);\n"
"	padding:3px;\n"
"	image: url(:/images/img/reflash_black.png);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#freshButton:pressed{\n"
"	padding:3px;\n"
"	background-color:rgb(140, 163, 163);\n"
"	image: url(:/images/img/reflash_white.png);\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}"));
        freshButton->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(freshButton);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(440, 110, 501, 123));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        commentTextEdit = new QTextEdit(layoutWidget1);
        commentTextEdit->setObjectName(QStringLiteral("commentTextEdit"));
        commentTextEdit->setMinimumSize(QSize(300, 100));
        commentTextEdit->setMaximumSize(QSize(16777215, 170));
        commentTextEdit->setStyleSheet(QStringLiteral("background-color:rgb(237, 237, 237);"));

        horizontalLayout_2->addWidget(commentTextEdit);

        curAvatar = new QLabel(layoutWidget1);
        curAvatar->setObjectName(QStringLiteral("curAvatar"));
        curAvatar->setMinimumSize(QSize(121, 121));
        curAvatar->setStyleSheet(QLatin1String("background-color:rgb(237, 237, 237);\n"
"border-width:3px;\n"
""));

        horizontalLayout_2->addWidget(curAvatar);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(440, 24, 501, 89));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        idLabel = new QLabel(layoutWidget2);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        idLabel->setMinimumSize(QSize(300, 40));
        idLabel->setFont(font);
        idLabel->setStyleSheet(QStringLiteral("background-color:rgb(237, 237, 237);"));

        verticalLayout_2->addWidget(idLabel);

        commitTime = new QDateTimeEdit(layoutWidget2);
        commitTime->setObjectName(QStringLiteral("commitTime"));
        commitTime->setEnabled(false);
        commitTime->setMinimumSize(QSize(150, 40));
        commitTime->setStyleSheet(QStringLiteral("background-color:rgb(237, 237, 237);"));

        verticalLayout_2->addWidget(commitTime);

        layoutWidget3 = new QWidget(Widget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(940, 24, 163, 211));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        closeButton = new QPushButton(layoutWidget3);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(150, 42));
        closeButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(202, 255, 194);\n"
"}\n"
""));

        verticalLayout_3->addWidget(closeButton);

        Avatar = new QLabel(layoutWidget3);
        Avatar->setObjectName(QStringLiteral("Avatar"));
        Avatar->setMinimumSize(QSize(161, 161));
        Avatar->setMaximumSize(QSize(16777215, 160));
        Avatar->setStyleSheet(QLatin1String("background-color:rgb(237, 237, 237);\n"
"border-width:3px;\n"
""));

        verticalLayout_3->addWidget(Avatar);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));

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

        currentFlag->setText(QString());
        commitButton->setText(QString());
        restoreButton->setText(QString());
        freshButton->setText(QString());
        curAvatar->setText(QString());
        idLabel->setText(QApplication::translate("Widget", "ID\357\274\232", Q_NULLPTR));
        closeButton->setText(QApplication::translate("Widget", "\344\270\213\347\217\255", Q_NULLPTR));
        Avatar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
