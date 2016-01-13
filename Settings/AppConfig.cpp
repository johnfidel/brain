//-----------------------------------------------------------------------------
// included files
//-----------------------------------------------------------------------------
#include <QSettings>
#include <QString>

#include "GenDefs.h"
#include "AppConfig.h"
#include "AppConfig_Def.h"

//****************************************************************************
// private functions
//

///
/// \brief SETTINGS::cAppConfig::config
/// \param section
/// \param key
/// \param def
/// \param value
/// \param write
/// \return
///
QVariant SETTINGS::cAppConfig::config(QString section, QString key, QString def, QVariant value, bool write)
{
#ifdef DESKTOP
    QSettings app(QSettings::UserScope, ORGANISATION, APPLICATION_NAME);
#else
    QSettings app(QSettings::SystemScope, ORGANISATION, APPLICATION_NAME);
#endif

    if (write) {
        app.setValue(section + key, value);
        return "";
    }
    else {
        return app.value(section + key, def);
    }
}
//-----------------------------------------------------------------------------

//*****************************************************************************
// public functions
//

///
/// \brief SETTINGS::cAppConfig::Language
/// \return
///
int SETTINGS::cAppConfig::LogLevel()
{
    return config(CONFIGFILE_SETTINGS, CONFIGFILE_ACTUAL_LANGUAGE, DEFAULT_LANGUAGE, "").toString();
}
//-----------------------------------------------------------------------------

///
/// \brief SETTINGS::cAppConfig::Language
/// \param value
///
void SETTINGS::cAppConfig::LogLevel(int value)
{
    config(CONFIGFILE_SETTINGS, CONFIGFILE_ACTUAL_LANGUAGE, "", value, true);
}
//-----------------------------------------------------------------------------
