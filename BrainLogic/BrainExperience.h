/**
* @file                     BrainExperience.h
* @author                   RPi
* @date                     13.02.2016
* @brief                    This class describes a Experience
*
*-------------------------------------------------------------------------------
* @verbatim
* Revisionhistory:
*
* Rev:  Datum:      Wer:        Was:
* ------------------------------------------------------------------------------
* V00   13.02.2016  rappic      Writing initial version
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

#include "BrainLogic/BrainObject.h"

class cBrainExperience : public QObject
{
  Q_OBJECT
private:

  /// \brief list of cBrainObjects
  QString m_Experience;
  //QImage *m_pImage;
  QDateTime m_TimeStamp;

public:

  /// \brief standard ctor
  explicit cBrainExperience(QObject *parent = 0);

  /// \brief destructor
  ~cBrainExperience();

  /// \brief Special constructor
  explicit cBrainExperience(const QString &experience, QObject *parent = 0);

  /// \brief Getter and setter
  QString Experience() const { return m_Experience; }
  void Experience(const QString &value) { m_Experience = value; }
  QDateTime TimeStamp() const { return m_TimeStamp; }
  void TimeStamp(const QDateTime &value) { m_TimeStamp = value; }

  /// \brief converts class into JSON object
  QJsonObject toJson() const;

  /// \brief converst a JSon string into a cBrainObject
  static cBrainExperience* fromJson(const QJsonObject &);

signals:

public slots:
};
