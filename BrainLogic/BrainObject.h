#ifndef CBRAINOBJECT_H
#define CBRAINOBJECT_H

#include <QObject>
#include <QMap>
#include <QImage>
#include <QJsonObject>

class cBrainObject : public QObject
{
  Q_OBJECT
private:

  int m_id;
  QMap<int, QString> m_dictionary;
  QImage m_image;

public:

  //standard ctor
  explicit cBrainObject(QObject *parent = 0);

  // Special constructor
  explicit cBrainObject(const int langId, const QString name);

  // converts class into JSON object
  QJsonObject toJson();

signals:

public slots:
};

#endif // CBRAINOBJECT_H
