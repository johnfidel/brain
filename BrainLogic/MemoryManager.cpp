#include <QStringList>

#include "MemoryManager.h"
#include "BrainLogic/BrainObject.h"
#include "BrainLogic/BrainExperience.h"
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
  // check if this is a experience of a object
  if (Text.split(" ").count() > 1)
  {
    cBrainExperience *pExp = new cBrainExperience(this);

    QStringList list = Text.split(" ");
    foreach (QString str, list)
    {
      cBrainObject *obj = new cBrainObject(m_ActualIndex++, str, this);
      pExp->AddObject(obj);
    }
    // ad to memory
    AddToShortMemory(pExp);
  }
  else
  {
    // create new brainObject
    cBrainObject *pObj = new cBrainObject(m_ActualIndex++, Text, this);

    // add it to list of shortmemory
    AddToShortMemory(*pObj);
  }
}
//-----------------------------------------------------------------------------

///
/// \brief cMemoryManager::AddToMemory
/// \param Obj
///
void cMemoryManager::AddToMemory(cBrainObject& Obj)
{
  m_MemoryList.mem.append(&Obj);

  QString fileName(WORKSPACE_PATH "/" MEMORY_SHORT);
  fileName.append(Obj.TimeStamp().toString("yyyymmdd_hhmmss"));
  cJsonSerializer::QJsonToFile(Obj.toJson(), fileName);
}
//-----------------------------------------------------------------------------

///
/// \brief cMemoryManager::AddToMemory
/// \param Obj
///
void cMemoryManager::AddToMemory(cBrainExperience& Exp)
{
  m_MemoryList.exp.append(&Exp);

  QString fileName(WORKSPACE_PATH "/");
  fileName.append(Obj.TimeStamp().toString("yyyymmdd_hhmmss"));
  cJsonSerializer::QJsonToFile(Exp.toJson(), fileName);
}
//-----------------------------------------------------------------------------

/*!
 * \brief cMemoryManager::ManageMemory
 */
void cMemoryManager::ManageMemory()
{
  // try to create dependencies between memoryObjects
  foreach (cBrainObject *obj, m_MemoryList.shortMemory)
  {
    foreach (cBrainObject *compObj, m_MemoryList.shortMemory)
    {
      //if obj.Name()
    }
  }
}
//-----------------------------------------------------------------------------
