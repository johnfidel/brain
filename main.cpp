#include <QCoreApplication>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QJsonDocument>

#include "BrainLogic/CoreState.h"

int main(int argc, char *argv[])
{

  // create mainthread
  cCoreState App;
  App.start();

  // mainloop
  while (App.isRunning());

  return 0;

}

