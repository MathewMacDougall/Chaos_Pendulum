#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/pendulum.hpp"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    Pendulum p1;
    Pendulum p2;
    QTimer timer;

};


#endif // MAINWINDOW_H
