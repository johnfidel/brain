QT += core gui
QT += multimedia multimediawidgets
QT += network
QT += websockets
QT += charts widgets
QT += texttospeech

INCLUDEPATH+=tools/build-qtspeech/include/QtTextToSpeech

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = brain
CONFIG -= app_bundle
CONFIG += console

TEMPLATE = app

SOURCES += main.cpp \
    BrainLogic/BrainObject.cpp \
    BrainLogic/CoreState.cpp \
    BrainLogic/MemoryManager.cpp \
    BrainLogic/BrainNeurone.cpp \
    BrainLogic/BrainExperience.cpp \
\
    IOSystem/Input/Console/TextReader.cpp \
    IOSystem/Input/Ears/Ears.cpp \
    IOSystem/Input/Eyes/Eyes.cpp \
    IOSystem/Output/Console/TextWriter.cpp \
\
    Drivers/WebCam/WebCam.cpp \
    Drivers/Audio/AudioFileHandler.cpp \
\
    Logging/Logger.cpp \
\
    Utils/JsonSerializer.cpp \
\
    Settings/AppConfig.cpp \
    EventHandler.cpp \
    View/MainView.cpp \
    View/MainViewModel.cpp \
    View/EarsWidget.cpp

HEADERS += \
    BrainLogic/BrainObject.h \
    BrainLogic/CoreState.h \
    BrainLogic/MemoryManager.h \
    BrainLogic/BrainNeurone.h \
    BrainLogic/BrainExperience.h \
    BrainLogic/MemoryManager_Def.h \
\
    IOSystem/Input/Console/TextReader.h \
    IOSystem/Input/Ears/Ears.h \
    IOSystem/Input/Eyes/Eyes.h \
    IOSystem/Output/Console/TextWriter.h \
    IOSystem/IOInterface.h \
\
    Drivers/WebCam/WebCam.h \
    Drivers/Audio/AudioFileHandler.h \
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
    EventInterface.h \
    Event.h \
    ModDefs.h \
    View/MainView.h \
    View/MainViewModel.h \
    View/EarsWidget.h

DISTFILES += \
    qtbuild

FORMS += \
    View/MainWindow.ui

