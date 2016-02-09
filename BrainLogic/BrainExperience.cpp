#include <QJsonValue>
#include <QJsonArray>
#include <algorithm>
#include <QMap>
#include <QJsonDocument>
#include <QJsonObject>

#include "BrainExperience.h"

//***********************************************************************
// private functions
//

//***********************************************************************
// public functions
//

///
/// \brief cBrainObject::cBrainObject
/// \param parent
///
cBrainExperience::cBrainExperience(QObject *parent) :
  QObject(parent)
{ }
//------------------------------------------------------------------------

/*!
 * \brief cBrainExperience::~cBrainExperience
 */
cBrainExperience::~cBrainExperience()
{

}
//------------------------------------------------------------------------

/*!
 * \brief cBrainExperience::toJson
 * \return
 */
QJsonObject cBrainExperience::toJson() const
{
  QJsonDocument tmp;

  foreach (cBrainObject *obj, Experience())
  {

  }
}
//------------------------------------------------------------------------

/*!
 * \brief cBrainExperience::fromString
 * \param string
 * \return
 */
cBrainObject cBrainExperience::fromString(const QString& string)
{

}
//------------------------------------------------------------------------
