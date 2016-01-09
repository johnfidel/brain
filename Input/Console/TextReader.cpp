/**

* @file                     TextReader.cpp
* @author                   RPi
* @date                     04.01.2016
* @brief                    This Module handles the Input of Text over the
*                           console
*
*-------------------------------------------------------------------------------
* @verbatim
* Revisionsverzeichnis:
*
* Rev:  Datum:      Wer:        Was:
* ------------------------------------------------------------------------------
* V00   04.01.2016  rappic      Writing initial version
*
* @endverbatim
*-------------------------------------------------------------------------------
*/
#include <iostream>
#include <QDebug>
#include <QTextStream>

#include "TextReader.h"

/*!
 * \brief cTextReader::cTextReader
 *          standard ctor
 * \param parent, parent Object
 */
cTextReader::cTextReader(QObject *parent) : QObject(parent)
{

}
/*-------------------------------------------------------------------*/

void cTextReader::DoWork()
{
  QTextStream console(stdin);

  qDebug() << console.readLine();

}
