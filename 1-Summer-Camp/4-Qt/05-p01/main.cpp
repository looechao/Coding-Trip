#include "mainwindow.h"
#include "mywidget.h"

#include <QApplication>
#include <QtWidgets/QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
