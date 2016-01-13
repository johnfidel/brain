/**
* @file                     BrainObject.cpp
* @author                   RPi
* @date                     04.01.2016
* @brief                    This class describes a known object to the brain.
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
#pragma once

#include <QObject>
#include <QMap>
#include <QImage>
#include <QJsonObject>
#include <QDateTime>

class cBrainObject : public QObject
{
  Q_OBJECT
private:

  int m_id;
  QMap<int, QString> m_dictionary;
  QImage m_image;
  QDateTime m_TimeStamp;

public:

  /// \brief standard ctor
  explicit cBrainObject(QObject *parent = 0);

  /// \brief copyconstructor
  explicit cBrainObject(const cBrainObject &obj);

  /// \brief Special constructor
  explicit cBrainObject(const QString name, const int langId = 0, QObject *parent = 0);

  /// \brief adds the name for another language
  void AddName(QString name, int langId = 0);

  /// \brief adds an image for the object
  void AddImage(QImage image);

  /// \brief Getter and setter
  int Id() const { return m_id; }
  QMap<int, QString> Dictionary() const { return m_dictionary; }
  QImage Image() const { return m_image; }
  QDateTime TimeStamp() const { return m_TimeStamp; }

  /// \brief converts class into JSON object
  QJsonObject& toJson() const;

  /// \brief converst a JSon string into a cBrainObject
  static cBrainObject fromString(const QString JsonString);

  /// \brief operator =
  cBrainObject operator=(const cBrainObject& other);

signals:

public slots:
};
