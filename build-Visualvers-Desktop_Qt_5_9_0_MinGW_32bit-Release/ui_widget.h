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
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *restoreButton;
    QPushButton *freshButton;
    QPushButton *commitButton;
    QListWidget *workSpaceWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *idLabel;
    QLabel *timeLabel;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *commentTextEdit;
    QLabel *curAvatar;
    QVBoxLayout *verticalLayout_3;
    QPushButton *closeButton;
    QLabel *userAvatar;
    QScrollArea *scrollArea;
    myPainterWidget *scrollAreaWidgetContents;
    QLabel *currentFlag;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(904, 611);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(false);
        font.setWeight(50);
        Widget->setFont(font);
        horizontalLayout_4 = new QHBoxLayout(Widget);
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(5);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        restoreButton = new QPushButton(Widget);
        restoreButton->setObjectName(QStringLiteral("restoreButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(restoreButton->sizePolicy().hasHeightForWidth());
        restoreButton->setSizePolicy(sizePolicy);
        restoreButton->setMinimumSize(QSize(150, 40));
        restoreButton->setMaximumSize(QSize(150, 40));
        restoreButton->setStyleSheet(QLatin1String("#restoreButton{\n"
"	background-color: rgb(88, 88, 88);\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	padding:3px;\n"
"	image: url(:/images/img/back_white.png);\n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#restoreButton:hover{\n"
"	background-color: rgb(255, 157, 157);\n"
"	color: rgb(95, 95, 95);\n"
"	padding:3px;\n"
"	\n"
"	image: url(:/images/img/back_black.png);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"}\n"
"#restoreButton:pressed{\n"
"	padding:3px;\n"
"	background-color:rgb(140, 163, 163);\n"
"	image: url(:/images/img/back_white.png);\n"
"	color: rgb(95, 95, 95);\n"
"	color: white;   \n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"\n"
"}"));
        restoreButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(restoreButton);

        freshButton = new QPushButton(Widget);
        freshButton->setObjectName(QStringLiteral("freshButton"));
        sizePolicy.setHeightForWidth(freshButton->sizePolicy().hasHeightForWidth());
        freshButton->setSizePolicy(sizePolicy);
        freshButton->setMinimumSize(QSize(150, 40));
        freshButton->setMaximumSize(QSize(150, 40));
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
"	\n"
"	background-color: rgb(211, 255, 152);\n"
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


        verticalLayout_4->addLayout(horizontalLayout);

        commitButton = new QPushButton(Widget);
        commitButton->setObjectName(QStringLiteral("commitButton"));
        sizePolicy.setHeightForWidth(commitButton->sizePolicy().hasHeightForWidth());
        commitButton->setSizePolicy(sizePolicy);
        commitButton->setMinimumSize(QSize(300, 40));
        commitButton->setMaximumSize(QSize(16777215, 300));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Devanagari"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        commitButton->setFont(font1);
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
"	background-color: rgb(211, 255, 152);\n"
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

        verticalLayout_4->addWidget(commitButton);


        verticalLayout_6->addLayout(verticalLayout_4);

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
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(workSpaceWidget->sizePolicy().hasHeightForWidth());
        workSpaceWidget->setSizePolicy(sizePolicy1);
        workSpaceWidget->setMinimumSize(QSize(300, 500));
        workSpaceWidget->setMaximumSize(QSize(16777215, 16777215));
        workSpaceWidget->setStyleSheet(QLatin1String("\n"
"border-style: outset;\n"
"border-width:2px;\n"
"border-color: rgb(132, 132, 132);"));
        workSpaceWidget->setSpacing(2);

        verticalLayout_6->addWidget(workSpaceWidget);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        idLabel = new QLabel(Widget);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(10);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(idLabel->sizePolicy().hasHeightForWidth());
        idLabel->setSizePolicy(sizePolicy2);
        idLabel->setMinimumSize(QSize(300, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("Consolas"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(9);
        idLabel->setFont(font3);
        idLabel->setStyleSheet(QLatin1String("background-color:rgb(237, 237, 237);\n"
"border-style: outset;\n"
"border-width:2px;\n"
"border-color: rgb(132, 132, 132);\n"
"\n"
"font: 75 12pt \"Consolas\";\n"
"color: rgb(188, 93, 61);"));

        verticalLayout_2->addWidget(idLabel);

        timeLabel = new QLabel(Widget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        sizePolicy2.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy2);
        timeLabel->setMinimumSize(QSize(300, 40));
        timeLabel->setStyleSheet(QLatin1String("background-color:rgb(237, 237, 237);\n"
"border-style: outset;\n"
"border-width:2px;\n"
"border-color: rgb(132, 132, 132);\n"
"\n"
"\n"
"font: 75 12pt \"Consolas\";\n"
"color: rgb(188, 93, 61);"));

        verticalLayout_2->addWidget(timeLabel);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        commentTextEdit = new QTextEdit(Widget);
        commentTextEdit->setObjectName(QStringLiteral("commentTextEdit"));
        sizePolicy2.setHeightForWidth(commentTextEdit->sizePolicy().hasHeightForWidth());
        commentTextEdit->setSizePolicy(sizePolicy2);
        commentTextEdit->setMinimumSize(QSize(300, 121));
        commentTextEdit->setMaximumSize(QSize(16777215, 121));
        commentTextEdit->setStyleSheet(QLatin1String("\n"
"background-color: rgb(254, 254, 254);\n"
"border-style: outset;\n"
"border-width:2px;\n"
"border-color: rgb(132, 132, 132);"));

        horizontalLayout_2->addWidget(commentTextEdit);

        curAvatar = new QLabel(Widget);
        curAvatar->setObjectName(QStringLiteral("curAvatar"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(curAvatar->sizePolicy().hasHeightForWidth());
        curAvatar->setSizePolicy(sizePolicy3);
        curAvatar->setMinimumSize(QSize(121, 121));
        curAvatar->setMaximumSize(QSize(121, 16777215));
        curAvatar->setStyleSheet(QLatin1String("#curAvatar{\n"
"background-color:rgb(237, 237, 237);\n"
"border-style: outset;\n"
"border-width:2px;\n"
"border-color: rgb(132, 132, 132);\n"
"}"));

        horizontalLayout_2->addWidget(curAvatar);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        closeButton = new QPushButton(Widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy4);
        closeButton->setMinimumSize(QSize(150, 42));
        closeButton->setMaximumSize(QSize(161, 16777215));
        closeButton->setStyleSheet(QLatin1String("#closeButton{\n"
"	border-style: outset;\n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color:rgb(226, 255, 253);\n"
"	font:15px;\n"
"}\n"
"#closeButton:hover{\n"
"	border-radius: 15px;  \n"
"	border:2px groove gray;\n"
"	border-style: outset;\n"
"	color:rgb(255, 255, 255);\n"
"	background-color:rgb(255, 0, 0);\n"
"	font:25px;\n"
"}\n"
"#closeButton:pressed{\n"
"	border-style: outset;\n"
"	border-radius: 15px;  \n"
"	border: 2px groove gray;\n"
"	border-style: outset;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color:rgb(237, 237, 237);\n"
"	font:15px;\n"
"}"));

        verticalLayout_3->addWidget(closeButton);

        userAvatar = new QLabel(Widget);
        userAvatar->setObjectName(QStringLiteral("userAvatar"));
        sizePolicy3.setHeightForWidth(userAvatar->sizePolicy().hasHeightForWidth());
        userAvatar->setSizePolicy(sizePolicy3);
        userAvatar->setMinimumSize(QSize(161, 161));
        userAvatar->setMaximumSize(QSize(161, 16777215));
        userAvatar->setStyleSheet(QLatin1String("#userAvatar{\n"
"background-color:rgb(237, 237, 237);\n"
"border-style: outset;\n"
"border-width:2px;\n"
"border-color: rgb(132, 132, 132);\n"
"}\n"
"#userAvatar:hover{\n"
"background-color:rgb(237, 237, 237);\n"
"border-style: solid;\n"
"border-width:3px;\n"
"border-color: rgb(201, 255, 254);\n"
"}"));

        verticalLayout_3->addWidget(userAvatar);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalLayout_3->setStretch(0, 1);

        verticalLayout_5->addLayout(horizontalLayout_3);

        scrollArea = new QScrollArea(Widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(0, 400));
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new myPainterWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 588, 398));
        scrollAreaWidgetContents->setStyleSheet(QLatin1String("#scrollAreaWidgetContents{background-color: rgb(217, 217, 217);\n"
"border-style: outset;\n"
"border-width:2px;\n"
"border-color: rgb(132, 132, 132);\n"
"}"));
        currentFlag = new QLabel(scrollAreaWidgetContents);
        currentFlag->setObjectName(QStringLiteral("currentFlag"));
        currentFlag->setGeometry(QRect(70, 130, 60, 60));
        currentFlag->setStyleSheet(QLatin1String("#currentFlag:hover{border-style: outset;\n"
"border-radius: 15px;  \n"
"border: 2px groove gray;\n"
"border-style: outset;}"));
        currentFlag->setPixmap(QPixmap(QString::fromUtf8(":/images/img/flag.png")));
        currentFlag->setAlignment(Qt::AlignCenter);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalLayout_4->setStretch(1, 1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        restoreButton->setText(QString());
        freshButton->setText(QString());
        commitButton->setText(QString());

        const bool __sortingEnabled = workSpaceWidget->isSortingEnabled();
        workSpaceWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = workSpaceWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Widget", "+ asdasdasdaf", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = workSpaceWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Widget", "-  gkuhhvkhbu", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = workSpaceWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Widget", "*  sadasdasdsd", Q_NULLPTR));
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

        idLabel->setText(QString());
        timeLabel->setText(QString());
        curAvatar->setText(QString());
        closeButton->setText(QApplication::translate("Widget", "\344\270\213\347\217\255", Q_NULLPTR));
        userAvatar->setText(QString());
        currentFlag->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
