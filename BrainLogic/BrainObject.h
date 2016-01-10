#pragma once

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

  // Getter and setter
  int Id() const { return m_id; }
  QMap<int, QString> Dictionary() const { return m_dictionary; }
  QImage Image() const { return m_image; }

  // converts class into JSON object
  QJsonObject toJson();

  // converst a JSon string into a cBrainObject
  static cBrainObject fromString(const QString JsonString);

signals:

public slots:
};
