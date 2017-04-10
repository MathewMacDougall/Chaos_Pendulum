#include "pendulumwidget.h"
#include <QPainter>
#include <QResizeEvent>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include <iostream>

PendulumWidget::PendulumWidget(QWidget *parent) : QWidget(parent)
{
    std::srand(time(0));

    allPendulums.push_back(new Pendulum(150, -2, 300000, Point()));
    allPendulums.push_back(new Pendulum(150, 0.9 * M_PI, 50, Point()));
    allPendulums[0]->attachChild(*allPendulums[1]);

    updateScaleFactor();

    fps = 60;
    fps_timer = 1000 / fps;
    fps_dt = fps_timer / 1000.0;

    ups_dt = default_ups_dt;

    connect(&renderTimer, SIGNAL(timeout()), this, SLOT(update()));
    renderTimer.start(fps_timer);

    connect(&updateTimer, SIGNAL(timeout()), this, SLOT(updateSimulation()));
    updateTimer.start(ups_timer);
}

void PendulumWidget::updateSimulation() {
    for(unsigned int i = 0; i < allPendulums.size(); i++) {
        if(!allPendulums[i]->isAttachedToPendulum()) {
            allPendulums[i]->update(ups_dt);
            allPendulums[i]->update(0.0); // This should makes sure all pendulums get their base positions updated to look "attached"
        }
    }
}

void PendulumWidget::startSimulation()
{
    if(!updateTimer.isActive()) {
        updateTimer.start(ups_timer);
    }
}

void PendulumWidget::stopSimulation()
{
    updateTimer.stop();
}

void PendulumWidget::addPendulum() {
    if(allPendulums.empty()) {
        allPendulums.push_back(getRandomPendulum());
    }else {
        allPendulums.push_back(getRandomPendulum());
        allPendulums[allPendulums.size() - 1]->attachTo(*allPendulums[allPendulums.size() - 2]);
    }

    updateScaleFactor();
}

void PendulumWidget::removePendulum() {
    if(allPendulums.empty()) {
        return;
    }else if(allPendulums.size() == 1){
        allPendulums.pop_back();
    }else {
        allPendulums[allPendulums.size() - 1]->attachTo(Point());
        allPendulums.pop_back();
    }

    updateScaleFactor();
}

void PendulumWidget::setSimulationSpeed(int speedPercentage) {
    ups_dt = default_ups_dt * speedPercentage / 100.0;
}

Pendulum* PendulumWidget::getRandomPendulum() {
    return new Pendulum(std::rand() % 300 + 50,
                    std::rand() % 1000 / 1000.0 * 2 * M_PI,
                    std::rand() % 1000 + 1,
                    Point());
}

double PendulumWidget::getLongestPendulumChain() {
    double longest = 0.0;
    for(unsigned int i = 0; i < allPendulums.size(); i++) {
        if(!allPendulums[i]->isAttachedToPendulum()) {
            double length = allPendulums[i]->getMaxTotalLength();
            if(length > longest) {
                longest = length;
            }
        }
    }

    return longest;
}

void PendulumWidget::updateScaleFactor() {
    int smallesttDim = this->width() > this->height() ? this->height() : this->width();
    int padding = 50;
    double length = getLongestPendulumChain() == 0.0 ? 1.0 : getLongestPendulumChain();
    scaleFactor = (double) (pow(smallesttDim, 0.9) - padding) / length;
}

void PendulumWidget::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    updateScaleFactor();
}

void PendulumWidget::drawPendulum(QPainter *painter, Pendulum &p) {

    QPen bobPen(Qt::red);
    bobPen.setWidth(15);

    QPen linePen(Qt::gray);
    linePen.setWidth(5);

    QPen basePen(Qt::black);
    basePen.setWidth(20);

    //draw base of pendulum system if this pendulum is attached to it
    if(!p.isAttachedToPendulum()) {
        painter->setPen(basePen);
        painter->drawPoint((int)p.getBasePosition().x(), (int)p.getBasePosition().y());
    }

    //draw the pendulum arm
    painter->setPen(linePen);
    painter->drawLine(p.getBasePosition().x(), p.getBasePosition().y(), p.getBobPosition().x(), p.getBobPosition().y());

    //draw the pendulum bob
    painter->setPen(bobPen);
    painter->drawPoint(p.getBobPosition().x(), p.getBobPosition().y());
}

void PendulumWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.translate(PendulumWidget::width() / 2, PendulumWidget::height() / 2); // set so (0, 0) is the middle of the window
    painter.scale(scaleFactor, -scaleFactor); // flips the y axis so +ve is "up"

    for(unsigned int i = 0; i < allPendulums.size(); i++) {
        drawPendulum(&painter, *allPendulums[i]);
    }
}
