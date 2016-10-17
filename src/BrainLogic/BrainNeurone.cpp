#include <QObject>

#include "BrainNeurone.h"

//***********************************************************************
// private functions
//

/*!
 * \brief cBrainNeurone::initVariables
 */
void cBrainNeurone::initVariables()
{
  m_BrainObjects.clear();
  m_BrainObjects.clear();
}
//------------------------------------------------------------------------

//***********************************************************************
// public functions
//

/*!
 * \brief cBrainNeurone::cBrainNeurone
 * \param parent
 */
cBrainNeurone::cBrainNeurone(QObject *parent) :
  QObject(parent)
{
  initVariables();

}
//------------------------------------------------------------------------

/*!
 * \brief cBrainNeurone::~cBrainNeurone
 */
cBrainNeurone::~cBrainNeurone()
{
  foreach (cBrainObject *pObj, m_BrainObjects)
  {
    delete pObj;
    pObj = NULL;
  }
  foreach (cBrainExperience *pExp, m_BrainExperiences)
  {
    delete pExp;
    pExp = NULL;
  }

}
//------------------------------------------------------------------------

/*!
 * \brief cBrainNeurone
 * \param pObj
 * \param parent
 */
cBrainNeurone::cBrainNeurone(cBrainObject *pObj, QObject *parent) :
  QObject(parent)
{
  initVariables();

  m_BrainObjects.append(pObj);
}
//------------------------------------------------------------------------

/*!
 * \brief cBrainNeurone
 * \param pExp
 * \param parent
 */
cBrainNeurone::cBrainNeurone(cBrainExperience *pExp, QObject *parent) :
  QObject(parent)
{

  initVariables();

  m_BrainExperiences.append(pExp);
}
//------------------------------------------------------------------------
