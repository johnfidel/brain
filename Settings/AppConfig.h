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

#include "ModDefs.h"

namespace SETTINGS {

    /// \brief Statische Klasse für das Managen der MB Einstellungen
    class cAppConfig
    {

    private:

        /// \brief generische funktion um einen configurationswert zu lesen oder schreiben
        static QVariant config(QString section, QString key, QString def, QVariant value, bool write = false);

    public:

        /// \brief Liest den Loglevel ein oder speichert ihn
        static int LogLevel();
        static void LogLevel(int value);

    };

}
