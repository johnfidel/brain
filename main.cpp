#include <QCoreApplication>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QJsonDocument>

#include "BrainLogic/CoreState.h"

int main(int argc, char *argv[])
{

  // create main application thread
  QCoreApplication App(argc, argv);

  // create mainthread
  cCoreState BrainCore(&App);
  BrainCore.start();

  // close event
  QObject::connect(&BrainCore, SIGNAL(finished()), &App, SLOT(quit()));

  // mainloop
  return App.exec();

}

