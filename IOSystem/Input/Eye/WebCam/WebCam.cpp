/**
* @file                     WebCam.cpp
* @author                   RPi
* @date                     04.01.2016
* @brief                    This Module handles the Input over a webcam
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
#include "WebCam.h"
#include "View/MainView.h"

#include <QAction>
#include <QCameraImageCapture>
#include <QCameraViewfinder>

//-------------------------------------------------------------------
//
cWebCam::cWebCam(QObject *parent) : QObject(parent)
{
  m_camera = new QCamera(QCameraInfo::defaultCamera());

  m_ImageCapturer = new QCameraImageCapture(m_camera);
}

//-------------------------------------------------------------------
//
void cWebCam::setViewFinder(QCameraViewfinder *pViewFinder)
{
  m_camera->setViewfinder(pViewFinder);

  m_camera->start();
}
