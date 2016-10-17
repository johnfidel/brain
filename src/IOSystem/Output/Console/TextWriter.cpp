#include <iostream>
#include <QDebug>
#include <QTextStream>

#include "IOSystem/IOInterface.h"
#include "IOSystem/Output/Console/TextWriter.h"

//********************************************************************************
// private constants
//

//********************************************************************************
// private functions
//

/*!
 * \brief OUTPUT::cTextWriter::run
 */
void OUTPUT::cTextWriter::run()
{
  QTextStream out(stdout, QIODevice::WriteOnly);

  while (true)
  {
    QThread::msleep(20);

    //out <<


  }
}

//********************************************************************************
// public functions
//

/*!
 * \brief OUTPUT::cTextWriter::cTextWriter
 * \param parent
 */
OUTPUT::cTextWriter::cTextWriter(QObject *parent) :
    cIOInterface(parent)
{

}
//--------------------------------------------------------------------------------

/*!
 * \brief OUTPUT::cTextWriter::OnEvent
 */
void OUTPUT::cTextWriter::OnEvent(const EVENTS::cEvent &)
{

}
//--------------------------------------------------------------------------------
