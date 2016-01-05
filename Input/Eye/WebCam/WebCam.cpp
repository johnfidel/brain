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

/*!
 * \brief cWebCam::cWebCam
 *        standardconstructor of class
 */
cWebCam::cWebCam()
{

  QCamera myCamera;
  QCameraInfo cameraInfo(myCamera);

  QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
  foreach (const QCameraInfo &cameraInfo, cameras)
      qDebug() << cameraInfo.deviceName();

  if (cameraInfo.position() == QCamera::FrontFace)
      qDebug() << "The camera is on the front face of the hardware system.";
  else if (cameraInfo.position() == QCamera::BackFace)
      qDebug() << "The camera is on the back face of the hardware system.";

  qDebug() << "The camera sensor orientation is " << cameraInfo.orientation() << " degrees.";

}
