#pragma once

#include <QString>
#include <QJsonObject>

class cJsonSerializer
{

  private:

  public:

    /// \brief save a QJSonObject to a file
    static bool QJsonToFile(const QJsonObject &obj, const QString &File);

    /// \brief save a QJSonObject to a file
    static QJsonObject QFileToJson(const QString &File);

};
