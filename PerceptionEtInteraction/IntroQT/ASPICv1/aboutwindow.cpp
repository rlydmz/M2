#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);

    setWindowTitle("About");
    setFixedSize(WIDTH,HEIGHT);
    addAboutText();
    addAboutPicture();
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::addAboutText()
{
    aboutText = new QLabel(this);
    aboutText->setText(QString::fromUtf8("Crée par Raphaël Anquetil"));
    aboutText->setGeometry(50,260,300,20);
    aboutText->show();
}

void AboutWindow::addAboutPicture()
{
    QPixmap *aboutPicture = new QPixmap(":/img/About.jpg");
    aboutPictureLabel = new QLabel(this);
    aboutPictureLabel->setGeometry(60, 20,
                                   aboutPicture->width(),
                                   aboutPicture->height());
    aboutPictureLabel->setPixmap(*aboutPicture);
    aboutPictureLabel->show();
}
