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

namespace SETTINGS {

    /// \brief this class stores the actual configuration of app
    class cAppConfig : public QObject
    {
      Q_OBJECT
      private:

        int m_LogLevel;

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
        int LogLevel() const { return m_LogLevel; }
        void LogLevel(const int loglevel) { m_LogLevel = loglevel; }

    };

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

    };

}
