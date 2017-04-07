#ifndef PENDULUMWIDGET_H
#define PENDULUMWIDGET_H

#include "src/pendulum.hpp"
#include "src/util/point.hpp"
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <vector>

class PendulumWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PendulumWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawPendulum(QPainter *painter, Pendulum p);

public slots:
    void updateSimulation();

private slots:
    void on_actionStart_triggered();
    void on_actionStop_triggered();

private:
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

#endif // PENDULUMWIDGET_H
