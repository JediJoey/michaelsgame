TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        GameSource.cpp \
        display.cpp \
        game_controls.cpp \
        game_data.cpp \
        game_object.cpp \
        main.cpp

HEADERS += \
    display.h \
    game_controls.h \
    game_data.h \
    game_object.h
