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

  // copyconstructor
  explicit cBrainObject(const cBrainObject &obj);

  // Special constructor
  explicit cBrainObject(const int langId, const QString name);

  // adds the name for another language
  void AddName(int langId, QString name);

  // adds an image for the object
  void AddImage(QImage image);

  // converts class into JSON object
  QJsonObject toJson();

  // converst a JSon string into a cBrainObject
  static cBrainObject fromString(const QString JsonString);

signals:

public slots:
};

#endif // CBRAINOBJECT_H
