#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QtWidgets/QtWidgets>
#include <QDebug>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev) override{
        if (ev->button() == Qt::LeftButton) {
                   // 检查点击是否在蚊子区域内
                   if (ev->x() >= posX && ev->x() <= posX + 50 &&
                       ev->y() >= posY && ev->y() <= posY + 50) {
                       // 生成随机位置
                       posX = QRandomGenerator::global()->bounded(width() - 50);
                       posY = QRandomGenerator::global()->bounded(height() - 50);

                       // 请求重新绘制
                       score++;
                       qDebug() << score;
                       myLabel->setText(QString("score: %1").arg(score));
                       update();
                   }
        }
    }

private:
    QLabel *myLabel;
    int posX; //蚊子图片的x坐标
    int posY; //蚊子图片的y坐标
    int score; //积分
signals:

};

#endif // MYWIDGET_H
