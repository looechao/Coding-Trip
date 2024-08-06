#include "mainwindow.h"

#include <QApplication>
#include <QString>
#include <QDebug>
#include <QStack>

QStack<QString> qs;

QStack<QString>& makestack(QString filepath){
    QStack<QString>* res = new QStack<QString>;
    QStringList list = filepath.split("/");
    for(int i = 0; i < list.size(); i++)
    {
        if(list[i] != "")
        {
            res->push(list[i]);
        }
    }
    return *res;
}

QString& cd(QString str)
{
    QString* file_res = new QString;

    if(str == ".")
    {
        while(!qs.empty())
        {
            file_res->prepend("/").prepend(qs.pop());
        }

        return *file_res;
    }

    if(str == "..")
    {
        qs.pop();
        while(!qs.empty())
        {
            file_res->prepend("/").prepend(qs.pop());
        }

        return *file_res;
    }

    while(!qs.empty())
    {
        file_res->prepend("/").prepend(qs.pop());
    }
    file_res->append(str);
    return *file_res;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString filepath = "/usr/include/dir1/dir2";

    qs = makestack(filepath);
    QString filepath_cd = cd(".");
    qDebug() << filepath_cd;

    qs = makestack(filepath_cd);
    filepath_cd = cd("..");
    qDebug() << filepath_cd;

    qs = makestack(filepath_cd);
    filepath_cd = cd("..");
    qDebug() << filepath_cd;

    qs = makestack(filepath_cd);
    filepath_cd = cd("dir1");
    qDebug() << filepath_cd;

    qs = makestack(filepath_cd);
    filepath_cd = cd("dir2");
    qDebug() << filepath_cd;


    qs = makestack(filepath_cd);
    filepath_cd = cd("dir3");
    qDebug() << filepath_cd;
    return a.exec();
}
