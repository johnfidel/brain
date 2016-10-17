/**
* @file                     Logger.h
* @author                   RPi
* @date                     14.01.2016
* @brief                    This class handles the logging to different targets
*
*-------------------------------------------------------------------------------
* @verbatim
* Revisionhistory:
*
* Rev:  Datum:      Wer:        Was:
* ------------------------------------------------------------------------------
* V00   14.01.2016  rappic      Writing initial version
*
* @endverbatim
*-------------------------------------------------------------------------------
*/
#pragma once

#include <QObject>
#include <QtWebSockets/QtWebSockets>
#include <QtWebSockets/QWebSocketServer>

#include "Logging/LogMessage.h"

namespace LOGGING
{
  class cLogger : public QObject
  {
      Q_OBJECT
    public:

      /// \brief this enum defines the logging output
      enum LoggingOutput
      {
        LoggingOutputNone = 0,
        LoggingOutputToDebugConsole = 1,
        LoggingOutputToConsole = 2,
        LoggingOutputToFile = 4,
        LoggingOutputToSocket = 8
      };
      Q_DECLARE_FLAGS(LoggingOutputs, LoggingOutput);

    private:

      /// \brief this variable contains the instance
      static cLogger *m_pInstance;

      /// \brief stores the current loggingsetup
      LoggingOutputs m_LoggingOutput;

      /// \brief stores the current logginglevel
      LoggingLevel m_LoggingLevel;

      /// \bief opens a socketconnection for the listener
      QTcpServer *m_pServerSocket;

      /// \brief list of all connected sockets
      QList<QTcpSocket*> m_SocketList;

      /// \brief private ctor to get an instance pointer
      explicit cLogger(QObject *parent = 0);

      void LogMessage(const cLogMessage&);

    public:

      /// \brief Function to get an instance
      static cLogger *Instance();

      /// \brief destructor
      ~cLogger();

      /// \brief to access the logger
      static cLogger& Logger();

      /// \brief set the logging output
      bool ConfigureLogger(LoggingOutput config);
      bool ConfigureLogger(LoggingLevel config);

      /// \brief output some msg on logger
      void operator <<(const cLogMessage&);

    signals:

    private slots:

      /// \brief slot for Sockets handling
      void onNewConnection();
      void socketDisconnected();

  };
  Q_DECLARE_OPERATORS_FOR_FLAGS(cLogger::LoggingOutputs);

}
