QT += core
QT += multimedia
QT -= gui

TARGET = brain
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    BrainLogic/BrainObject.cpp \
    Input/Eye/WebCam/WebCam.cpp \
    BrainLogic/CoreState.cpp \
    Utils/JsonSerializer.cpp \
    Input/Console/TextReader.cpp

HEADERS += \
    gendefs.h \
    BrainLogic/BrainObject.h \
    Input/Eye/WebCam/WebCam.h \
    BrainLogic/CoreState.h \
    Utils/JsonSerializer.h \
    Input/Console/TextReader.h

