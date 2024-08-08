#include "awidget.h"

AWidget::AWidget(QWidget *parent) : BWidget(parent) {
    setFixedSize(200, 150); // 设置 AWidget 的大小
    setStyleSheet("background-color: lightgreen;"); // 设置背景颜色
}
