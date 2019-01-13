#-------------------------------------------------
#
# Project created by QtCreator 2019-01-05T13:48:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EscapeTheMATF
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
    game.cpp \
    wall.cpp \
    door.cpp \
    player.cpp \
    exampaper.cpp \
    tips.cpp \
    score.cpp \
    stairs.cpp \
    profesor.cpp \
    level1.cpp \
    level2.cpp \
    customize.cpp \
    meni.cpp

HEADERS += \
    game.h \
    wall.h \
    door.h \
    player.h \
    exampaper.h \
    tips.h \
    score.h \
    stairs.h \
    profesor.h \
    level1.h \
    level2.h \
    customize.h \
    meni.h

FORMS +=

RESOURCES += \
    res.qrc

DISTFILES += \
    1st.jpg
