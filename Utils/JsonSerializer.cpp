/**
* @file                     JsonSerializer.cpp
* @author                   RPi
* @date                     04.01.2016
* @brief                    This class provides the interface for JSON
*                           serialisation of Objects
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
#include <QJsonDocument>

#include "JsonSerializer.h"

/*!
 * \brief cJsonSerializer::cJsonSerializer
 * \param parent
 */
QString cJsonSerializer::QJSonToString(const QJsonObject &obj)
{
  QJsonDocument doc(obj);
  return QString(doc.toJson(QJsonDocument::Compact));
}

/*!
 * \brief cJsonSerializer::QJSonToFile
 *        Save a JSON Object into a file
 * \param obj
 *        the Object
 * \param File
 *        the filename
 * \return
 */
QString cJsonSerializer::QJSonToFile(const QJsonObject &obj, const QString &File)
{

}



