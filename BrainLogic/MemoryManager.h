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

    /// \brief stores short and long memory
    struct MemoryStructure
    {
        QList<cBrainObject*> mem;
        QList<cBrainExperience*> exp;
    };

    /// \brief brain list of all memories
    MemoryStructure m_MemoryList;

    /// \brief The index of the MemoryEntry
    int m_ActualIndex;

    /// \brief instance holder
    static cMemoryManager *m_pInstance;

    /// \brief ctor (Singleton)
    explicit cMemoryManager(QObject *parent = 0);

    /// \brief destructor
    ~cMemoryManager();

    /// \brief adds a object into list
    void AddToMemory(cBrainObject&);

    /// \brief adds a object into list
    void AddToMemory(cBrainExperience&);

  public:

    /// \brief To get an instance
    static cMemoryManager *Instance();

    /// \brief adds a object into list
    void AddToMemory(const QString& Text);

    /// \brief Does some sorting and analysing work on memory
    void ManageMemory();

  signals:

  public slots:
};
