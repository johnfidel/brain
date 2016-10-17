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

#include "AudioFileHandler.h"
#include "View/EarsWidget.h"

#include <QElapsedTimer>
#include <QtCore/QDebug>
#include <QFile>
#include <QDataStream>

static const int resolution = 8;

void cAudioFileHandler::handleWidget(const char *data, qint64 maxSize)
{
  qint64 range = 2000;
  QVector<QPointF> oldPoints = m_pWidget->getLineSeries().pointsVector();
  QVector<QPointF> points;
  int resolution = 4;

  if (oldPoints.count() < range) {
      points = m_pWidget->getLineSeries().pointsVector();
  } else {
      for (int i = maxSize/resolution; i < oldPoints.count(); i++)
          points.append(QPointF(i - maxSize/resolution, oldPoints.at(i).y()));
  }

  qint64 size = points.count();
  for (int k = 0; k < maxSize/resolution; k++)
      points.append(QPointF(k + size, ((quint8)data[resolution * k] - 128)/128.0));

  m_pWidget->getLineSeries().replace(points);
}

//-----------------------------------------------------------------------------------
//
bool cAudioFileHandler::saveFile()
{
  static int fileNr = 0;
  QString filename = QString("audio") + QString::number(fileNr++) + QString(".raw");
  QFile file(filename);
  file.open(QIODevice::WriteOnly);  

  while (m_DataQueue.count() > 0)
  {
    char chr = m_DataQueue.dequeue();
    file.write(&chr);
  }

  file.close();

  qDebug() << "file: " << filename << " saved.";

  return true;
}

cAudioFileHandler::cAudioFileHandler(QWidget *widget, QObject *parent)
    : QIODevice(parent), m_pWidget(0)
{
  if (widget)
  {
    m_pWidget = new cEarsWidget(widget);
    m_pWidget->show();
  }

  // start timer
  m_pretimer.start();
  m_posttimer.start();

}

// Implementation required for this pure virtual function
qint64 cAudioFileHandler::readData(char *data, qint64 maxSize)
{
    Q_UNUSED(data)
    Q_UNUSED(maxSize)
    return -1;
}

qint64 cAudioFileHandler::writeData(const char *data, qint64 maxSize)
{
  static bool recording = false;
  static qint64 addedPoints = 0;
  static qint64 addedPointsSince200ms = 0;

  // handle gui
  if (m_pWidget)
  {
    handleWidget(data, maxSize);
  }

//  QFile file("audiotest.raw");
//  file.open(QIODevice::Append);
//  file.write(data, maxSize);
//  file.close();

  // check level of audio
  int index = 0;
  bool peak = false;
  float peakvalue = 0.0;
  for (int i = 0; i < maxSize; i++)
  {

    // first save acutal data
    m_DataQueue.enqueue(data[i]);
    addedPoints++;

    // Add 0.01 to the value to avoid gaps in the graph (i.e. zero height bars).
    // Also, scale to 0...100
    float value = float(quint8(data[i]) - 128) / 1.28f + 0.01f;

    if (value > peakvalue)
    {
      peakvalue = value;
    }
    index++;
  }

  if (peakvalue > 2.0)
  {
    recording = true;
    m_posttimer.restart();
    qDebug() << "peak " << peakvalue;
  } 

  // reset pretimer
  if ((m_pretimer.hasExpired(200)) && (recording == false))
  {
    addedPointsSince200ms = addedPoints;
  }
  if ((m_pretimer.hasExpired(400)) && (recording == false))
  {
    m_pretimer.restart();
    // remove first 200ms of recording
    for (quint64 i = 0; i < (addedPoints - addedPointsSince200ms); i++)
    {
      m_DataQueue.dequeue();
    }
    qDebug() << "removed: " << (addedPoints - addedPointsSince200ms) << " data";
    addedPoints = 0;
    addedPointsSince200ms = 0;
  }

  if ((recording) && (m_posttimer.hasExpired(200)))
  {
    recording = false;
    m_posttimer.restart();
    m_pretimer.restart();
    saveFile();
  }

  return maxSize;
}


