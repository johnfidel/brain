/**

* @file                     InputInterface.h
* @author                   RPi
* @date                     09.01.2016
* @brief                    This interface defines the base Interface for a
*                           Input
*
*-------------------------------------------------------------------------------
* @verbatim
* Revisionsverzeichnis:
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

#include "EventNotifier.h"

namespace INPUT
{

  class cInputInterface : public QThread
  {
    Q_OBJECT

    private:

    protected:

      /*!
       * \brief cInputInterface
       *        standardconstructor
       */
      explicit cInputInterface(QObject *parent = 0) : QThread(parent) {}

      /*!
       * \brief run
       *        Main function of thread
       */
      virtual void run() {}

    signals:

      /*!
       * \brief UserEvent
       *        This Function is used to signalize events
       * \param event
       */
      void Event(const EVENTS::cEventNotifier &);

    public slots:

  };

} // namespace INPUT
