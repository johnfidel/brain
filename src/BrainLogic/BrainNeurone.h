/**
* @file                     BrainObject.h
* @author                   RPi
* @date                     04.01.2016
* @brief                    This class describes a known object to the brain.
*
*-------------------------------------------------------------------------------
*/
#pragma once

#include <QObject>
#include <QList>

#include "BrainLogic/BrainExperience.h"
#include "BrainLogic/BrainObject.h"

class cBrainNeurone : public QObject
{
    Q_OBJECT
  private:

    /// \brief This list contains multiple brainobjects
    QList<cBrainObject*> m_BrainObjects;

    /// \brief this list may contain multiple experiences
    QList<cBrainExperience*> m_BrainExperiences;

    /// \brief this function initialises the class objects
    void initVariables();

  public:

    /// \brief standard ctor
    explicit cBrainNeurone(QObject *parent = 0);
    ~cBrainNeurone();

    /// \brief this is a constructor with one Brainobject
    explicit cBrainNeurone(cBrainObject *pObj, QObject *parent = 0);

    /// \brief this is a constructor with one Brainexperience
    explicit cBrainNeurone(cBrainExperience *pExp, QObject *parent = 0);

    /// \brief getter and setters
    QList<cBrainObject*> BrainObjects() const { return m_BrainObjects; }
    QList<cBrainExperience*> BrainExperiences() const { return m_BrainExperiences; }

  signals:

  public slots:

};
