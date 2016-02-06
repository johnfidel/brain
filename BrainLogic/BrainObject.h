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
  QString m_Name;
  //QImage *m_pImage;
  QDateTime m_TimeStamp;

public:

  /// \brief standard ctor
  explicit cBrainObject(QObject *parent = 0);
  /// \brief copyconstructor
  explicit cBrainObject(const cBrainObject &obj);
  /// \brief operator =
  cBrainObject operator=(const cBrainObject&);

  /// \brief destructor
  ~cBrainObject();

  /// \brief Special constructor
  explicit cBrainObject(const QString name, QObject *parent = 0);

  /// \brief Special constructor
  explicit cBrainObject(const int idx, const QString name, QObject *parent = 0);

  /// \brief adds an image for the object
  void AddImage(const QImage&);

  /// \brief Getter and setter
  int Id() const { return m_id; }
  QString Name() const { return m_Name; }
  //QImage Image() const { return *m_pImage; }
  QDateTime TimeStamp() const { return m_TimeStamp; }

  /// \brief converts class into JSON object
  QJsonObject toJson() const;

  /// \brief converst a JSon string into a cBrainObject
  cBrainObject fromString(const QString&);

signals:

public slots:
};
