#ifndef BWIDGET_H
#define BWIDGET_H

#include "mywidget.h"

class BWidget : public MyWidget
{
    Q_OBJECT

public:
    explicit BWidget(QWidget *parent = nullptr);

protected:
    bool event(QEvent *ev) override {
        qDebug() << "BWidget event:" << ev->type();
        return MyWidget::event(ev); // 调用基类的事件处理
    }
};

#endif // BWIDGET_H
