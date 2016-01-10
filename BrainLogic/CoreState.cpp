#include <QDebug>
#include <QObject>
#include <QTimer>

#include "CoreState.h"
#include "IOSystem/Input/Console/TextReader.h"
#include "IOSystem/Input/InputInterface.h"
#include "EventHandler.h"

//****************************************************************************
// private functions
//

//----------------------------------------------------------------------------
// Main function
void cCoreState::run()
{
  CoreStateEnum state = (CoreStateEnum)0;

  while (isRunning())
  {
    QThread::msleep(20);

    m_Mutex.lock();
    state = m_eMainState;
    m_Mutex.unlock();

    switch (state)
    {

      case Idle:
      {

        break;
      }

      case HandleConsoleInput:
      {
        int i = 0;

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
  qRegisterMetaType<EVENTS::cEventNotifier>();

  // initialize mainstate
  m_eMainState = Idle;

  // create eventhandler and register its signal
  m_pEventHandler = EVENTS::cEventHandler::Instance();
  QObject::connect(m_pEventHandler, SIGNAL(Event(EVENTS::cEventNotifier)), this, SLOT(OnEvent(EVENTS::cEventNotifier)));

  // register threads to eventhandler
  m_pEventHandler->RegisterThread(&m_TextReader);

  // start threads
  m_TextReader.start();

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
void cCoreState::OnEvent(const EVENTS::cEventNotifier &event)
{

  // evaluate received event
  switch (event.UserEventId())
  {

    case EVENTS::cEventNotifier::ConsoleInput:
    {
      m_Mutex.lock();
      m_eMainState = HandleConsoleInput;
      m_Mutex.unlock();
    }

    default:
    {
      // do nothing
    }
  } // case (event.m_eUserEventId)


}
//----------------------------------------------------------------------------
