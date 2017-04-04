#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "src/pendulum.hpp"
#include "src/util/point.hpp"
#include <QMainWindow>
#include <QTimer>
#include <QPainter>


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
    void drawPendulum(QPainter *painter, Pendulum p);

public slots:
    void updateSimulation();

private:
    Ui::MainWindow *ui;

    Pendulum p1, p2;

    QTimer renderTimer;
    QTimer updateTimer;

    int fps;
    int fps_timer;
    double fps_dt;

    int ups;
    int ups_timer;
    double ups_dt;
};


#endif // MAINWINDOW_H
