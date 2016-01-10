#include <iostream>
#include <QDebug>
#include <QTextStream>

#include "IOSystem/Input/InputInterface.h"
#include "TextReader.h"


//********************************************************************************
// private functions
//

//--------------------------------------------------------------------------------
// main function
void INPUT::cTextReader::run()
{
  QTextStream console(stdin);

  while (true)
  {
    QThread::msleep(20);

    QString input = console.readLine();

    if (input != "")
    {
      emit Event(EVENTS::cEventNotifier(EVENTS::cEventNotifier::ConsoleInput, input));
    }
  }
}

//********************************************************************************
// public functions
//

//--------------------------------------------------------------------------------
// ctor
INPUT::cTextReader::cTextReader(QObject *parent) :
    cInputInterface(parent)
{

}
//--------------------------------------------------------------------------------
