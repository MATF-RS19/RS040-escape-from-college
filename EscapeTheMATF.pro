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
        sources/main.cpp \
    sources/game.cpp \
    sources/wall.cpp \
    sources/door.cpp \
    sources/player.cpp \
    sources/exampaper.cpp \
    sources/tips.cpp \
    sources/score.cpp \
    sources/stairs.cpp \
    sources/profesor.cpp \
    sources/level1.cpp \
    sources/level2.cpp \
    sources/customize.cpp \
    sources/meni.cpp \
    sources/level3.cpp

HEADERS += \
    headers/customize.h \
    headers/door.h \
    headers/exampaper.h \
    headers/game.h \
    headers/level1.h \
    headers/level2.h \
    headers/meni.h \
    headers/player.h \
    headers/profesor.h \
    headers/score.h \
    headers/stairs.h \
    headers/tips.h \
    headers/wall.h \
    headers/level3.h

FORMS +=

RESOURCES += \
    res.qrc

DISTFILES += \
    1st.jpg
