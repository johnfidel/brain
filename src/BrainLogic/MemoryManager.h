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
#include "EventInterface.h"

class cMemoryManager : public QObject, public EVENT::IEventInterface
{
    Q_OBJECT
    Q_INTERFACES(EVENT::IEventInterface)

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

    /// \brief searches for string in Memory
    bool SearchInMemory(const QString &);

    /// \brief adds a object into list
    void AddToMemory(const QString &);

    /// \brief Does some sorting and analysing work on memory
    void ManageMemory();

  signals:

    /// \brief reimplementation of interface
    void Event(const EVENTS::cEvent &);

  public slots:

    /// \brief reimplementation of interface
    virtual void OnEvent(const EVENTS::cEvent &) {}


};
