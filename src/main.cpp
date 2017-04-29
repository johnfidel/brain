#include <QApplication>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QJsonDocument>
#include <QDateTime>
#include <QTextToSpeech>

#include "ModDefs.h"
#include "BrainLogic/CoreState.h"
#include "Logging/Logger.h"
#include "Logging/LogMessage.h"

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

  QStringList engineList = QTextToSpeech::availableEngines();
  QTextToSpeech speech(engineList.first());
  speech.say("hello");

  speech.setLocale(QLocale::German);

  //speech.say("hallo");

  // create mainthread  
  cCoreState BrainCore;
  BrainCore.start();

  // close event
  QObject::connect(&BrainCore, SIGNAL(finished()), &App, SLOT(quit()));

  // log programstard
  LOGGING::cLogger::Logger() << LOGGING::cLogMessage("Application started", LOGGING::LoggingLevelInfo);

  // mainloop
  return App.exec();

  // log programstard
  LOGGING::cLogger::Logger() << LOGGING::cLogMessage("Application terminated", LOGGING::LoggingLevelInfo);

}

