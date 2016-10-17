#ifndef QMAINVIEWMODEL_H
#define QMAINVIEWMODEL_H

#include <QStandardItemModel>
#include <QCameraViewfinder>

class cMainViewModel : public QObject
{
  Q_OBJECT

  private:
    QCameraViewfinder *m_pViewFinder;
    QWidget *m_pWidget;

  public:
    cMainViewModel();

    ///
    /// \brief getViewFinder
    /// \return
    /// Returns the actual viewfinder object
    QCameraViewfinder* getEyes() const { return m_pViewFinder; }
    void setEyes(QCameraViewfinder* pEyes) { m_pViewFinder = pEyes; }

    QWidget* getEars() const { return m_pWidget; }
    void setEars(QWidget* pEars) { m_pWidget = pEars; }

};

#endif // QMAINVIEWMODEL_H
