#-------------------------------------------------
#
# Project created by QtCreator 2018-02-12T13:38:49
#
#-------------------------------------------------

QT       += core gui
QT 	 += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Zork_Qt_project
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


SOURCES += mainwindow.cpp\
        Character.cpp\
        Command.cpp\
        CommandWords.cpp\
        item.cpp\
        Parser.cpp\
        Room.cpp\
        ZorkUL.cpp \
    floor.cpp \
    zorkhome.cpp \
    newGame.cpp \
    carryableItem.cpp \
    searchableitem.cpp \
    key.cpp \
    settings.cpp \
    gameover.cpp



HEADERS  += mainwindow.h\
            Character.h\
            Command.h\
            CommandWords.h\
            item.h\
            parser.h\
            Room.h\
            ZorkUL.h \
    floor.h \
    zorkhome.h \
    newGame.h \
    carryableItem.h \
    searchableitem.h \
    key.h \
    settings.h \
    gameover.h

FORMS    += mainwindow.ui \
    newGame.ui \
    zorkhome.ui \
    settings.ui \
    gameover.ui

RESOURCES += \
    imglib.qrc
