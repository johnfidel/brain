#ifndef CWEBCAM_H
#define CWEBCAM_H

#include <QObject>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraImageCapture>

#include "GenDefs.h"
#include "View/MainViewModel.h"

class cWebCam : public QObject
{

  private:
    QCamera *m_camera;
    QCameraImageCapture *m_ImageCapturer;

  public:

    ///
    /// \brief cWebCam
    ///
    explicit cWebCam(QObject *parent = nullptr);

    void setViewFinder(QCameraViewfinder *pViewFinder);

  signals:

  public slots:

};

#endif // CWEBCAM_H
