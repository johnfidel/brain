/**
* @file                     LogMessgage.h
* @author                   RPi
* @date                     17.01.2016
* @brief                    This class represents a LoggingMessage
*
*-------------------------------------------------------------------------------
* @verbatim
* Revisionhistory:
*
* Rev:  Datum:      Wer:        Was:
* ------------------------------------------------------------------------------
* V00   17.01.2016  rappic      Writing initial version
*
* @endverbatim
*-------------------------------------------------------------------------------
*/
#pragma once

#include <QObject>

namespace LOGGING
{

  /// \brief enum to declare the logginglevel
  enum LoggingLevel
  {
    LoggingLevelNone = 0,
    LoggingLevelInfo = 1,
    LoggingLevelVerbose = 2,
    LoggingLevelDebug = 3,
  };

  /// \brief this class represents a loggermessage
  class cLogMessage : public QObject
  {
      Q_OBJECT
    private:

      /// \brief stores the logglevel
      LoggingLevel m_loglevel;

      /// \brief stores the message
      QString m_Msg;

    public:

      /// \brief ctor
      explicit cLogMessage(QObject *parent = 0) :
        QObject(parent)
      {

      }

      /// \brief specific ctor
      explicit cLogMessage(const QString& msg, const LoggingLevel loglevel, QObject *parent = 0) :
        QObject(parent), m_loglevel(loglevel), m_Msg(msg) {}

      /// \brief dtor
      ~cLogMessage() {}

      /// \brief getter & Setter
      LoggingLevel LogLevel() const { return m_loglevel; }
      QString Message() const { return m_Msg; }

    signals:

    private slots:

  };

}
