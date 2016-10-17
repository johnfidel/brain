#include "EventHandler.h"
#include "IOSystem/IOInterface.h"

//*****************************************************************************
// Private functions
//

///
/// \brief EVENTS::cEventHandler::cEventHandler
/// \param parent
///
EVENTS::cEventHandler::cEventHandler(QObject *parent) :
  QObject(parent)
{ }
//-----------------------------------------------------------------------------

//*****************************************************************************
// public functions

///
/// \brief EVENTS::cEventHandler::m_pInstance
///
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

///
/// \brief EVENTS::cEventHandler::RegisterThread
/// \param pThread
/// \return
///
bool EVENTS::cEventHandler::RegisterEvent(EVENT::IEventInterface *pEvent)
{

  if (pEvent != 0)
  {
    QObject::connect(dynamic_cast<QObject*>(pEvent), SIGNAL(Event(EVENTS::cEvent)),
                                                     this, SLOT(OnEvent(EVENTS::cEvent)));
    QObject::connect(this, SIGNAL(Event(EVENTS::cEvent)),
                      dynamic_cast<QObject*>(pEvent), SLOT(OnEvent(EVENTS::cEvent)));
  }

  return true;
}
//-----------------------------------------------------------------------------

//*****************************************************************************
// public slots

///
/// \brief EVENTS::cEventHandler::OnEvent
/// \param event
///
void EVENTS::cEventHandler::OnEvent(const EVENTS::cEvent &event)
{
  emit Event(event);
}
//-----------------------------------------------------------------------------
