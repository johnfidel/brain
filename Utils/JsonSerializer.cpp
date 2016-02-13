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

//***********************************************************************
// private functions
//

//***********************************************************************
// public functions
//

///
/// \brief cJsonSerializer::FileToJson
///         Wandelt eine json datei in ein Objekt um
/// \param File
/// \param obj
/// \return
///
QJsonObject cJsonSerializer::QFileToJson(const QString &File)
{
  QFile jsonFile(File);
  jsonFile.open(QFile::ReadOnly);

  QJsonDocument doc = QJsonDocument::fromJson(jsonFile.readAll());

  jsonFile.close();

  return doc.object();
}
//---------------------------------------------------------------------

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

  QFileInfo info(jsonFile.fileName());
  if (!info.absoluteDir().exists())
  {
    info.absoluteDir().mkpath(info.absoluteDir().absolutePath());
  }

  jsonFile.open(QFile::ReadWrite);
  jsonFile.write(doc.toJson());
  jsonFile.close();

  return false;
}
//---------------------------------------------------------------------


