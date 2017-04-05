#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    allPendulums.push_back(Pendulum(150, -2, 300000, Point()));
    allPendulums.push_back(Pendulum(150, 0.9 * M_PI, 50, Point()));
    allPendulums[0].attachChild(allPendulums[1]);

    rootPendulums.push_back(&allPendulums[0]);

    fps = 60;
    fps_timer = 1000 / fps;
    fps_dt = fps_timer / 1000.0;

    ups = 100;
    ups_timer = 1000 / ups;
    ups_dt = ups_timer / 1000.0 * 4;

    connect(&renderTimer, SIGNAL(timeout()), this, SLOT(update()));
    renderTimer.start(fps_timer);

    connect(&updateTimer, SIGNAL(timeout()), this, SLOT(updateSimulation()));
    updateTimer.start(ups_timer);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateSimulation() {
    for(unsigned int i = 0; i < rootPendulums.size(); i++) {
        rootPendulums[i]->update(ups_dt);
    }
}

void MainWindow::drawPendulum(QPainter *painter, Pendulum p) {

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

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.translate(MainWindow::width() / 2, MainWindow::height() / 2); // set so (0, 0) is the middle of the window
    painter.scale(1, -1); // flips the y axis so +ve is "up"

    for(unsigned int i = 0; i < allPendulums.size(); i++) {
        drawPendulum(&painter, allPendulums[i]);
    }
}
