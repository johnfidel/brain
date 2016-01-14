#include "Utils/Logger.h"

//*****************************************************************************
// Private functions
//

///
/// \brief UTILS::cLogger::cLogger
/// \param parent
///
UTILS::cLogger::cLogger(QObject *parent) :
  QObject(parent), m_LoggerSettings((LoggerSettingsEnum)0)
{

}
//-----------------------------------------------------------------------------

///
/// \brief LogMessage
///       Outputs the message on the specified output
/// \param msg
///
void UTILS::cLogger::LogMessage(const QString& msg)
{
  //if (m_LoggerSettings & LoggerSettingsEnum::)
}
//-----------------------------------------------------------------------------


//*****************************************************************************
// public functions

///
/// \brief UTILS::cLogger::m_pInstance
///
UTILS::cLogger* UTILS::cLogger::m_pInstance= 0;
UTILS::cLogger* UTILS::cLogger::Instance()
{
  if (m_pInstance == 0)
  {
    m_pInstance = new UTILS::cLogger();
  }
  return m_pInstance;
}
//-----------------------------------------------------------------------------

///
/// \brief UTILS::cLogger::ConfigureLogger
///
bool UTILS::cLogger::ConfigureLogger(const int settings)
{

  m_LoggerSettings = settings;

  return true;
}
//-----------------------------------------------------------------------------

UTILS::cLogger& UTILS::cLogger::operator<<(QString in)
{
  LogMessage(in);
}
