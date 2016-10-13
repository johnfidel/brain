QT += core
QT += multimedia multimediawidgets
QT -= gui
QT += network
QT += websockets

TARGET = brain
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += /usr/lib/x86_64-linux-gnu/gstreamer-1.0/

TEMPLATE = app

SOURCES += main.cpp \
    BrainLogic/BrainObject.cpp \
    BrainLogic/CoreState.cpp \
    BrainLogic/MemoryManager.cpp \
\
    IOSystem/Input/Eye/WebCam/WebCam.cpp \
    IOSystem/Input/Console/TextReader.cpp \
\
    Logging/Logger.cpp \
\
    Utils/JsonSerializer.cpp \
\
    Settings/AppConfig.cpp \
    EventHandler.cpp

HEADERS += \
    BrainLogic/BrainObject.h \
    BrainLogic/CoreState.h \
    BrainLogic/MemoryManager.h \
\
    IOSystem/Input/Eye/WebCam/WebCam.h \
    IOSystem/Input/Console/TextReader.h \
    IOSystem/Input/InputInterface.h \
\
    Logging/Logger.h \
    Logging/LogMessage.h \
\
    Utils/JsonSerializer.h \
\
    Settings/AppConfig.h \
    Settings/AppConfig_Def.h \
\
    GenDefs.h \
    EventHandler.h \
    Event.h \
    ModDefs.h

DISTFILES += \
    qtbuild

