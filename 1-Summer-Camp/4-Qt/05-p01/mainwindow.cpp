#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QDebug>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->radioButton, &QPushButton::clicked, this, &MainWindow::do_radiobtn_clicked);
    QObject::connect(ui->radioButton_2, &QPushButton::clicked, this, &MainWindow::do_radiobtn_clicked);
    QObject::connect(ui->radioButton_7, &QPushButton::clicked, this, &MainWindow::do_radiobtn_clicked);
    QObject::connect(ui->radioButton_8, &QPushButton::clicked, this, &MainWindow::do_radiobtn_clicked);
    QObject::connect(ui->radioButton_10, &QPushButton::clicked, this, &MainWindow::do_radiobtn_clicked);
    QObject::connect(ui->radioButton_9, &QPushButton::clicked, this, &MainWindow::do_radiobtn_clicked);
    QObject::connect(ui->radioButton_11, &QPushButton::clicked, this, &MainWindow::do_radiobtn_clicked);
    QObject::connect(ui->radioButton_12, &QPushButton::clicked, this, &MainWindow::do_radiobtn_clicked);


    QObject::connect(ui->checkBox, &QPushButton::clicked, this, &MainWindow::do_checkbtn_clicked);
    QObject::connect(ui->checkBox_2, &QPushButton::clicked, this, &MainWindow::do_checkbtn_clicked);
    QObject::connect(ui->checkBox_3, &QPushButton::clicked, this, &MainWindow::do_checkbtn_clicked);
    QObject::connect(ui->checkBox_4, &QPushButton::clicked, this, &MainWindow::do_checkbtn_clicked);
    QObject::connect(ui->checkBox_5, &QPushButton::clicked, this, &MainWindow::do_checkbtn_clicked);
    QObject::connect(ui->checkBox_8, &QPushButton::clicked, this, &MainWindow::do_checkbtn_clicked);
    QObject::connect(ui->checkBox_9, &QPushButton::clicked, this, &MainWindow::do_checkbtn_clicked);
    QObject::connect(ui->checkBox_10, &QPushButton::clicked, this, &MainWindow::do_checkbtn_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_clicked()
{
//    QString filepath = QFileDialog::getOpenFileName(this,
//                                                    tr("Open File"),
//                                                    "QString()",
//                                                    tr("*.c *.cc *.cpp"));

//    QString filepath = QFileDialog::getSaveFileName(
//                this,
//                "title",
//                QString()
//                );
//    qDebug() << filepath;

    bool *ok = new bool;
    QFont font = QFontDialog::getFont(ok, this);
    qDebug() << "font = " << ok;

}

void MainWindow::on_actionopen_triggered()
{
    QString filepath = QFileDialog::getOpenFileName(this,
                                                    tr("Open file"),
                                                    "QString()",
                                                    tr("*.c *.cc *.cpp"));
}

void MainWindow::on_pushButton_clicked()
{
    QWidget *newWindow = new QWidget(this, _type | _hints);
    newWindow->resize(400,400);
    newWindow->show();
}

void MainWindow::do_radiobtn_clicked()
{
    QRadioButton* rbtn = qobject_cast<QRadioButton *> (sender());
    if( rbtn->text() == "Window"){
        _type = Qt::Window;
    }
    if( rbtn->text() == "Popup"){
        _type = Qt::Popup;
    }
    if( rbtn->text() == "Dialog"){
        _type = Qt::Dialog;
    }
    if( rbtn->text() == "Tool"){
        _type = Qt::Tool;
    }
    if( rbtn->text() == "Sheet"){
        _type = Qt::Sheet;
    }
    if( rbtn->text() == "Tooltip"){
        _type = Qt::ToolTip;
    }
    if( rbtn->text() == "Drawer"){
        _type = Qt::Drawer;
    }
    if( rbtn->text() == "Splash screen"){
        _type = Qt::SplashScreen;
    }
}


void MainWindow::do_checkbtn_clicked(bool checked)
{
    QCheckBox* cbox = qobject_cast<QCheckBox *> (sender());

    if (cbox->text() == "WindowTitleHint") {
        if (checked) {
            _hints |= Qt::WindowTitleHint;
        } else {
            _hints &= ~Qt::WindowTitleHint; // 取消选择时移除标志
        }
    }
    if (cbox->text() == "WindowStaysOnTopHint") {
        if (checked) {
            _hints |= Qt::WindowStaysOnTopHint;
        } else {
            _hints &= ~Qt::WindowStaysOnTopHint; // 取消选择时移除标志
        }
    }
    if (cbox->text() == "WindowCloseButtonHint") {
        if (checked) {
            _hints |= Qt::WindowCloseButtonHint;
        } else {
            _hints &= ~Qt::WindowCloseButtonHint; // 取消选择时移除标志
        }
    }
    if (cbox->text() == "WindowMaximizeButtonHint") {
        if (checked) {
            _hints |= Qt::WindowMaximizeButtonHint;
        } else {
            _hints &= ~Qt::WindowMaximizeButtonHint; // 取消选择时移除标志
        }
    }
    if (cbox->text() == "WindowMinimizeButtonHint") {
        if (checked) {
            _hints |= Qt::WindowMinimizeButtonHint;
        } else {
            _hints &= ~Qt::WindowMinimizeButtonHint; // 取消选择时移除标志
        }
    }

    if (cbox->text() == "WindowSystemMenuHint") {
        if (checked) {
            _hints |= Qt::WindowSystemMenuHint;
        } else {
            _hints &= ~Qt::WindowSystemMenuHint; // 取消选择时移除标志
        }
    }
    if (cbox->text() == "FramelessWindowHint") {
        if (checked) {
            _hints |= Qt::FramelessWindowHint;
        } else {
            _hints &= ~Qt::FramelessWindowHint; // 取消选择时移除标志
        }
    }
    if (cbox->text() == "NoDropShadowWindowHint") {
        if (checked) {
            _hints |= Qt::NoDropShadowWindowHint;
        } else {
            _hints &= ~Qt::NoDropShadowWindowHint; // 取消选择时移除标志
        }
    }
}
