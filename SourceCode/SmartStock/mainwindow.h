#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <library.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void showProgressBar();

private slots:
    void on_pushButton_Connexion_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
