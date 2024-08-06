#include "mainwindow.h"

#include <QApplication>

#include <QDebug>

#include <QList>

#include <QSet>

#include <QMap>

QList<int>& Myintersection(QList<int>& ql, QSet<int>& qs)
{
    QList<int>* res = new QList<int>;
    for(auto &it : ql){
        if(qs.contains(it)){
            res->append(it);
        }
    }
    return *res;
}

QList<int>& MyOdd(QMap<int, int>& qm)
{
    QList<int>* res = new QList<int>;
    for(auto &it : qm)
    {
        if(it % 2 != 0)
        {
            res->append(it);
        }
        if(qm.key(it) %2 != 0)
        {
            res->append(qm.key(it));
        }
    }
    return *res;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "hello world!";
    QList<int> ql1 = {1, 2, 3, 4, 5};
    QSet<int> b = {1, 2, 4, 9, 10};
    QList<int> res = Myintersection(ql1, b);
    QMap<int, int> qm;
    qm.insert(8, 9);
    qm.insert(3, 7);
    qm.insert(6, 4);
    QList<int> res2 = MyOdd(qm);
    qDebug() << res;
    qDebug() << res2;
    return a.exec();
}

