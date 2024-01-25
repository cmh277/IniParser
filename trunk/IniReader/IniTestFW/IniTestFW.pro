QT += core
QT -= gui

CONFIG += c++11

TARGET = IniTestFW
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    TestIni.cpp

HEADERS += \
    TestIni.h

#生成路径修改，将可执行文件统一放到bin目录下
win32{
    CONFIG(debug, debug | release)
    {
        DESTDIR = $$PWD/../WorkSpace/debug/
    }
    CONFIG(release, debug | release)
    {
        DESTDIR = $$PWD/../WorkSpace/release/
    }
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../WorkSpace/release/ -lIniParser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../WorkSpace/debug/ -lIniParser

INCLUDEPATH += $$PWD/../IniParser
DEPENDPATH += $$PWD/../IniParser
