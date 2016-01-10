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

class cMemoryManager : public QObject
{
    Q_OBJECT

  private :

    /// \brain list of all memories
    QList<cBrainObject> m_MemoryList;

  public:

    /*!
     * \brief cMemoryManager
     * \param parent
     */
    explicit cMemoryManager(QObject *parent = 0);

  signals:

  public slots:
};
