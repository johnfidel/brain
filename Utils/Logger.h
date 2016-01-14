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

      /// \brief private ctor to get an instance pointer
      explicit cLogger(QObject *parent = 0);

      void LogMessage(const QString&);
    public:

      /// \brief Function to get an instance
      static cLogger *Instance();

      /// \brief set the logging output
      bool ConfigureLogger(const int config);

      /// \brief output some msg on logger
      cLogger& operator<<(QString);

    signals:

    public slots:

  };

}
