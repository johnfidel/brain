/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
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

#include "EarsWidget.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QtCharts>
#include <QtWidgets/QVBoxLayout>
#include <QtCharts/QValueAxis>

cEarsWidget::cEarsWidget(QWidget *parent)
    : QWidget(parent),
      m_chart(0),
      m_series(0)
{
    m_chart = new QChart;
    QChartView *chartView = new QChartView(m_chart);
    chartView->setMinimumSize(400, 300);
    m_series = new QLineSeries;
    m_chart->addSeries(m_series);
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, 2000);
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-1, 1);
    m_chart->setAxisX(axisX, m_series);
    m_chart->setAxisY(axisY, m_series);
    m_chart->legend()->hide();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);    
}

cEarsWidget::~cEarsWidget()
{ }
