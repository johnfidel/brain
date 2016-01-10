/**
* @file                     BrainObject.cpp
* @author                   RPi
* @date                     04.01.2016
* @brief                    This class describes a known object to the brain.
*
*-------------------------------------------------------------------------------
* @verbatim
* Revisionhistory:
*
* Rev:  Datum:      Wer:        Was:
* ------------------------------------------------------------------------------
* V00   04.01.2016  rappic      Writing initial version
*
* @endverbatim
*-------------------------------------------------------------------------------
*/
#include <QJsonValue>
#include <QJsonArray>
#include <algorithm>
#include <QMap>
#include <QJsonDocument>

#include "BrainObject.h"

/*!
  \class cBainObject
  \brief This class contains the
*/
/*----------------------------------------------------------------------*/


/*!
  \brief cBrainObject::cBrainObject
           This is the constructor of the class
  \param parent, The parent object
 */
cBrainObject::cBrainObject(QObject *parent) :
  QObject(parent)
{

}
/*----------------------------------------------------------------------*/


// copyconstructor
cBrainObject::cBrainObject(const cBrainObject &obj)
{

}

/*!
  \brief cBrainObject
           Constructor for a new object
  \param langId, the Id of the language
  \param name, name in the specified language
 */
cBrainObject::cBrainObject(const int langId, const QString name)
{

}
/*----------------------------------------------------------------------*/

/*!
 * \brief cBrainObject::AddName
 * \param langId
 * \param name
 */
void cBrainObject::AddName(int langId, QString name)
{
  m_dictionary.insert(langId, name);
}
/*----------------------------------------------------------------------*/

/*!
 * \brief cBrainObject::AddImage
 * \param image
 */
void cBrainObject::AddImage(QImage image)
{
  m_image = image;
}
/*----------------------------------------------------------------------*/

/*!
 * \brief cBrainObject::toJson
 *        Converts this Object into a JSON Object
 * \return
 */
QJsonObject cBrainObject::toJson()
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
/*----------------------------------------------------------------------*/

/*!
 * \brief cBrainObject::fromString
 *        converts a string into a Object
 * \param JsonString
 */
cBrainObject cBrainObject::fromString(const QString string)
{
  cBrainObject obj;

  QJsonDocument strJson = QJsonDocument::fromJson(string.toUtf8());
  QJsonObject jsonObject = strJson.object();
  QJsonArray jsonArray = jsonObject["properties"].toArray();

  //return cBrainObject();
}
/*----------------------------------------------------------------------*/
