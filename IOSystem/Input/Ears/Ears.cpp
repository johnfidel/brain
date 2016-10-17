/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Data Visualization module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "Ears.h"
#include "View/MainViewModel.h"

#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioInput>

namespace INPUT
{

  cEars::cEars(cMainViewModel *widget, QObject *parent)
      : cIOInterface(parent),
        m_fileHandler(0),
        m_audioInput(0)
  {

      QAudioDeviceInfo inputDevice = QAudioDeviceInfo::defaultInputDevice();

      if (inputDevice.supportedSampleRates().size() > 0
              && inputDevice.supportedChannelCounts().size() > 0
              && inputDevice.supportedSampleSizes().size() > 0
              && inputDevice.supportedCodecs().size() > 0) {
          QAudioFormat formatAudio;
          formatAudio.setSampleRate(8000);
          formatAudio.setChannelCount(1);
          formatAudio.setSampleSize(8);
          formatAudio.setCodec("audio/pcm");
          formatAudio.setByteOrder(QAudioFormat::LittleEndian);
          formatAudio.setSampleType(QAudioFormat::UnSignedInt);

          m_audioInput = new QAudioInput(inputDevice, formatAudio, this);
  #ifdef Q_OS_MAC
          // OS X seems to wait for entire buffer to fill before calling writeData, so use smaller buffer
          m_audioInput->setBufferSize(256);
  #else
          m_audioInput->setBufferSize(1024);
  #endif

#if USE_GUI
          m_fileHandler = new cAudioFileHandler(widget->getEars(), this);
#else
          m_fileHandler = new cAudioFileHandler(nullptr, this);
#endif //USE_GUI

          m_fileHandler->open(QIODevice::WriteOnly);
          m_audioInput->start(m_fileHandler);
      }
  }

  cEars::~cEars()
  {
      if (m_audioInput)
          m_audioInput->stop();
  }


  //********************************************************************************
  // public functions
  //

  //--------------------------------------------------------------------------------
  // main function
  void INPUT::cEars::run()
  {

    while (true)
    {
      QThread::msleep(20);
    }
  }

}

