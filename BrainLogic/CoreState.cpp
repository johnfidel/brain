#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QQueue>

#include "CoreState.h"
#include "IOSystem/Input/Console/TextReader.h"
#include "IOSystem/Input/InputInterface.h"
#include "EventHandler.h"
#include "BrainLogic/BrainObject.h"

//****************************************************************************
// private functions
//

//----------------------------------------------------------------------------
// Main function
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
        cBrainObject *obj = ne cBrainObject(event.m_text);

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

//----------------------------------------------------------------------------
// standard ctor
cCoreState::cCoreState(QObject *parent) :
  QThread(parent)
{
  // register event type once to metatypes
  qRegisterMetaType<EVENTS::cEvent>();

  // initialize mainstate
  m_eMainState = Idle;

  // create eventhandler and register its signal
  m_pEventHandler = EVENTS::cEventHandler::Instance();
  QObject::connect(m_pEventHandler, SIGNAL(Event(EVENTS::cEvent)), this, SLOT(OnEvent(EVENTS::cEvent)));

  // register threads to eventhandler
  m_pEventHandler->RegisterThread(&m_TextReader);

  // start threads
  m_TextReader.start();

  m_EventQueue = QQueue<EVENTS::cEvent>();

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// dtor
cCoreState::~cCoreState()
{

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// receives events
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
