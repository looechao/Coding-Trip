#include "mainwindow.h"
#include "awidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    MyWidget w;
    w.show();
    return a.exec();
}
