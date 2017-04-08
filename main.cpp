#include "pendulumwidget.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow widget;
    widget.show();

    return a.exec();
}
