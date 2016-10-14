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
  Q_OBJECT

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

    ///
    /// \brief readyForCapture
    /// \param ready
    ///
    void readyForCapture(bool ready);

    ///
    /// \brief processCapturedImage
    /// \param requestId
    /// \param img
    ///
    void processCapturedImage(int requestId, const QImage& img);

    ///
    /// \brief imageSaved
    /// \param id
    /// \param fileName
    ///
    void imageSaved(int id, const QString &fileName);

    ///
    /// \brief displayCaptureError
    /// \param id
    /// \param error
    /// \param errorString
    ///
    void displayCaptureError(int id, const QCameraImageCapture::Error error, const QString &errorString);

};

#endif // CWEBCAM_H
