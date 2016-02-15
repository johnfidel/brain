#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QQueue>

#include "CoreState.h"
#include "IOSystem/Input/Console/TextReader.h"
#include "IOSystem/IOInterface.h"
#include "EventHandler.h"
#include "BrainLogic/BrainObject.h"
#include "Utils/JsonSerializer.h"
#include "Logging/Logger.h"
#include "EventHandler.h"

//****************************************************************************
// private functions
//

/*!
 * \brief cCoreState::run
 */
void cCoreState::run()
{
  CoreStateEnum state = (CoreStateEnum)0;
  EVENTS::cEvent event;

  // log programstard
  LOGGING::cLogger::Logger() << LOGGING::cLogMessage("Enter cCoreState thread", LOGGING::LoggingLevelVerbose);

  while (isRunning())
  {
    QThread::msleep(20);

    m_Mutex.lock();
    state = m_eMainState;
    if (!m_EventQueue.isEmpty())
    {
      // read out event from queue
      event = m_EventQueue.dequeue();
    }
    m_Mutex.unlock();

    switch (state)
    {

      case CoreState_Idle:
      {

        // we have nothing to do... lets memorymanager
        // do some sorting in our memory
        m_pMemoryManager->ManageMemory();

        break;
      }

      case CoreState_Input:
      {
        // log incoming input
        LOGGING::cLogger::Logger() << LOGGING::cLogMessage("Console input received", LOGGING::LoggingLevelVerbose);

        // parse memory
        m_pMemoryManager->SearchInMemory(event.Text());

        // Create new memoryentry if neccessairy
        m_pMemoryManager->AddToMemory(event.Text());

        break;
      }

      case CoreState_Output:
      {        
        if (event.BrainNeurone())
        {
          QTextStream out(stdout);

          foreach (cBrainExperience *pExp, event.BrainNeurone()->BrainExperiences())
          {
            out << pExp->Experience();
          }
          foreach (cBrainObject *pObj, event.BrainNeurone()->BrainObjects())
          {
            out << pObj->Name();
          }
        }

        break;
      }

      default:
      {

      }
    } /* switch (m_MainState); */

    m_Mutex.lock();
    m_eMainState = CoreState_Idle;
    m_Mutex.unlock();

  } // while() /*
}
//----------------------------------------------------------------------------

//****************************************************************************
// public functions
//

/*!
 * \brief cCoreState::cCoreState
 * \param parent
 */
cCoreState::cCoreState(QObject *parent) :
  QThread(parent)
{
  // register event type once to metatypes
  qRegisterMetaType<EVENTS::cEvent>();

  // initialize mainstate
  m_eMainState = CoreState_Idle;

  //Appconfig
  m_pAppConfig = SETTINGS::cAppConfig::Instance();

  // create eventhandler and register its signal
  m_pEventHandler = EVENTS::cEventHandler::Instance();
  QObject::connect(m_pEventHandler, SIGNAL(Event(EVENTS::cEvent)), this, SLOT(OnEvent(EVENTS::cEvent)));

  // create memorymanager
  m_pMemoryManager = cMemoryManager::Instance();

  // register IO threads to eventhandler
  m_pEventHandler->RegisterEvent(&m_TextReader);

  // start IO threads
  m_TextReader.start();

  // register memorymanager to eventhandler
  m_pEventHandler->RegisterEvent(m_pMemoryManager);

  // init Event queue
  m_EventQueue = QQueue<EVENTS::cEvent>();

}
//----------------------------------------------------------------------------

/*!
 * \brief cCoreState::~cCoreState
 */
cCoreState::~cCoreState()
{

}
//----------------------------------------------------------------------------

/*!
 * \brief cCoreState::OnEvent
 * \param event
 */
void cCoreState::OnEvent(const EVENTS::cEvent &event)
{

  // evaluate received event
  switch (event.EventId())
  {

    case EVENTS::cEvent::Event_ConsoleInput:
    {
      m_Mutex.lock();
      m_eMainState = CoreState_Input;
      m_EventQueue.enqueue(EVENTS::cEvent(event));
      m_Mutex.unlock();

      break;
    }

    case EVENTS::cEvent::Event_BrainNeuroneFound:
    {
      m_Mutex.lock();
      m_eMainState = CoreState_Output;
      m_EventQueue.enqueue(EVENTS::cEvent(event));
      m_Mutex.unlock();

      break;
    }

    default:
    {
      // do nothing
    }
  } // case (event.m_eUserEventId)


}
//----------------------------------------------------------------------------
