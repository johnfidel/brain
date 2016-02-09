/**
* @file                     BrainExperience.cpp
* @author                   RPi
* @date                     06.02.2016
* @brief                    This class represents a serie of objects in brain.
*                           This may be a sentence for instance
*
*-------------------------------------------------------------------------------
* @verbatim
* Revisionhistory:
*
* Rev:  Datum:      Wer:        Was:
* ------------------------------------------------------------------------------
* V00   06.01.2016  rappic      Writing initial version
*
* @endverbatim
*-------------------------------------------------------------------------------
*/
#pragma once

#include <QObject>
#include <QList>
#include <QImage>
#include <QJsonObject>
#include <QDateTime>

#include "BrainObject.h"

class cBrainExperience : public QObject
{
  Q_OBJECT
private:

  /// \brief the list ob objects4
  QList<cBrainObject*> m_Experience;

public:

  /// \brief standard ctor
  explicit cBrainExperience(QObject *parent = 0);

  /// \brief destructor
  ~cBrainExperience();

  /// \brief adds a object into list
  void AddObject(const cBrainObject& obj);

  /// \brief converts class into JSON object
  QJsonObject toJson() const;

  /// \brief converst a JSon string into a cBrainObject
  cBrainObject fromString(const QString&);

  /// \brief getter for the experience
  QList<cBrainObject*> Experience() const { return m_Experience; }

signals:

public slots:
};
