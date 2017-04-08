#include "mainwindow.h"
#include "ui_mainwindow.h"


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
