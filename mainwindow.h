#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include "pendulumwidget.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void on_startButton_clicked();
        void on_stopButton_clicked();
        void on_addPendulumButton_clicked();
        void on_removePendulumButton_clicked();
        void on_speedSlider_sliderMoved(int position);
        void on_resetSpeedButton_clicked();

private:
        Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
