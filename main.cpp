#include <QApplication>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QJsonDocument>
#include <QDateTime>

#include "ModDefs.h"
#include "BrainLogic/CoreState.h"
#include "Logging/Logger.h"
#include "Logging/LogMessage.h"
#include "View/MainWindow.h"
#include "IOSystem/Input/Eye/WebCam/WebCam.h"

void getLoggingConfiguration()
{ 
  // configure logging
  int loglevel = SETTINGS::cAppConfig::Instance()->LogLevel();
  LOGGING::cLogger::Instance()->ConfigureLogger((LOGGING::LoggingLevel)loglevel);
  int logoutput = SETTINGS::cAppConfig::Instance()->LogOutput();
  LOGGING::cLogger::Instance()->ConfigureLogger((LOGGING::cLogger::LoggingOutput)logoutput);
}

void initApplication(QCoreApplication *app)
{
  // globale programmeinstellungen
  app->setOrganizationName(ORGANISATION);
  app->setOrganizationDomain(ORGANISATION_DOMAIN);
  app->setApplicationName(APPLICATION_NAME);
  app->setApplicationVersion(APP_VERSION);

  // configure logger
  getLoggingConfiguration();
}

int main(int argc, char *argv[])
{

  // create main application thread
  QApplication App(argc, argv);

  initApplication(&App);

  cWebCam webcam;

  // create mainthread  
  cCoreState BrainCore(&App);
  BrainCore.start();

  // close event
  QObject::connect(&BrainCore, SIGNAL(finished()), &App, SLOT(quit()));

  // log programstard
  LOGGING::cLogger::Logger() << LOGGING::cLogMessage("Application started", LOGGING::LoggingLevelInfo);

  MainWindow w;
  w.show();

  // mainloop
  return App.exec();

}

