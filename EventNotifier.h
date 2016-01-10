/**
* @file                     EventNotifier.cpp
* @author                   RPi
* @date                     09.01.2016
* @brief                    Class to define Userevents
*
*-------------------------------------------------------------------------------
* @verbatim
* Revisionhistory:
*
* Rev:  Datum:      Wer:        Was:
* ------------------------------------------------------------------------------
* V00   09.01.2016  rappic      Writing initial version
*
* @endverbatim
*-------------------------------------------------------------------------------
*/
#pragma once

#include <QObject>
#include <QThread>

namespace EVENTS
{

  class cEventNotifier
  {

    public:

      enum UserEventEnum
      {
        Invalid = 0,
        ConsoleInput
      };

    private:

      /*!
       * \brief eUserEventId
       *        this field stores the ID of event
       */
      UserEventEnum m_eUserEventId;
      QString m_text;

    public:

      /*!
       * \brief initData
       *        Initialises every Member of class
       */
      void initData()
      {
         m_eUserEventId = (UserEventEnum)0;
         m_text = QString("");
      }

      /*!
       * \brief cEventNotifier
       *        Standardconstructor
       */
      explicit cEventNotifier() {}

      /*!
       * \brief cEventNotifier
       *        Copyconstructor
       * \param obj
       */
      explicit cEventNotifier(const cEventNotifier &event)
      {
        *this = event;
      }

      explicit cEventNotifier(const UserEventEnum id, QString text = "")
      {
        m_eUserEventId = id;
        m_text = QString(text);
      }

      /*!
       * \brief UserEventId
       *        getter for m_eUserEventId
       * \return
       */
      UserEventEnum UserEventId() const { return m_eUserEventId; }

    signals:

    public slots:

  };

}

//Adding a Q_DECLARE_METATYPE() makes the type known to all template based functions, including QVariant.
//Note that if you intend to use the type in queued signal and slot connections or in QObject's property
//system, you also have to call qRegisterMetaType() since the names are resolved at runtime.
Q_DECLARE_METATYPE(EVENTS::cEventNotifier)
