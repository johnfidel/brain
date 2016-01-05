/**
* @file                     CoreState.cpp
* @author                   RPi
* @date                     04.01.2016
* @brief                    Main Thread of Brainlogic
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
#include "CoreState.h"

/*!
 * \brief cCoreState::cCoreState
 *        standardconstructor
 * \param parent
 */
cCoreState::cCoreState(QObject *parent) : QThread(parent)
{

}

/*!
  \brief Reimplemented Functions from baseclass
  */

/*!
 * \brief cCoreState::exec
 * \return
 */
int cCoreState::exec()
{

  switch (m_MainState)
  {

  }
}


