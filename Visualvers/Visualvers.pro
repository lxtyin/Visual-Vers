#-------------------------------------------------
#
# Project created by QtCreator 2022-05-27T20:51:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Visualvers
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES  -= UNICODE
DEFINES  += UMBCS

SOURCES += \
    main.cpp\
    Branch.cpp\
    command.cpp\
    CommitNodeButton.cpp\
    diffdialog.cpp\
    ModifyItem.cpp\
    myPainterWidget.cpp\
    Node.cpp\
    operator.cpp\
    widget.cpp\
    startdialog.cpp \
    contextmenu.cpp


HEADERS += \
    command.h\
    CommitNodeButton.h\
    Branch.h\
    widget.h\
    myPainterWidget.h\
    Node.h\
    ModifyItem.h\
    diffdialog.h\
    operator.h \
    startdialog.h \
    contextmenu.h


FORMS += \
    widget.ui\
    diffdialog.ui \
    startdialog.ui \
    contextmenu.ui


RESOURCES += \
    resource.qrc
