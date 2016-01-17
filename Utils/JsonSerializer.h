#pragma once

#include <QString>
#include <QJsonObject>

class cJsonSerializer
{

public:

  /// \brief convert QJSonObject into string
  static QString QJsonToString(const QJsonObject& obj);

  /// \brief convert a string to json Object
  static QJsonObject QStringToJson(const QString& str);

  /// \brief save a QJSonObject to a file
  static bool QJsonToFile(const QJsonObject& obj, const QString& File);
};
