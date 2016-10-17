#include "Eyes.h"

namespace INPUT
{

  //-----------------------------------------------------------
  //
  cEye::cEye(cMainViewModel *widget, QObject *parent) :
    cIOInterface(parent), m_pViewFinder(0), m_pWebCam(0)
  {
    // create webcam
    if (widget)
    {
      m_pViewFinder = widget->getEyes();
    }
    else
    {
      m_pViewFinder = new QCameraViewfinder();
    }

    if (m_pViewFinder)
    {
      m_pWebCam = new cWebCam(m_pViewFinder);
    }
  }

  //-----------------------------------------------------------
  //
  void cEye::run()
  {
    while (true)
    {
      QThread::msleep(20);           
    }
  }

  //-----------------------------------------------------------
  //
  void cEye::OnEvent(const EVENTS::cEvent &)
  {
  }

}
