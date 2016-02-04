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
  QObject(parent), m_id(-1), m_dictionary()//, m_pImage(0)
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
cBrainObject::cBrainObject(const cBrainObject &obj) :
  QObject()
{
  m_dictionary = obj.m_dictionary;
  m_id = obj.m_id;
//  if (obj.m_pImage != 0)
//  {
//    m_pImage = new QImage(*obj.m_pImage);
//  }
  m_TimeStamp = obj.m_TimeStamp;

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

/*!
 * \brief cBrainObject::cBrainObject
 * \param idx
 * \param name
 * \param langId
 * \param parent
 */
cBrainObject::cBrainObject(const int idx, const QString name, const int langId, QObject *parent) :
  QObject(parent)
{
  //save idx
  m_id = idx;
  // save creation time
  m_TimeStamp = QDateTime::currentDateTime();
  // add the name to dictionary
  m_dictionary.insert(langId, name);
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
/// \brief cBrainObject::AddName
/// \param name
/// \param langId
///
void cBrainObject::AddName(const QString& name, int langId)
{
  m_dictionary.insert(langId, name);
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::AddImage
/// \param image
///
void cBrainObject::AddImage(const QImage& image)
{
  //*m_pImage = image;
}
//------------------------------------------------------------------------

///
/// \brief cBrainObject::toJson
/// \return
///
QJsonObject cBrainObject::toJson() const
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
cBrainObject cBrainObject::fromString(const QString& string)
{
  cBrainObject obj;

  QJsonDocument strJson = QJsonDocument::fromJson(string.toUtf8());
  QJsonObject jsonObject = strJson.object();
  QJsonArray jsonArray = jsonObject["properties"].toArray();

  //return cBrainObject();
}
//------------------------------------------------------------------------
