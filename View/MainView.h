#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "View/MainViewModel.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);

    ///
    /// \brief SetModel
    /// \param model
    /// sets the underlying datamodel for view
    void setModel(cMainViewModel& model);

    ~MainWindow();

  private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
