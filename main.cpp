#include <QCoreApplication>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QJsonDocument>
#include <QDateTime>

#include "BrainLogic/CoreState.h"
#include "Utils/Logger.h"

int main(int argc, char *argv[])
{

  // create main application thread
  QCoreApplication App(argc, argv);

  // create mainthread
  cCoreState BrainCore(&App);
  BrainCore.start();

  // close event
  QObject::connect(&BrainCore, SIGNAL(finished()), &App, SLOT(quit()));

  // log programstard
  UTILS::cLogger::Logger() << QString("Application started at:");// << QDateTime::currentDateTime().toString();

  // mainloop
  return App.exec();

}

