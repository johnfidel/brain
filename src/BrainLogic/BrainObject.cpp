#include <QJsonValue>
#include <QJsonArray>
#include <algorithm>
#include <QMap>
#include <QJsonDocument>

#include "BrainObject.h"

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
cBrainObject::cBrainObject(QObject *parent) :
  QObject(parent), m_Name("")//, m_pImage(0)
{
  // save creation time
  m_TimeStamp = QDateTime::currentDateTime();
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject
/// \param name
/// \param parent
///
cBrainObject::cBrainObject(const QString &name, QObject *parent) :
  QObject(parent)
{
  // save creation time
  m_TimeStamp = QDateTime::currentDateTime();
  m_Name = name;
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::~cBrainObject
///
cBrainObject::~cBrainObject()
{
//  if (m_pImage != 0)
//  {
//    delete m_pImage;
//    m_pImage = 0;
//  }
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::toJson
/// \return
///
QJsonObject cBrainObject::toJson() const
{
  QJsonObject tmp;

  // append all properties to json object
  tmp.insert("m_TimeStamp", QJsonValue(m_TimeStamp.toString()));
  tmp.insert("m_Name", QJsonValue(m_Name));

  return tmp;

}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::fromString
/// \param string
/// \return
///
cBrainObject* cBrainObject::fromJson(const QJsonObject &jobj)
{

  cBrainObject *obj = new cBrainObject();
  obj->Name(jobj["m_Name"].toString());
  obj->TimeStamp(QDateTime::fromString(jobj["m_TimeStamp"].toString()));

  return obj;
}
//------------------------------------------------------------------------
