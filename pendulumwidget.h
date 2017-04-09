#ifndef PENDULUMWIDGET_H
#define PENDULUMWIDGET_H

#include "src/pendulum.hpp"
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
    void drawPendulum(QPainter *painter, Pendulum &p);

public slots:
    void updateSimulation();
    void startSimulation();
    void stopSimulation();
    void addPendulum();
    void removePendulum();
    void setSimulationSpeed(int);

private:
    std::vector<Pendulum*> allPendulums;

    QTimer renderTimer;
    QTimer updateTimer;

    /**
     * Creates and returns a pendulum with random parameters
     *
     * @return a pointer to a pendulum with random parameters
     */
    Pendulum* getRandomPendulum();

    int fps;
    int fps_timer;
    double fps_dt;

    const int ups = 100;
    const int ups_timer = 1000 / ups;
    const double default_ups_dt = ups_timer / 1000.0 * 6;
    double ups_dt;
};

#endif // PENDULUMWIDGET_H
