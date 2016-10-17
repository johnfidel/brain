#include <QJsonValue>
#include <QJsonArray>
#include <algorithm>
#include <QMap>
#include <QJsonDocument>
#include <QDateTime>

#include "BrainLogic/BrainExperience.h"

//***********************************************************************
// private functions
//

//***********************************************************************
// public functions
//

///
/// \brief cBrainObject::cBrainObject
/// \param parent
///
cBrainExperience::cBrainExperience(QObject *parent) :
  QObject(parent)
{
  // save creation time
  m_TimeStamp = QDateTime::currentDateTime();
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::cBrainObject
/// \param name
/// \param langId
///
cBrainExperience::cBrainExperience(const QString &experience, QObject *parent) :
  QObject(parent)
{
  // save creation time
  m_TimeStamp = QDateTime::currentDateTime();
  m_Experience = experience;
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::~cBrainObject
///
cBrainExperience::~cBrainExperience()
{ }
//------------------------------------------------------------------------

///
/// \brief cBrainObject::toJson
/// \return
///
QJsonObject cBrainExperience::toJson() const
{
  QJsonObject tmp;

  // append all properties to json object
  tmp.insert("m_TimeStamp", QJsonValue(m_TimeStamp.toString()));
  tmp.insert("m_Experience", QJsonValue(m_Experience));

  return tmp;
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::fromString
/// \param string
/// \return
///
cBrainExperience* cBrainExperience::fromJson(const QJsonObject &obj)
{

  cBrainExperience *exp = new cBrainExperience();
  exp->Experience(obj["m_Experience"].toString());
  exp->TimeStamp(QDateTime::fromString(obj["m_TimeStamp"].toString()));

  return exp;
}
//------------------------------------------------------------------------
