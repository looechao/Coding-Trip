#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->btn1, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->btn2, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->btn3, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->btn4, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->btn5, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->btn6, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->btn7, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->btn8, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->btn9, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->btn1->setText("");
    ui->btn2->setText("");
    ui->btn3->setText("");
    ui->btn4->setText("");
    ui->btn5->setText("");
    ui->btn6->setText("");
    ui->btn7->setText("");
    ui->btn8->setText("");
    ui->btn9->setText("");
    buttonStack.clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(buttonStack.size() > 0)
    {
        buttonStack.pop()->setText("");
    }
}
