#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>
#include <QtWebSockets/QWebSocketServer>
#include <QHostAddress>
#include <QtWebSockets/QWebSocket>

#include "Utils/Logger.h"

//*****************************************************************************
// Private functions
//

///
/// \brief UTILS::cLogger::cLogger
/// \param parent
///
UTILS::cLogger::cLogger(QObject *parent) :
  QObject(parent), m_LoggerSettings((LoggerSettingsEnum)1),
  m_SocketList()
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
    if (m_pServerSocket == 0)
    {
      m_pServerSocket = new QWebSocketServer(QCoreApplication::applicationName().append(QString(" logging service")),
                                              QWebSocketServer::NonSecureMode, this);

      if (m_pServerSocket->listen(QHostAddress::Any, 1234))
      {

      }
    }
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

  if ((m_LoggerSettings & toSocket) == toSocket)
  {
    // create socket connection
    if (m_pServerSocket == 0)
    {
      m_pServerSocket = new QWebSocketServer(QCoreApplication::applicationName().append(QString(" logging service")),
                                              QWebSocketServer::NonSecureMode, this);

      if (m_pServerSocket->listen(QHostAddress::Any, 1234))
      {
        QObject::connect(m_pServerSocket, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
      }
    }
  }

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

//*****************************************************************************
// private slots
//

///
/// \brief UTILS::cLogger::onNewConnection
///
void UTILS::cLogger::onNewConnection()
{
  QWebSocket *pSocket = m_pServerSocket->nextPendingConnection();

  QObject::connect(pSocket, SIGNAL(textMessageReceived(QString)), this, SLOT(processMessage(QString)));

  m_SocketList.append(pSocket);

}
//-----------------------------------------------------------------------------

///
/// \brief UTILS::cLogger::processMessage
/// \param message
///
void UTILS::cLogger::processMessage(QString message)
{

}
//-----------------------------------------------------------------------------

///
/// \brief UTILS::cLogger::socketDisconnected
///
void UTILS::cLogger::socketDisconnected()
{

}
//----------------------------------------------------------------------------
