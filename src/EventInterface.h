/**

* @file                     EventInterface.h
* @author                   RPi
* @date                     09.01.2016
* @brief                    This interface describes an base Event
*
*-------------------------------------------------------------------------------
*/

#pragma once

#include <QObject>

#include "Event.h"

namespace EVENT
{
  class IEventInterface
  {
    private:

    protected:

    signals:

      /*!
       * \brief UserEvent
       *        This Function is used to signalize events
       * \param event
       */
      virtual void Event(const EVENTS::cEvent &) = 0;

    public slots:

      /*!
       * \brief OnEvent
       *        This Function is to receive Events
       */
      virtual void OnEvent(const EVENTS::cEvent &) = 0;

  };

} // namespace EVENT
Q_DECLARE_INTERFACE(EVENT::IEventInterface, "EVENT::IEventInterface")
