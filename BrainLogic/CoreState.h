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
#include "Settings/AppConfig.h"
#include "MemoryManager.h"

class cCoreState : public QThread
{
  Q_OBJECT

  private:

    /// \brief main enumaration for states
    enum CoreStateEnum
    {
      CoreState_Idle = 0,
      CoreState_Input,
      CoreState_Output
    };

    /// \brief stores the mainstate of core thread
    CoreStateEnum m_eMainState;

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
    INPUT::cTextReader m_TextReader;

    /// \brief Reimplementation of function run() of QThread
    void run();

  public:

    /// \brief standard ctor
    explicit cCoreState(QObject *parent = 0);

    /// \brief destructor
    ~cCoreState();

  signals:

  public slots:

    /// \brief receives events
    void OnEvent(const EVENTS::cEvent&);
};
