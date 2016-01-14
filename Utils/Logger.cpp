#include <QTextStream>
#include <QDebug>

#include "Utils/Logger.h"

//*****************************************************************************
// Private functions
//

///
/// \brief UTILS::cLogger::cLogger
/// \param parent
///
UTILS::cLogger::cLogger(QObject *parent) :
  QObject(parent), m_LoggerSettings((LoggerSettingsEnum)1)
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
  // logg to consoel
  if ((m_LoggerSettings & toDebugConsole) == toDebugConsole)
  {
    qDebug() << msg;
  }

  if ((m_LoggerSettings & toConsole) == toConsole)
  {
    QTextStream cout(stdout);
    cout << msg;
  }

  if ((m_LoggerSettings & toFile) == toFile)
  {
    // not yet implemented
  }

  if ((m_LoggerSettings & toSocket) == toSocket)
  {
    // not yet implemented
  }
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
/// \brief UTILS::cLogger::Logger
/// \return
///
UTILS::cLogger& UTILS::cLogger::Logger()
{
  return *Instance();
}
//-----------------------------------------------------------------------------

///
/// \brief UTILS::cLogger::ConfigureLogger
///
bool UTILS::cLogger::ConfigureLogger(const LoggerSettingsEnum settings)
{

  m_LoggerSettings = settings;

  return true;
}
//-----------------------------------------------------------------------------

///
/// \brief UTILS::cLogger::operator <<
/// \param in
/// \return
///
UTILS::cLogger& UTILS::cLogger::operator <<(const QString& in)
{
  LogMessage(in);
}
//-----------------------------------------------------------------------------

///
/// \brief UTILS::cLogger::operator <<
/// \param in
/// \return
///
UTILS::cLogger& UTILS::cLogger::operator <<(int in)
{
  LogMessage(QString::number(in));
}
//-----------------------------------------------------------------------------
