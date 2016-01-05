/**
* @file                     BrainObject.cpp
* @author                   RPi
* @date                     04.01.2016
* @brief                    This class describes a known object to the brain.
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
#include "BrainObject.h"

/*!
  \class cBainObject
  \brief This class contains the
*/

/*!
  \brief cBrainObject::cBrainObject
           This is the constructor of the class
  \param parent, The parent object
 */
cBrainObject::cBrainObject(QObject *parent) :
  QObject(parent)
{

}

/*!
  \brief cBrainObject
           Constructor for a new object
  \param langId, the Id of the language
  \param name, name in the specified language
 */
cBrainObject::cBrainObject(const int langId, const QString name)
{

}

QJsonObject toJson();
