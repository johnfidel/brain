#pragma once

#include <QString>
#include <QJsonObject>

class cJsonSerializer
{

public:

  /// \brief convert QJSonObject into string
  static QString QJSonToString(const QJsonObject& obj);

  /// \brief save a QJSonObject to a file
  static QString QJSonToFile(const QJsonObject& obj, const QString& File);
};
