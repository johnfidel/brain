/**
* @file                     EventHandler.h
* @author                   RPi
* @date                     09.01.2016
* @brief                    This class is implemented in singleton pattern.
*                           It handles the interaction with events. Each
*                           Object has to register to this eventhandler.
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

#include "IOSystem/IOInterface.h"

namespace EVENTS
{

  class cEventHandler : public QObject
  {
      Q_OBJECT

    private:

      /// \brief this variable contains the instance
      static cEventHandler *m_pInstance;

      /// \brief private ctor to get an instance pointer
      explicit cEventHandler(QObject *parent = 0);

    public:

      /// \brief Function to get an instance
      static cEventHandler *Instance();

      /// \brief Register any thread to the Eventhandler
      bool RegisterEvent(EVENT::IEventInterface *pThread);
      bool RegisterEvent(QThread *pMainThread, EVENT::IEventInterface *pEvent);

    signals:

      /// \brief Signalizes events
      void Event(const EVENTS::cEvent &);

    public slots:

      /// \brief occures if an event of any thread is received
      void OnEvent(const EVENTS::cEvent &);

  };

}
