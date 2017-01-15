#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../pendulum.hpp"
#include "../util/point.hpp"
#include "../pendulum.cpp"
#include "../util/point.cpp"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QPen(Qt::black, 10, Qt::DashDotLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter.drawEllipse(width()/2, height()/2, width()/3, height()/2);

    /*
    Pendulum p1 = Pendulum(100, 1.0, 5, Point(200, 100));

    painter.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
    painter.drawLine(p1.getBasePosition().x(), p1.getBasePosition().y(),
                     p1.getBasePosition().x(), p1.getBobPosition().y());
    painter.drawEllipse(p1.getBobPosition().x(), p1.getBobPosition().y(),
                        10, 10);
                        */
}
