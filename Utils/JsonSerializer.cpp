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
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QDataStream>
#include "JsonSerializer.h"

/*!
 * \brief cJsonSerializer::cJsonSerializer
 * \param parent
 */
QString cJsonSerializer::QJsonToString(const QJsonObject& obj)
{
  QJsonDocument doc(obj);
  return QString(doc.toJson(QJsonDocument::Compact));
}

///
/// \brief cJsonSerializer::QStringToJson
/// \param str
/// \return
///
QJsonObject cJsonSerializer::QStringToJson(const QString& str)
{
  return QJsonObject();
}

/*!
 * \brief cJsonSerializer::QJSonToFile
 *       Save a JSON Object into a file
 * \param obj
 *        the Object
 * \param File
 *        the filename
 * \return
 */
bool cJsonSerializer::QJsonToFile(const QJsonObject &obj, const QString &File)
{
  QJsonDocument doc(obj);
  QFile jsonFile(File);

  QFileInfo *jsonFileInfo = new QFileInfo(jsonFile.fileName());
  if (!jsonFileInfo->absoluteDir().exists())
  {
    jsonFileInfo->absoluteDir().mkpath(jsonFileInfo->absoluteDir().absolutePath());
  }

  jsonFile.open(QFile::ReadWrite);
  jsonFile.write(doc.toJson());

  delete jsonFileInfo;

  return false;
}



