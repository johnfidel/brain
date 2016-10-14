/**
* @file                     CoreState.h
* @author                   RPi
* @date                     04.01.2016
* @brief                    Main Thread of Brainlogic
*
*-------------------------------------------------------------------------------
* @verbatim
* Revisionhistory:
*
* Rev:  Datum:      Wer:        Was:
* ------------------------------------------------------------------------------
* V00   04.01.2016  rappic      Writing initial version
*
* @endverbatim
*-------------------------------------------------------------------------------
*/
#pragma once

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QQueue>

#include "Event.h"
#include "EventHandler.h"
#include "IOSystem/Input/Console/TextReader.h"
#include "IOSystem/Input/Eye/cEye.h"
#include "Settings/AppConfig.h"
#include "MemoryManager.h"
#ifdef USE_GUI
#include "View/MainView.h"
#include "View/MainViewModel.h"
#endif //USE_GUI

class cCoreState : public QThread
{
  Q_OBJECT

  private:

    /// \brief main enumaration for states
    enum CoreStateEnum
    {
      Idle = 0,
      HandleConsoleInput = 1
    };

    /// \brief stores the mainstate of core thread
    CoreStateEnum m_eMainState;

#ifdef USE_GUI
    MainWindow m_GUI;
    cMainViewModel *m_pMainViewModel;
#endif //USEGUI

    /// \brief mutex for thread safety
    QMutex m_Mutex;

    /// \brief stores every event
    QQueue<EVENTS::cEvent> m_EventQueue;

    /// \brief stores the app config class
    SETTINGS::cAppConfig *m_pAppConfig;

    /// \brief Event handler
    EVENTS::cEventHandler *m_pEventHandler;

    /// \brief memory Manager
    cMemoryManager *m_pMemoryManager;

    /// \brief Console input
    INPUT::cTextReader *m_pTextReader;

    /// \brief Eyes to look around
    INPUT::cEye *m_pEye;

    /// \brief Reimplementation of function run() of QThread
    void run();

  public:

    /// \brief standard ctor
    explicit cCoreState(QObject *parent = 0);

    /// \brief destructor
    ~cCoreState();

  signals:

    ///
    /// \brief Event
    ///
    void Event(const EVENTS::cEvent &);

  public slots:

    /// \brief receives events
    void OnEvent(const EVENTS::cEvent&);
};
