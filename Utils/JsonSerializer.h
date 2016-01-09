#ifndef CJSONSERIALIZER_H
#define CJSONSERIALIZER_H

#include <QString>
#include <QJsonObject>

class cJsonSerializer
{

public:

  // convert QJSonObject into string
  static QString QJSonToString(const QJsonObject obj);

};

#endif // CJSONSERIALIZER_H
