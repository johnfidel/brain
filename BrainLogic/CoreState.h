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

#include "EventNotifier.h"
#include "EventHandler.h"
#include "IOSystem/Input/Console/TextReader.h"

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

    /// \brief mutex for thread safety
    QMutex m_Mutex;

    // Event handler
    EVENTS::cEventHandler *m_pEventHandler;

    // Console input
    INPUT::cTextReader m_TextReader;


    /*!
     * \brief run
     *        reimplements the run of QThread
     */
    void run();

  public:

    /*!
     * \brief cCoreState
     *        standard ctor
     * \param parent
     */
    explicit cCoreState(QObject *parent = 0);

    /// \brief destructor
    ~cCoreState();

  signals:

  public slots:

    /*!
     * \brief OnEvent
     *        receives events
     */
    void OnEvent(const EVENTS::cEventNotifier &);
};
