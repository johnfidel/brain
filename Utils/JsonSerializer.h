#ifndef CJSONSERIALIZER_H
#define CJSONSERIALIZER_H

#include <QObject>

class cJsonSerializer : public QObject
{
  Q_OBJECT
public:
  explicit cJsonSerializer(QObject *parent = 0);

signals:

public slots:
};

#endif // CJSONSERIALIZER_H
