#ifndef AWIDGET_H
#define AWIDGET_H

#include "bwidget.h"

class AWidget : public BWidget
{
    Q_OBJECT

public:
    explicit AWidget(QWidget *parent = nullptr);

protected:
    bool event(QEvent *ev) override {
        qDebug() << "AWidget event:" << ev->type();
        return BWidget::event(ev); // 调用基类的事件处理
    }
};

#endif // AWIDGET_H
