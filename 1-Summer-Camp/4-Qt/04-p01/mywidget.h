#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QEvent>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    bool event(QEvent *ev) override{
        qDebug() << ev->type();
        return QWidget::event(ev); //在派生类当中调用基类的虚函数
    }
signals:

};

#endif // MYWIDGET_H
