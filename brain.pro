QT += core gui
QT += multimedia multimediawidgets
QT += network
QT += websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = brain
CONFIG -= app_bundle
CONFIG += console

TEMPLATE = app

SOURCES += main.cpp \
    BrainLogic/BrainObject.cpp \
    BrainLogic/CoreState.cpp \
    BrainLogic/MemoryManager.cpp \
\
    IOSystem/Input/Console/TextReader.cpp \
\
    Drivers/WebCam/WebCam.cpp \
\
    Logging/Logger.cpp \
\
    Utils/JsonSerializer.cpp \
\
    Settings/AppConfig.cpp \
    EventHandler.cpp \
    View/MainView.cpp \
    View/MainViewModel.cpp \
    IOSystem/Input/Eye/cEye.cpp

HEADERS += \
    BrainLogic/BrainObject.h \
    BrainLogic/CoreState.h \
    BrainLogic/MemoryManager.h \
\
    IOSystem/Input/Console/TextReader.h \
    IOSystem/Input/InputInterface.h \
\
    Drivers/WebCam/WebCam.h \
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
    ModDefs.h \
    View/MainView.h \
    View/MainViewModel.h \
    IOSystem/Input/Eye/cEye.h

DISTFILES += \
    qtbuild

FORMS += \
    View/MainWindow.ui

