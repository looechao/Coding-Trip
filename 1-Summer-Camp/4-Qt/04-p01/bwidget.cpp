#include "bwidget.h"

BWidget::BWidget(QWidget *parent) : MyWidget(parent) {
    setFixedSize(300, 200); // 设置 BWidget 的大小
    setStyleSheet("background-color: lightblue;"); // 设置背景颜色
}
