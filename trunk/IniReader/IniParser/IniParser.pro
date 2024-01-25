#-------------------------------------------------
#
# Project created by QtCreator 2024-01-05T10:45:47
#
#-------------------------------------------------

QT       -= gui

TARGET = IniParser
TEMPLATE = lib

DEFINES += INIPARSER_LIBRARY

SOURCES += IniParser.cpp \
    ini.c

HEADERS += IniParser.h\
        iniparser_global.h \
    ini.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

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
