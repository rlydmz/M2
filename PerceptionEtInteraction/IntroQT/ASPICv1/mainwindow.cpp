#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("ASPICv1");

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
    connect(openFileAction, SIGNAL(triggered(bool)), this, SLOT(onOpenFileActionClicked()));
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

void MainWindow::onOpenFileActionClicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "/",
                "JPG Files (*.jpg);;PNG files (*.png)");
    QImage *file = new QImage(filename);
    selectedFileLabel = new QLabel(this);
    QSize windowSize = this->size();
    int windowWidth = windowSize.width();
    int windowHeight = windowSize.height();
    if(file->width() <= windowWidth && file->height() <= windowHeight){
        selectedFileLabel->setGeometry((windowWidth - file->width())/2,
                                       (windowHeight - file->height())/2,
                                       file->width(),
                                       file->height());
        selectedFileLabel->setPixmap(QPixmap::fromImage(*file));
        selectedFileLabel->show();
    }
    else{
        qDebug("Image trop grande :/");
    }
}
