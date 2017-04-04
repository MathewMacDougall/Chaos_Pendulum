#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), p1(150, -2, 300000, Point()), p2(150, 0.9 * M_PI, 50, p1)
{
    ui->setupUi(this);

    //p1 = Pendulum(150, -2, 300000, Point());
    //p2 = Pendulum(150, 0.9 * M_PI, 50, p1);
    //p1(150, -2, 300000, Point()), p2(150, 0.9 * M_PI, 50, p1)

    fps = 30;
    fps_timer = 1000 / fps;
    fps_dt = fps_timer / 1000.0;

    ups = 60;
    ups_timer = 1000 / fps;
    ups_dt = fps_timer / 1000.0;

    connect(&renderTimer, SIGNAL(timeout()), this, SLOT(update()));
    renderTimer.start(fps_timer);

    connect(&updateTimer, SIGNAL(timeout()), this, SLOT(updateSimulation()));
    updateTimer.start(ups_timer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSimulation() {
    p1.update(ups_dt);
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

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.translate(MainWindow::width() / 2, MainWindow::height() / 2); // set so (0, 0) is the middle of the window
    painter.scale(1, -1); // flips the y axis so +ve is "up"

    drawPendulum(&painter, p1);
    drawPendulum(&painter, p2);
}
