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
#include <QDebug>

#include "CoreState.h"
#include "Input/Console/TextReader.h"

/*!
 * \brief cCoreState::cCoreState
 *        standardconstructor
 * \param parent
 */
cCoreState::cCoreState(QObject *parent) :
  QThread(parent)
{
  m_eMainState = Idle;
}

/*!
  \brief Reimplemented Functions from baseclass
  */

/*!
 * \brief cCoreState::exec
 * \return
 */
void cCoreState::run()
{
  cTextReader consoleInput;

  while (isRunning())
  {
    QThread::msleep(20);
    switch (m_eMainState)
    {

      case Idle:
      {
        consoleInput.DoWork();
      }

      default:
      {

      }

    } /* switch (m_MainState); */
  }
}


