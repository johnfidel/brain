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

#include "IOSystem/Input/InputInterface.h"

namespace UTILS
{

  class cLogger : public QObject
  {
      Q_OBJECT

    public:

      /// \brief this enum defines the logging output
      enum LoggerSettingsEnum
      {
        none = 0,
        toDebugConsole = 1,
        toConsole = 2,
        toFile = 4,
        toSocket = 8
      };

    private:

      /// \brief this variable contains the instance
      static cLogger *m_pInstance;

      /// \brief stores the current loggingsetup
      int m_LoggerSettings;

      /// \bief opens a socketconnection for the listener
      QWebSocketServer *m_pServerSocket;

      /// \brief list of all connected sockets
      QList<QWebSocket*> m_SocketList;

      /// \brief private ctor to get an instance pointer
      explicit cLogger(QObject *parent = 0);

      void LogMessage(const QString&);
    public:

      /// \brief Function to get an instance
      static cLogger *Instance();

      /// \brief to access the logger
      static cLogger& Logger();

      /// \brief set the logging output
      bool ConfigureLogger(const LoggerSettingsEnum config);

      /// \brief output some msg on logger
      cLogger& operator <<(const QString&);
      cLogger& operator <<(int);

    signals:

    private slots:

      /// \brief slot for Sockets handling
      void onNewConnection();
      void processMessage(QString message);
      void socketDisconnected();

  };

}
