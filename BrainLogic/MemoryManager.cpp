#include "MemoryManager.h"
#include "BrainLogic/BrainObject.h"
#include "Utils/JsonSerializer.h"

//******************************************************************************
// private functions
//

/*!
 * \brief cMemoryManager::cMemoryManager
 *        private constructor to initialize singleton
 * \param parent
 */
cMemoryManager::cMemoryManager(QObject *parent) :
  QObject(parent), m_ActualIndex(0)
{

}
//-----------------------------------------------------------------------------

///
/// \brief cMemoryManager::~cMemoryManager
///
cMemoryManager::~cMemoryManager()
{
  // clean up memnory
  foreach (cBrainObject *obj, m_MemoryList.longMemory)
  {
    delete obj;
  }
  foreach (cBrainObject *obj, m_MemoryList.shortMemory)
  {
    delete obj;
  }
}
//-----------------------------------------------------------------------------

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
//-----------------------------------------------------------------------------

/*!
 * \brief cMemoryManager::AddToMemory
 * \param Text
 */
void cMemoryManager::AddToMemory(const QString& Text)
{
  // create new brainObject
  cBrainObject *pObj = new cBrainObject(m_ActualIndex++, Text);

  // add it to list of shortmemory
  AddToShortMemory(*pObj);

}
//-----------------------------------------------------------------------------

///
/// \brief cMemoryManager::AddToMemory
/// \param Obj
///
void cMemoryManager::AddToShortMemory(cBrainObject& Obj)
{
  m_MemoryList.shortMemory.append(&Obj);

#ifdef DEBUG
  QString FileName;
  //FileName << QString(WORKSPACE_PATH) << QString(MEMORY_SHORT) << Obj.TimeStamp().toString("yyyymmdd_hhmmss");
  cJsonSerializer::QJsonToFile(Obj.toJson(), FileName);
#else
  cJsonSerializer::QJsonToFile(Obj.toJson(), Obj.TimeStamp().toString(QString(MEMORY_LONGTERM) + "yyyymmdd_hhmmss"));
#endif //DEBUG

}
//-----------------------------------------------------------------------------

/*!
 * \brief cMemoryManager::ManageMemory
 */
void cMemoryManager::ManageMemory()
{

}
//-----------------------------------------------------------------------------
