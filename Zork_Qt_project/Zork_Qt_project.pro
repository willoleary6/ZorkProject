#-------------------------------------------------
#
# Project created by QtCreator 2018-02-12T13:38:49
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia


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
        item.cpp\
        Room.cpp\
        ZorkUL.cpp \
    floor.cpp \
    zorkhome.cpp \
    carryableItem.cpp \
    searchableitem.cpp \
    key.cpp \
    settings.cpp \
    gameover.cpp \
    leaderboard.cpp



HEADERS  += mainwindow.h\
            Character.h\
            Command.h\
            item.h\
            Room.h\
            ZorkUL.h \
    floor.h \
    zorkhome.h \
    carryableItem.h \
    searchableitem.h \
    key.h \
    settings.h \
    gameover.h \
    leaderboard.h

FORMS    += mainwindow.ui \
    zorkhome.ui \
    settings.ui \
    gameover.ui \
    leaderboard.ui

RESOURCES += \
    imglib.qrc
