/**
* @file                     MemoryManager.h
* @author                   RPi
* @date                     10.01.2016
* @brief                    This Module handles all the memories in brain
*
*-------------------------------------------------------------------------------
* @verbatim
* Revisionhistory:
*
* Rev:  Datum:      Wer:        Was:
* ------------------------------------------------------------------------------
* V00   10.01.2016  rappic      Writing initial version
*
* @endverbatim
*-------------------------------------------------------------------------------
*/
#pragma once

#include <QObject>
#include <QList>

#include "BrainLogic/BrainObject.h"
#include "BrainLogic/BrainExperience.h"
#include "BrainLogic/MemoryManager_Def.h"

class cMemoryManager : public QObject
{
    Q_OBJECT

  private :

    /// \brief instance holder
    static cMemoryManager *m_pInstance;

    /// \brief ctor (Singleton)
    explicit cMemoryManager(QObject *parent = 0);

    /// \brief destructor
    ~cMemoryManager();

    /// \brief adds a object into list
    void AddToMemory(const cBrainObject &);

    /// \brief adds a object into list
    void AddToMemory(const cBrainExperience &);

  public:

    /// \brief To get an instance
    static cMemoryManager *Instance();

    /// \brief adds a object into list
    void AddToMemory(const QString &Text);

    /// \brief Does some sorting and analysing work on memory
    void ManageMemory();

  signals:

  public slots:
};
