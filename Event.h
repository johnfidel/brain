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
#include <QList>

#include "BrainLogic/BrainObject.h"
#include "BrainLogic/BrainExperience.h"
#include "BrainLogic/BrainNeurone.h"

namespace EVENTS
{

  class cEvent
  {

    public:

      enum EventEnum
      {
        Event_Invalid = 0,
        Event_ConsoleInput,
        Event_BrainNeuroneFound,
      };

    private:

      /*!
       * \brief eUserEventId
       *        this field stores the ID of event
       */
      EventEnum m_eEventId;
      QString m_text;
      cBrainObject *m_pBrainObject;
      cBrainNeurone *m_pBrainNeurone;

    public:

      /*!
       * \brief initData
       *        Initialises every Member of class
       */
      void initData()
      {
         m_eEventId = (EventEnum)0;
         m_text = QString("");

         m_pBrainObject = NULL;
         m_pBrainNeurone = NULL;
      }

      /*!
       * \brief cEvent
       *        Standardconstructor
       */
      cEvent() {}

      /// \brief destruktor
      ~cEvent()
      {
        if (m_pBrainNeurone)
        {
          delete m_pBrainNeurone;
          m_pBrainNeurone = NULL;
        }
        if (m_pBrainObject)
        {
          delete m_pBrainObject;
          m_pBrainObject = NULL;
        }
      }

      /*!
       * \brief cEvent
       *        Copyconstructor
       * \param obj
       */
      cEvent(const cEvent& event)
      {
        initData();

        m_eEventId = event.m_eEventId;
        m_text = event.m_text;
        m_pBrainNeurone = event.BrainNeurone();
        m_pBrainObject = event.BrainObject();
      }

      /*!
       * \brief cEvent
       *        Special constructor
       * \param id
       * \param text
       */
      cEvent(const EventEnum id, QString text = "")
      {
        initData();

        m_eEventId = id;
        m_text = QString(text);
      }

      /*!
       * \brief cEvent
       * \param obj
       */
      cEvent(cBrainObject *pObj)
      {
        initData();

        m_eEventId = Event_BrainNeuroneFound;
        m_pBrainObject = pObj;
      }

      /*!
       * \brief cEvent
       * \param pNeurone
       */
      cEvent(cBrainNeurone *pNeurone)
      {
        initData();

        m_eEventId = Event_BrainNeuroneFound;
        m_pBrainNeurone = pNeurone;
      }

      /// \brief Getter and Setter for local variables
      EventEnum EventId() const { return m_eEventId; }
      QString Text() const { return m_text; }
      cBrainObject *BrainObject() const { return m_pBrainObject; }
      cBrainNeurone *BrainNeurone() const { return m_pBrainNeurone; }

    signals:

    public slots:

  };

}

//Adding a Q_DECLARE_METATYPE() makes the type known to all template based functions, including QVariant.
//Note that if you intend to use the type in queued signal and slot connections or in QObject's property
//system, you also have to call qRegisterMetaType() since the names are resolved at runtime.
Q_DECLARE_METATYPE(EVENTS::cEvent)
