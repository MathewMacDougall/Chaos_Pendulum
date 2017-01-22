#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "src/util/point.hpp"
#include <iostream>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), p1(150, -2, 300000, Point()), p2(150, 0.9 * M_PI, 50, p1)
{
    ui->setupUi(this);
    p1.update(0.0);
    p2.update(0.0);

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(0.05);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// TODO: allow to paint arbitrary number of Pendulums. Add Pendulum controller?
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.translate(MainWindow::width() / 2, MainWindow::height() / 2);
    painter.scale(1, -1);

    QPen bobPen(Qt::red);
    bobPen.setWidth(15);

    QPen linePen(Qt::gray);
    linePen.setWidth(5);

    QPen basePen(Qt::black);
    basePen.setWidth(20);

    //draw base of pendulum system
    painter.setPen(basePen);
    painter.drawPoint((int)p1.getBasePosition().x(), (int)p1.getBasePosition().y());
    //draw the pendulum arm
    painter.setPen(linePen);
    painter.drawLine(p1.getBasePosition().x(), p1.getBasePosition().y(), p1.getBobPosition().x(), p1.getBobPosition().y());
    //draw the pendulum bob
    painter.setPen(bobPen);
    painter.drawPoint(p1.getBobPosition().x(), p1.getBobPosition().y());

    //draw base of pendulum system
    //painter.setPen(basePen);
    //painter.drawPoint((int)p2.getBasePosition().x(), (int)p2.getBasePosition().y());
    //draw the pendulum arm
    painter.setPen(linePen);
    painter.drawLine(p2.getBasePosition().x(), p2.getBasePosition().y(), p2.getBobPosition().x(), p2.getBobPosition().y());
    //draw the pendulum bob
    painter.setPen(bobPen);
    painter.drawPoint(p2.getBobPosition().x(), p2.getBobPosition().y());

    // TODO: Split rendering from updating
    p1.update(1.0/100.0);
    p2.update(1.0/100.0);
}
