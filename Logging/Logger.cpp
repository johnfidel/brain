#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTextStream>

#include "Logging/Logger.h"

namespace LOGGING
{

  //*****************************************************************************
  // Private functions
  //

  ///
  /// \brief cLogger::cLogger
  /// \param parent
  ///
  cLogger::cLogger(QObject *parent) :
    QObject(parent), m_LoggingOutput((LoggingOutput)1),
    m_pServerSocket(0), m_SocketList()
  {

  }
  //-----------------------------------------------------------------------------

  ///
  /// \brief LogMessage
  ///       Outputs the message on the specified output
  /// \param msg
  ///
  void cLogger::LogMessage(const cLogMessage& msg)
  {
    // check if message is in the currently configured loglevel
    if (msg.LogLevel() <= m_LoggingLevel)
    {

      // logg to consoel
      if ((m_LoggingOutput & LoggingOutputToDebugConsole) == LoggingOutputToDebugConsole)
      {
        qDebug() << msg.Message();
      }

      if ((m_LoggingOutput & LoggingOutputToConsole) == LoggingOutputToConsole)
      {
        QTextStream cout(stdout);
        cout << msg.Message();
      }

      if ((m_LoggingOutput & LoggingOutputToFile) == LoggingOutputToFile)
      {
        // not yet implemented
      }

      if ((m_LoggingOutput & LoggingOutputToSocket) == LoggingOutputToSocket)
      {
        if (m_pServerSocket != 0)
        {
          foreach (QTcpSocket *sock, m_SocketList)
          {
            QByteArray array;
            array.append(msg.Message());
            array.append("\r\n");
            sock->write(array);
            sock->flush();
          } // foreach

        } // if (m_pServerSocket != 0)

      } // if ((loggingOutput & LoggingOutputToSocket) == LoggingOutputToSocket)

    }// if (msg_LogLeve() <= m_LoggingLevel)

  } // void cLogger::LogMessage()
  //-----------------------------------------------------------------------------


  //*****************************************************************************
  // public functions

  ///
  /// \brief cLogger::m_pInstance
  ///
  cLogger* cLogger::m_pInstance= 0;
  cLogger* cLogger::Instance()
  {
    if (m_pInstance == 0)
    {
      m_pInstance = new LOGGING::cLogger();
    }
    return m_pInstance;
  }
  //-----------------------------------------------------------------------------

  ///
  /// \brief cLogger::~cLogger
  ///
  cLogger::~cLogger()
  {
    foreach (QTcpSocket *sock, m_SocketList)
    {
      delete sock;
    }
    if (m_pServerSocket != 0)
    {
      delete m_pServerSocket;
      m_pServerSocket = 0;
    }
    if (m_pInstance != 0)
    {
      delete m_pInstance;
      m_pInstance = 0;
    }
  }
  //-----------------------------------------------------------------------------

  ///
  /// \brief cLogger::Logger
  /// \return
  ///
  cLogger& cLogger::Logger()
  {
    return *Instance();
  }
  //-----------------------------------------------------------------------------

  ///
  /// \brief cLogger::ConfigureLogger
  ///
  bool cLogger::ConfigureLogger(LoggingOutput settings)
  {

    m_LoggingOutput = settings;

    if ((m_LoggingOutput & LoggingOutputToSocket) == LoggingOutputToSocket)
    {
      // create socket connection
      if (m_pServerSocket == 0)
      {
        m_pServerSocket = new QTcpServer(this);

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
  /// \brief cLogger::ConfigureLogger
  /// \param config
  /// \return
  ///
  bool cLogger::ConfigureLogger(LoggingLevel config)
  {
    m_LoggingLevel = config;
  }
  //-----------------------------------------------------------------------------

  ///
  /// \brief cLogger::operator <<
  /// \param in
  /// \return
  ///
  void cLogger::operator <<(const cLogMessage& in)
  {
    LogMessage(in);
  }
  //-----------------------------------------------------------------------------

  //*****************************************************************************
  // private slots
  //

  ///
  /// \brief cLogger::onNewConnection
  ///
  void cLogger::onNewConnection()
  {
    // create websocket
    QTcpSocket *pSocket = m_pServerSocket->nextPendingConnection();

    // connect disconnect signal
    QObject::connect(pSocket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));

    // add socket to socketlist
    m_SocketList << pSocket;

  }
  //-----------------------------------------------------------------------------

  ///
  /// \brief cLogger::socketDisconnected
  ///
  void cLogger::socketDisconnected()
  {

  }
  //----------------------------------------------------------------------------

} // namespace LOGGING
