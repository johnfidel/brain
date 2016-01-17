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

  class cEvent
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
       * \brief cEvent
       *        Standardconstructor
       */
      cEvent() {}

      /*!
       * \brief cEvent
       *        Copyconstructor
       * \param obj
       */
      cEvent(const cEvent& event)
      {
        *this = event;
      }

      /*!
       * \brief cEvent
       *        Special constructor
       * \param id
       * \param text
       */
      cEvent(const UserEventEnum id, QString text = "")
      {
        m_eUserEventId = id;
        m_text = QString(text);
      }

      /*!
       * \brief operator =
       *        Set operator
       * \param obj
       * \return
       */
      cEvent& operator=(const cEvent& obj)
      {
        m_eUserEventId = obj.m_eUserEventId;
        m_text = obj.m_text;
        return *this;
      }

      /// \brief Getter and Setter for local variables
      UserEventEnum UserEventId() const { return m_eUserEventId; }
      QString Text() const { return m_text; }

    signals:

    public slots:

  };

}

//Adding a Q_DECLARE_METATYPE() makes the type known to all template based functions, including QVariant.
//Note that if you intend to use the type in queued signal and slot connections or in QObject's property
//system, you also have to call qRegisterMetaType() since the names are resolved at runtime.
Q_DECLARE_METATYPE(EVENTS::cEvent)
