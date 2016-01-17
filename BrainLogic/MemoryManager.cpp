#include "MemoryManager.h"
#include "BrainLogic/BrainObject.h"

//******************************************************************************
// private functions
//

/*!
 * \brief cMemoryManager::cMemoryManager
 *        private constructor to initialize singleton
 * \param parent
 */
cMemoryManager::cMemoryManager(QObject *parent) : QObject(parent)
{
  m_pMemoryList = new QList<cBrainObject>();
}
//-----------------------------------------------------------------------------

///
/// \brief cMemoryManager::~cMemoryManager
///
cMemoryManager::~cMemoryManager()
{
  if (m_pMemoryList != 0)
  {
    delete m_pMemoryList;
    m_pMemoryList = 0;
  }
}

//******************************************************************************
// public functions
//

/*!
 * \brief cMemoryManager::m_pInstance
 *        This function is to get an instance of Memorymanager
 */
cMemoryManager *cMemoryManager::m_pInstance = 0;
cMemoryManager *cMemoryManager::Instance()
{
  if (m_pInstance == 0)
  {
    m_pInstance = new cMemoryManager();
  }
  return m_pInstance;
}

///
/// \brief cMemoryManager::AddToMemory
/// \param Obj
///
void cMemoryManager::AddToMemory(const cBrainObject& Obj)
{
  m_pMemoryList->append(Obj);
}
