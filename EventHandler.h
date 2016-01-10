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

#include "IOSystem/Input/InputInterface.h"

namespace EVENTS
{

  class cEventHandler : public QObject
  {
      Q_OBJECT

    private:

      /*!
       * \brief m_pInstance
       * This member stores the instance of class
       */
      static cEventHandler *m_pInstance;

      /*!
       * \brief cEventHandler
       *        standard ctro
       * \param parent
       */
      cEventHandler(QObject *parent = 0);

    public:

      /*!
       * \brief Instance
       *        To get an instance of the class
       * \return
       */
      static cEventHandler *Instance();

      /*!
       * \brief RegisterThread
       *        This function registers a thread to eventhandler
       * \param thread
       * \return
       */
      bool RegisterThread(INPUT::cInputInterface *pThread);

    signals:

      /*!
       * \brief Event
       *        transmits an event
       */
      void Event(const EVENTS::cEventNotifier &);

    public slots:

      /*!
       * \brief OnEvent
       *        Slot to receive an event
       * \param event
       */
      void OnEvent(const EVENTS::cEventNotifier &event);

  };

}
