#include <QStringList>
#include <QFile>
#include <QDir>
#include <QFileInfo>

#include "MemoryManager.h"
#include "BrainLogic/BrainObject.h"
#include "BrainLogic/BrainExperience.h"
#include "Utils/JsonSerializer.h"
#include "Logging/Logger.h"

//******************************************************************************
// private functions
//

/*!
 * \brief cMemoryManager::cMemoryManager
 *        private constructor to initialize singleton
 * \param parent
 */
cMemoryManager::cMemoryManager(QObject *parent) :
  QObject(parent)
{ }
//-----------------------------------------------------------------------------

///
/// \brief cMemoryManager::~cMemoryManager
///
cMemoryManager::~cMemoryManager()
{ }
//-----------------------------------------------------------------------------

///
/// \brief cMemoryManager::AddToMemory
/// \param Obj
///
void cMemoryManager::AddToMemory(const cBrainObject &Obj)
{
  QString fileName(WORKSPACE_PATH);

  fileName.append(Obj.Name().at(0).toUpper());
  fileName.append("/" + Obj.Name() + "/" + Obj.Name());

  QFileInfo info(fileName);
  if (!info.absoluteDir().exists())
  {
    // create directory
    info.absoluteDir().mkdir(info.absoluteDir().absolutePath());
  }
  // write file
  cJsonSerializer::QJsonToFile(Obj.toJson(), fileName);
}
//-----------------------------------------------------------------------------

///
/// \brief cMemoryManager::AddToMemory
/// \param Obj
///
void cMemoryManager::AddToMemory(const cBrainExperience &Exp)
{
  QString fileName(WORKSPACE_PATH);
  fileName.append(Exp.TimeStamp().toString("yyyymmdd_hhmmss"));
  cJsonSerializer::QJsonToFile(Exp.toJson(), fileName);
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
void cMemoryManager::AddToMemory(const QString &Text)
{
  // check if this is a experience of a object
  if (Text.split(" ").count() > 1)
  {
    // log programstard
    LOGGING::cLogger::Logger() << LOGGING::cLogMessage("Create new ExperienceObject", LOGGING::LoggingLevelVerbose);

    // create experience object
    cBrainExperience *pExp = new cBrainExperience(Text);
    // add it to memory
    AddToMemory(*pExp);
  }
  else
  {
    // log programstard
    LOGGING::cLogger::Logger() << LOGGING::cLogMessage("Create new BrainObject", LOGGING::LoggingLevelVerbose);

    // create new brainObject
    cBrainObject *pObj = new cBrainObject(Text);
    // add it to list of shortmemory
    AddToMemory(*pObj);
  }
}
//-----------------------------------------------------------------------------

/*!
 * \brief cMemoryManager::ManageMemory
 */
void cMemoryManager::ManageMemory()
{

  QDir directory(WORKSPACE_PATH);

  QFileInfoList files(directory.entryInfoList(QDir::Files));

  // read next file
  if (files.count() > 0)
  {

    // log
    LOGGING::cLogger::Logger() << LOGGING::cLogMessage("process " + files[0].fileName(), LOGGING::LoggingLevelDebug);

    // read experience object
    cBrainExperience *pExp = cBrainExperience::fromJson(cJsonSerializer::QFileToJson(files[0].absoluteFilePath()));

    // now check if one of the brain objects is contained in the experience
    foreach (QString str, pExp->Experience().split(' '))
    {
      QString firstLetter = str.at(0).toUpper();

      QDir parseDir(directory.absolutePath() + "/" + firstLetter);

      if (parseDir.exists())
      {
        QStringList objects = parseDir.entryList(QStringList(str), QDir::Files);
        if (objects.count() > 0)
        {
          //QFile::rename(files.at(0) )
        }
      }
    }



    // deallocate memory
    delete pExp;
  }
}
//-----------------------------------------------------------------------------
