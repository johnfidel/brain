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

  connect(m_ImageCapturer, SIGNAL(readyForCaptureChanged(bool)), this, SLOT(readyForCapture(bool)));
  connect(m_ImageCapturer, SIGNAL(imageCaptured(int,QImage)), this, SLOT(processCapturedImage(int,QImage)));
  connect(m_ImageCapturer, SIGNAL(imageSaved(int,QString)), this, SLOT(imageSaved(int,QString)));
  connect(m_ImageCapturer, SIGNAL(error(int,QCameraImageCapture::Error,QString)), this,
          SLOT(displayCaptureError(int,QCameraImageCapture::Error,QString)));

}

//-------------------------------------------------------------------
//
void cWebCam::setViewFinder(QCameraViewfinder *pViewFinder)
{
  m_camera->setViewfinder(pViewFinder);

  m_camera->start();
}

//-------------------------------------------------------------------
//
void cWebCam::readyForCapture(bool ready)
{
}

//-------------------------------------------------------------------
//
void cWebCam::processCapturedImage(int requestId, const QImage& img)
{
    Q_UNUSED(requestId);
    QImage scaledImage = img.scaled(m_camera->viewfinderSettings().resolution(),
                                    Qt::KeepAspectRatio,
                                    Qt::SmoothTransformation);


}

//-------------------------------------------------------------------
//
void cWebCam::imageSaved(int id, const QString &fileName)
{    
}

void cWebCam::displayCaptureError(int id, const QCameraImageCapture::Error error, const QString &errorString)
{

}
