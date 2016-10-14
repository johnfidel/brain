#include <iostream>
#include <QDebug>
#include <QTextStream>

#include "IOSystem/Input/InputInterface.h"
#include "TextReader.h"

//********************************************************************************
// private constants
//
const QString INPUT::cTextReader::CONSOLE_PROMPT = "brain: ";

//********************************************************************************
// private functions
//

//--------------------------------------------------------------------------------
// main function
void INPUT::cTextReader::run()
{

  QTextStream in(stdin);
  QTextStream out(stdout, QIODevice::WriteOnly);

  // output default string
  out << CONSOLE_PROMPT << endl;

  while (true)
  {
    QThread::msleep(20);

    QString entry = in.readLine();
    out << CONSOLE_PROMPT << endl;

    if (entry != "")
    {
      emit Event(EVENTS::cEvent(EVENTS::cEvent::ConsoleInput, entry));
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
