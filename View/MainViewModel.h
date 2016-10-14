#ifndef QMAINVIEWMODEL_H
#define QMAINVIEWMODEL_H

#include <QStandardItemModel>
#include <QCameraViewfinder>

class cMainViewModel : public QObject
{
  Q_OBJECT

  private:
    QCameraViewfinder *m_pViewFinder;

  public:
    cMainViewModel();

    ///
    /// \brief getViewFinder
    /// \return
    /// Returns the actual viewfinder object
    QCameraViewfinder* getViewFinder() const { return m_pViewFinder; }
    void setViewFinder(QCameraViewfinder* pViewFinder) { m_pViewFinder = pViewFinder; }

};

#endif // QMAINVIEWMODEL_H
