//-----------------------------------------------------------------------------
// included files
//-----------------------------------------------------------------------------
#include <QSettings>
#include <QString>
#include <QObject>

#include "GenDefs.h"
#include "AppConfig.h"
#include "AppConfig_Def.h"

//****************************************************************************
//****************************************************************************
// class cAppConfig
//

//****************************************************************************
// private function
//

///
/// \brief cAppConfig
/// \param parent
///
SETTINGS::cAppConfig::cAppConfig(QObject *parent) :
  QObject(parent)
{

}
//----------------------------------------------------------------------------

///
/// \brief SETTINGS::cAppConfig::~cAppConfig
///
SETTINGS::cAppConfig::~cAppConfig()
{
  if (m_pInstance != 0)
  {
    delete m_pInstance;
    m_pInstance = 0;
  }
}
//----------------------------------------------------------------------------

//****************************************************************************
// public function
//

///
/// \brief SETTINGS::cAppConfig::m_pInstance
///
SETTINGS::cAppConfig *SETTINGS::cAppConfig::m_pInstance = 0;
SETTINGS::cAppConfig *SETTINGS::cAppConfig::Instance()
{
  if (m_pInstance == 0)
  {
    m_pInstance = new cAppConfig();
  }
  return m_pInstance;
}
//---------------------------------------------------------------------------

//****************************************************************************
//****************************************************************************
// class cAppConfigReadWrit
//

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
QVariant SETTINGS::cAppConfigReadWrite::config(QString section, QString key, QString def, QVariant value, bool write)
{
    QSettings app(QSettings::UserScope, ORGANISATION, APPLICATION_NAME);

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
int SETTINGS::cAppConfigReadWrite::LogLevel()
{
    return config(SECTION_SETTINGS, VARIABLE_LOGGINGLEVEL, DEFAULT_LOGGINGLEVEL, "").toInt();
}
//-----------------------------------------------------------------------------

///
/// \brief SETTINGS::cAppConfig::Language
/// \param value
///
void SETTINGS::cAppConfigReadWrite::LogLevel(int value)
{
    config(SECTION_SETTINGS, VARIABLE_LOGGINGLEVEL, "", value, true);
}
//-----------------------------------------------------------------------------

///
/// \brief SETTINGS::cAppConfig::Language
/// \return
///
int SETTINGS::cAppConfigReadWrite::LogOutput()
{
    return config(SECTION_SETTINGS, VARIABLE_LOGGINGOUTPUT, DEFAULT_LOGGINGOUTPUT, "").toInt();
}
//-----------------------------------------------------------------------------

///
/// \brief SETTINGS::cAppConfig::Language
/// \param value
///
void SETTINGS::cAppConfigReadWrite::LogOutput(int value)
{
    config(SECTION_SETTINGS, VARIABLE_LOGGINGOUTPUT, "", value, true);
}
//-----------------------------------------------------------------------------