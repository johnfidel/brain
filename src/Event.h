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

      enum eMainEvent
      {
        MainEvent_None = 0,
        MainEvent_ConsoleInput,
        MainEvent_BrainNeuroneFound,
        MainEvent_Ears,
        MainEvent_Eyes,
      };

      enum eSubEventNone
      {
        SubEventNone_None = 0
      };

      enum eSubEventEars
      {
        SubEventEars_None = 0,
        SubEventEars_heared_something,
      };

      enum eSubEventEyes
      {
        SubEventEyes_None = 0,
        SubEventEyes_Seen_something,
      };

      union eSubEvent
      {
        eSubEventNone None;
        eSubEventEars Ears;
        eSubEventEyes Eyes;
      };

      struct tEvent
      {
        eMainEvent mainEvent;
        eSubEvent subEvent;
        tEvent()
        {
          mainEvent = (eMainEvent)0;
          subEvent.None = (eSubEventNone)0;
        }
        tEvent(eMainEvent main, int sub)
        {
          mainEvent = main;
          subEvent.None = (eSubEventNone)sub;
        }
        tEvent operator=(const tEvent other)
        {
          mainEvent = other.mainEvent;
          subEvent = other.subEvent;
          return *this;
        }
      };

    private:

      /*!
       * \brief eUserEventId
       *        this field stores the ID of event
       */
      tEvent m_EventId;
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
         m_EventId = tEvent();
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

        m_EventId = event.m_EventId;
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
      cEvent(const tEvent id, QString text = "")
      {
        initData();

        m_EventId = id;
        m_text = QString(text);
      }

      /*!
       * \brief cEvent
       * \param obj
       */
      cEvent(cBrainObject *pObj)
      {
        initData();

        m_EventId.mainEvent = MainEvent_BrainNeuroneFound;
        m_EventId.subEvent.None = SubEventNone_None;
        m_pBrainObject = pObj;
      }

      /*!
       * \brief cEvent
       * \param pNeurone
       */
      cEvent(cBrainNeurone *pNeurone)
      {
        initData();

        m_EventId.mainEvent = MainEvent_BrainNeuroneFound;
        m_EventId.subEvent.None = SubEventNone_None;
        m_pBrainNeurone = pNeurone;
      }

      /// \brief Getter and Setter for local variables
      tEvent EventId() const { return m_EventId; }
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
