/**

* @file                     IOInterface.h
* @author                   RPi
* @date                     09.01.2016
* @brief                    This interface defines the base Interface for a
*                           IO System
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

#include "Event.h"
#include "EventInterface.h"

class cIOInterface : public QThread, public EVENT::IEventInterface
{
  Q_OBJECT
  Q_INTERFACES(EVENT::IEventInterface)

  private:

  protected:

    /*!
     * \brief cInputInterface
     *        standardconstructor
     */
    explicit cIOInterface(QObject *parent = 0) : QThread(parent) {}

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
    void Event(const EVENTS::cEvent &);

  public slots:

    /*!
     * \brief OnEvent
     */
    virtual void OnEvent(const EVENTS::cEvent &) {}

};
