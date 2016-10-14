#pragma once

#include <QString>
#include <QJsonObject>

class cJsonSerializer
{

public:

  /// \brief convert QJSonObject into string
  static QString QJsonToString(const QJsonObject&);

  /// \brief convert a string to json Object
  static QJsonObject QStringToJson(const QString&);

  /// \brief save a QJSonObject to a file
  static bool QJsonToFile(const QJsonObject&, const QString&);
};
