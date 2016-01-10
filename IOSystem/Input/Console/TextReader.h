/**

* @file                     TextReader.cpp
* @author                   RPi
* @date                     04.01.2016
* @brief                    This Module handles the Input of Text over the
*                           console
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
#pragma once

#include <QObject>

#include "IOSystem/Input/InputInterface.h"

namespace INPUT
{
  class cTextReader : public cInputInterface
  {
      Q_OBJECT
    private:

      static const QString CONSOLE_PROMPT;

       /*!
        * \brief run
        *        Main function of thread
        */
       void run();

    public:

      /*!
       * \brief cTextReader
       *        standard ctor
       * \param parent
       */
      explicit cTextReader(QObject *parent = 0);

    signals:

    public slots:

  };
}
