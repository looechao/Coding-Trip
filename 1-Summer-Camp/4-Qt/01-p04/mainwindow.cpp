#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_3,SIGNAL(clicked()), this, SLOT(do_pushButton_3_clicked()));
    QObject::connect(ui->pushButton_4,SIGNAL(clicked()), this, SLOT(do_pushButton_4_clicked()));
    QObject::connect(ui->pushButton_5,SIGNAL(clicked()), this, SLOT(do_pushButton_5_clicked()));
    QObject::connect(ui->pushButton_6,SIGNAL(clicked()), this, SLOT(do_pushButton_6_clicked()));
    QObject::connect(ui->pushButton_7,SIGNAL(clicked()), this, SLOT(do_pushButton_7_clicked()));
    QObject::connect(ui->pushButton_8,SIGNAL(clicked()), this, SLOT(do_pushButton_8_clicked()));
    QObject::connect(ui->pushButton_9,SIGNAL(clicked()), this, SLOT(do_pushButton_9_clicked()));
    QObject::connect(ui->pushButton_0,SIGNAL(clicked()), this, SLOT(do_pushButton_0_clicked()));
    QObject::connect(ui->pushButton_add,SIGNAL(clicked()), this, SLOT(do_pushButton_add_clicked()));
    QObject::connect(ui->pushButton_minus,SIGNAL(clicked()), this, SLOT(do_pushButton_minus_clicked()));
    QObject::connect(ui->pushButton_cross,SIGNAL(clicked()), this, SLOT(do_pushButton_cross_clicked()));
    QObject::connect(ui->pushButton_divide,SIGNAL(clicked()), this, SLOT(do_pushButton_divide_clicked()));
    QObject::connect(ui->pushButton_equal,SIGNAL(clicked()), this, SLOT(do_pushButton_equal_clicked()));
    QObject::connect(ui->pushButton_del,SIGNAL(clicked()), this, SLOT(do_pushButton_del_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_1_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("1"));
    }else{
        ui->label->setText(ui->label->text().append("1"));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("2"));
    }else{
        ui->label->setText(ui->label->text().append("2"));
    }
}


void MainWindow::do_pushButton_3_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("3"));
    }else{
        ui->label->setText(ui->label->text().append("3"));
    }
}


void MainWindow::do_pushButton_4_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("4"));
    }else{
        ui->label->setText(ui->label->text().append("4"));
    }
}

void MainWindow::do_pushButton_5_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("5"));
    }else{
        ui->label->setText(ui->label->text().append("5"));
    }
}


void MainWindow::do_pushButton_6_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("6"));
    }else{
        ui->label->setText(ui->label->text().append("6"));
    }
}


void MainWindow::do_pushButton_7_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("7"));
    }else{
        ui->label->setText(ui->label->text().append("7"));
    }
}

void MainWindow::do_pushButton_8_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("8"));
    }else{
        ui->label->setText(ui->label->text().append("8"));
    }
}


void MainWindow::do_pushButton_9_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("9"));
    }else{
        ui->label->setText(ui->label->text().append("9"));
    }
}

void MainWindow::do_pushButton_0_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("0"));
    }else{
        ui->label->setText(ui->label->text().append("0"));
    }
}

void MainWindow::do_pushButton_del_clicked()
{
    ui->label->setText("plese input here...");
}

void MainWindow::do_pushButton_add_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("+"));
    }else{
        ui->label->setText(ui->label->text().append("+"));
    }
}

void MainWindow::do_pushButton_minus_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("-"));
    }else{
        ui->label->setText(ui->label->text().append("-"));
    }
}

void MainWindow::do_pushButton_cross_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("×"));
    }else{
        ui->label->setText(ui->label->text().append("×"));
    }
}

void MainWindow::do_pushButton_divide_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("÷"));
    }else{
        ui->label->setText(ui->label->text().append("÷"));
    }
}

void MainWindow::do_pushButton_equal_clicked()
{
    if(ui->label->text() == "plese input here..."){
        ui->label->setText("plese input here...");
    }else{
        ui->label->setText("");
        ui->label->setText(ui->label->text().append("0"));
    }
}




