#ifndef CEYE_H
#define CEYE_H

#include "IOSystem/IOInterface.h"
#include "Drivers/WebCam/WebCam.h"

#include <QMutex>
#include <QCameraViewfinder>

namespace INPUT
{

  class cEye : public cIOInterface
  {
    Q_OBJECT

    private:

      QCameraViewfinder *m_pViewFinder;
      cWebCam *m_pWebCam;

    public:

      ///
      /// \brief run
      ///
      void run();

      ///
      /// \brief cEye
      ///
      explicit cEye(cMainViewModel *widget = nullptr, QObject *parent = nullptr);      

    public slots:

      ///
      /// \brief OnEvent
      ///
      void OnEvent(const EVENTS::cEvent &);

  };
}

#endif // CEYE_H
