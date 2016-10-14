#include "MainView.h"
#include "ui_MainWindow.h"
#include "View/MainViewModel.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::setModel(cMainViewModel& model)
{
  model.setViewFinder(ui->viewFinder);
}
