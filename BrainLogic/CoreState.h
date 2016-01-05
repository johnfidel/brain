#ifndef CORESTATE_H
#define CORESTATE_H

#include <QObject>
#include <QThread>

class cCoreState : public QThread
{
  Q_OBJECT
private:

  /*!
   * \brief The eCoreState_typ enum
   *        Help enumerator for the internal statemachine
   */
  enum eCoreState_typ
  {
    Idle = 0,

  };

  /*!
   * \brief m_MainState, Stores the actual Mainstate
   */
  eCoreState_typ m_MainState;

public:

  // standard constructor
  explicit cCoreState(QObject *parent = 0);

  // overrided function exec
  virtual int exec();

signals:

public slots:
};

#endif // CORE_H
