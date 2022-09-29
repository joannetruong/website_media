#
# VLC-Qt Simple Player
# Copyright (C) 2015 Tadej Novak <tadej@tano.si>
#

TARGET      = simple-player
TEMPLATE    = app
#CONFIG 	   += c++11

QT         += widgets\
              network

SOURCES    += main.cpp \
    SimplePlayer.cpp

HEADERS    += SimplePlayer.h

FORMS      += SimplePlayer.ui

LIBS       += -llibVLCQtCored -llibVLCQtWidgetsd


# Edit below for custom library location
LIBS       += -LC:\Users\bec\Documents\VLC-Qt_1.1.0_win32_mingw\bin -llibVLCQtCored -llibVLCQtWidgetsd
INCLUDEPATH += C:\Users\bec\Documents\VLC-Qt_1.1.0_win32_mingw\include

RESOURCES += \
    resources.qrc
