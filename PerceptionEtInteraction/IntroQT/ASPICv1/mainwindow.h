#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static const int WIDTH = 800;
    static const int HEIGHT = 600;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onAboutActionClicked();
    void onOpenFileActionClicked();

private:
    Ui::MainWindow *ui;
    AboutWindow *aboutWindow;
    QLabel *selectedFileLabel;
};

#endif // MAINWINDOW_H
