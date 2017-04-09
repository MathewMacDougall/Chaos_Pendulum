#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    setWindowTitle(tr("Chaos Pendulum"));

    // sets so that the PendulumWidget takes up as much
    // space as possible initially in the splitter
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 0);

    // set stylesheet for the splitter handle
    // basically makes the splitter visible
    this->setStyleSheet("QSplitter::handle{"
                        "background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
                        "stop:0 #eee, stop:1 #ccc);"
                        "border: 1px solid #777;"
                        "width: 5px;"
                        "margin-top: 2px;"
                        "margin-bottom: 2px;"
                        "border-radius: 4px;"
                        "}");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    ui->pendulumWidget->startSimulation();
}

void MainWindow::on_stopButton_clicked()
{
    ui->pendulumWidget->stopSimulation();
}

void MainWindow::on_addPendulumButton_clicked()
{
    ui->pendulumWidget->addPendulum();
}

void MainWindow::on_removePendulumButton_clicked()
{
    ui->pendulumWidget->removePendulum();
}

void MainWindow::on_speedSlider_sliderMoved(int position)
{
    ui->pendulumWidget->setSimulationSpeed(position);
    std::cout << position << std::endl;
}

void MainWindow::on_resetSpeedButton_clicked()
{
    ui->pendulumWidget->setSimulationSpeed(100);
    ui->speedSlider->setValue(100);
}
