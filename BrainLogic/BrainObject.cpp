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
  QObject(parent)
{
  // save creation time
  m_TimeStamp = QDateTime::currentDateTime();
}
//------------------------------------------------------------------------


///
/// \brief cBrainObject::cBrainObject
///         Copyconstructor
/// \param obj
///
cBrainObject::cBrainObject(const cBrainObject &obj)

{
  *this = obj;
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::cBrainObject
/// \param name
/// \param langId
///
cBrainObject::cBrainObject(const QString name, const int langId, QObject *parent) :
  QObject(parent)
{
  // save creation time
  m_TimeStamp = QDateTime::currentDateTime();
  // add the name to dictionary
  m_dictionary.insert(langId, name);
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::AddName
/// \param name
/// \param langId
///
void cBrainObject::AddName(QString name, int langId)
{
  m_dictionary.insert(langId, name);
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::AddImage
/// \param image
///
void cBrainObject::AddImage(QImage image)
{
  m_image = image;
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::toJson
/// \return
///
QJsonObject& cBrainObject::toJson() const
{
  QJsonObject tmp;
  QJsonArray array;

  // iterate through dictionary
  foreach (QString value, m_dictionary)
  {
    array.append(QJsonValue(value));
  }

  // append all properties to json object
  tmp.insert("m_id", QJsonValue(m_id));
  tmp.insert("m_dictionary", array);

  return tmp;

}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::fromString
/// \param string
/// \return
///
cBrainObject cBrainObject::fromString(const QString string)
{
  cBrainObject obj;

  QJsonDocument strJson = QJsonDocument::fromJson(string.toUtf8());
  QJsonObject jsonObject = strJson.object();
  QJsonArray jsonArray = jsonObject["properties"].toArray();

  //return cBrainObject();
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::operator =
/// \param other
/// \return
///
cBrainObject cBrainObject::operator=(const cBrainObject& other)
{
  m_TimeStamp = other.m_TimeStamp;
  m_dictionary = other.m_dictionary;
  m_image = other.m_image;
  m_id = other.m_id;
}
//------------------------------------------------------------------------
