#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "src/pendulum.hpp"
#include "src/util/point.hpp"
#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <vector>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    protected:
        void paintEvent(QPaintEvent *);
        void drawPendulum(QPainter *painter, Pendulum p);

    public slots:
        void updateSimulation();

private slots:
        void on_actionStart_triggered();
        void on_actionStop_triggered();

        void on_PendulumWidget_destroyed();

private:
        Ui::MainWindow *ui;

        std::vector<Pendulum> allPendulums;
        std::vector<Pendulum *> rootPendulums; // all Pendulums connected to a fixed point

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
