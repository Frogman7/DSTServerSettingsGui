#-------------------------------------------------
#
# Project created by QtCreator 2015-01-31T21:26:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DST_ServerEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    viewmodel.cpp

HEADERS  += mainwindow.h \
    viewmodel.h

FORMS    += mainwindow.ui

RESOURCES += qdarkstyle\style.qrc

RC_ICONS = dst_server_gui.ico

DISTFILES += \
    dst_server_gui_icon.ico
