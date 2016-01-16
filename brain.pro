QT += core
QT += multimedia
QT -= gui
QT += network
QT += websockets

TARGET = brain
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    BrainLogic/BrainObject.cpp \
    IOSystem/Input/Eye/WebCam/WebCam.cpp \
    BrainLogic/CoreState.cpp \
    Utils/JsonSerializer.cpp \
    IOSystem/Input/Console/TextReader.cpp \
    EventHandler.cpp \
    BrainLogic/MemoryManager.cpp \
    Settings/AppConfig.cpp \
    Utils/Logger.cpp

HEADERS += \
    BrainLogic/BrainObject.h \
    IOSystem/Input/Eye/WebCam/WebCam.h \
    BrainLogic/CoreState.h \
    Utils/JsonSerializer.h \
    IOSystem/Input/Console/TextReader.h \
    GenDefs.h \
    IOSystem/Input/InputInterface.h \
    EventHandler.h \
    BrainLogic/MemoryManager.h \
    Event.h \
    Settings/AppConfig.h \
    Settings/AppConfig_Def.h \
    ModDefs.h \
    Utils/Logger.h

DISTFILES +=

