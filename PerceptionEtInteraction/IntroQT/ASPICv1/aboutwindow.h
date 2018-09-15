#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = 0);
    ~AboutWindow();
    void addAboutText();
    void addAboutPicture();

private:
    static const int WIDTH = 400;
    static const int HEIGHT = 300;
    Ui::AboutWindow *ui;
    QLabel *aboutText;
    QLabel *aboutPictureLabel;
};

#endif // ABOUTWINDOW_H
