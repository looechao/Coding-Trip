#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
: QWidget(parent)
,posX(600)
,posY(400)
,score(0)
{
    myLabel = new QLabel(QString("score: %1").arg(score), this);

    myLabel->setAlignment(Qt::AlignCenter);

    // 创建布局管理器
    QVBoxLayout *layout = new QVBoxLayout(this);  // 使用垂直布局
    layout->addWidget(myLabel);  // 将 QLabel 添加到布局中

    // 将布局添加到窗口
    layout->addStretch();  // 添加伸缩空间以居中 QLabel
    setLayout(layout);  // 设置布局
}



void MyWidget::paintEvent(QPaintEvent *ev) {
    //只有在handler里面，才可以做绘制相关的事情
    //绘制一个蚊子
    QPixmap pixmap(":/new/prefix1/images/mos.png");
    //通过画笔绘制图像
    QPainter painter(this);
    painter.drawPixmap(posX, posY, 50, 50, pixmap);
}

