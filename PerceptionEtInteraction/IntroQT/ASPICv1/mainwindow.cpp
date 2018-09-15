#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Création des menus
    QMenu *fileMenu = new QMenu("File");
    QMenu *optionsMenu = new QMenu("Options");

    ui->menuBar->addMenu(fileMenu);
    ui->menuBar->addMenu(optionsMenu);

    //Ajout des sous-menus au menu File
    QAction *openFileAction = fileMenu->addAction("Open");
    openFileAction->setShortcut(tr("Ctrl+O"));

    QAction *saveAction = fileMenu->addAction("Save");
    saveAction->setShortcut(tr("Ctrl+S"));

    QAction *quitAction = fileMenu->addAction("Quit");
    quitAction->setShortcut(tr("Ctrl+Q"));

    //Ajout des sous-menus au menu Options
    QAction *aboutAction = optionsMenu->addAction("About");
    aboutAction->setShortcut(tr("Ctrl+A"));

    //Ajout des événements
    connect(quitAction, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(onAboutActionClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAboutActionClicked()
{
    aboutWindow = new AboutWindow(this);
    aboutWindow->show();
}
