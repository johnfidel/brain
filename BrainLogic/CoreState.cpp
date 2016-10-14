#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QQueue>

#include "CoreState.h"
#include "IOSystem/Input/Console/TextReader.h"
#include "IOSystem/Input/InputInterface.h"
#include "EventHandler.h"
#include "BrainLogic/BrainObject.h"
#include "Utils/JsonSerializer.h"
#include "Logging/Logger.h"

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

      case Idle:
      {

        break;
      }

      case HandleConsoleInput:
      {
        // log incoming input
        LOGGING::cLogger::Logger() << LOGGING::cLogMessage("Console input received", LOGGING::LoggingLevelInfo);

        cBrainObject *pObj = new cBrainObject(event.Text());
        m_pMemoryManager->AddToMemory(*pObj);
        cJsonSerializer::QJsonToFile(pObj->toJson(), pObj->TimeStamp().toString("YYYYMMDD_hhmmss"));

        break;
      }

      default:
      {

      }

    } /* switch (m_MainState); */
  }

  m_Mutex.lock();
  m_eMainState = Idle;
  m_Mutex.unlock();

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
  m_eMainState = Idle;

  //Appconfig
  m_pAppConfig = SETTINGS::cAppConfig::Instance();

  // create eventhandler and register its signal
  m_pEventHandler = EVENTS::cEventHandler::Instance();
  QObject::connect(m_pEventHandler, SIGNAL(Event(EVENTS::cEvent)), this, SLOT(OnEvent(EVENTS::cEvent)));

  // create memorymanager
  m_pMemoryManager = cMemoryManager::Instance();

  // register threads to eventhandler
  m_pEventHandler->RegisterThread(&m_TextReader);
  m_pEventHandler->RegisterThread(&m_Ears);

  // start threads
  m_TextReader.start();
  m_Ears.start();

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
  switch (event.UserEventId())
  {

    case EVENTS::cEvent::ConsoleInput:
    {
      m_Mutex.lock();
      m_eMainState = HandleConsoleInput;
      m_EventQueue.enqueue(EVENTS::cEvent(event));
      m_Mutex.unlock();
    }

    default:
    {
      // do nothing
    }
  } // case (event.m_eUserEventId)


}
//----------------------------------------------------------------------------
