#-------------------------------------------------
#
# Project created by QtCreator 2018-09-07T10:34:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hreducer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        hreducer.cpp \
    login.cpp \
    logindialog.cpp

HEADERS += \
        hreducer.h \
    login.h \
    logindialog.h

FORMS += \
        hreducer.ui \
    login.ui

DEFINES += QT_DLL QWT_DLL
LIBS += -L"D:\Softwares\Qt\5.11.1\mingw53_32\lib" -lqwtd
LIBS += -L"D:\Softwares\Qt\5.11.1\mingw53_32\lib" -lqwt
INCLUDEPATH += D:\Softwares\Qt\5.11.1\mingw53_32\include\Qwt

RESOURCES += \
    images.qrc
