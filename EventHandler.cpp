#include "EventHandler.h"
#include "IOSystem/Input/InputInterface.h"

//*****************************************************************************
// Private functions
//

//-----------------------------------------------------------------------------
// constructor
EVENTS::cEventHandler::cEventHandler(QObject *parent) :
  QObject(parent)
{

}
//-----------------------------------------------------------------------------

//*****************************************************************************
// public functions

//-----------------------------------------------------------------------------
// to get an instance
EVENTS::cEventHandler* EVENTS::cEventHandler::m_pInstance= 0;
EVENTS::cEventHandler* EVENTS::cEventHandler::Instance()
{
  if (m_pInstance == 0)
  {
    m_pInstance = new EVENTS::cEventHandler();
  }
  return m_pInstance;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// this function register a thread to eventhandler
bool EVENTS::cEventHandler::RegisterThread(INPUT::cInputInterface *pThread)
{

  if (pThread != 0)
  {
    QObject::connect(pThread, SIGNAL(Event(EVENTS::cEvent)), this, SLOT(OnEvent(EVENTS::cEvent)));
  }

  return true;
}
//-----------------------------------------------------------------------------

//*****************************************************************************
// public slots

//-----------------------------------------------------------------------------
// transmit an event
void EVENTS::cEventHandler::OnEvent(const EVENTS::cEvent &event)
{
  emit Event(event);
}
//-----------------------------------------------------------------------------
