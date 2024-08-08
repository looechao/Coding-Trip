#include "mainwindow.h"
#include "mywidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.resize(1200,800);
    w.show();
    return a.exec();
}
