/**

* @file                     TextWriter.cpp
* @author                   RPi
* @date                     04.01.2016
* @brief                    This Module handles the Output of Text over the
*                           console
*
*-------------------------------------------------------------------------------
*/
#pragma once

#include <QObject>

#include "IOSystem/IOInterface.h"

namespace OUTPUT
{
  class cTextWriter : public cIOInterface
  {
      Q_OBJECT
    private:

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
      explicit cTextWriter(QObject *parent = 0);

    signals:

    public slots:

      /// \brief reimplementation of Interface
      virtual void OnEvent(const EVENTS::cEvent &);

  };
}
