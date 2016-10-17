/// \file <AppConfig.h>
///
/// Dieses Modul bietet ein Interface zu den Einstellungen der Masterbedienung
/// an.
///
//-----------------------------------------------------------------------------
//  Date        Who	Modification
//  ---------	---	-------------------------------------------------------
//  26.04.12    Pi	Writing initial version
//
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// included files
//-----------------------------------------------------------------------------
#include <QString>
#include <QObject>

#include "ModDefs.h"
#include "Settings/AppConfig.h"

namespace SETTINGS {


  /// \brief This class handles the read an write acces to configfile
  class cAppConfigReadWrite
  {

    private:

      /// \brief generic function to write or read a config parameter
      static QVariant config(QString section, QString key, QString def, QVariant value, bool write = false);

    public:

      /// \brief read or write LogLevel
      static int LogLevel();
      static void LogLevel(int value);

      /// \brief to read or write logoutput
      static int LogOutput();
      static void LogOutput(int value);

  };

  /// \brief this class stores the actual configuration of app
  class cAppConfig : public QObject
  {
    Q_OBJECT
    private:

      /// \brief stores the actual instance
      static cAppConfig *m_pInstance;

      /// \brief private ctor for singgleton
      explicit cAppConfig(QObject *parent = 0);

      /// \brief destructor
      ~cAppConfig();

    public:

      /// \brief to get an instance of Object
      static cAppConfig *Instance();

      /// \brief getter & Setter for m_LogLevel
      int LogLevel() const { return cAppConfigReadWrite::LogLevel(); }
      void LogLevel(const int loglevel) { cAppConfigReadWrite::LogLevel(loglevel); }

      int LogOutput() const { return cAppConfigReadWrite::LogOutput(); }
      void LogOutput(const int logoutput) { cAppConfigReadWrite::LogOutput(logoutput); }

  };
}
