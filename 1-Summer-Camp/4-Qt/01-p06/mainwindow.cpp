#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStack>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(do_pushButton_2_clicked()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(do_pushButton_3_clicked()));
    QObject::connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(do_pushButton_4_clicked()));
    QObject::connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(do_pushButton_5_clicked()));
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(do_pushButton_6_clicked()));
    QObject::connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(do_pushButton_7_clicked()));
    QObject::connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(do_pushButton_8_clicked()));
    QObject::connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(do_pushButton_9_clicked()));
    QObject::connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(do_pushButton_10_clicked()));
    QObject::connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(do_pushButton_11_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

QStack<QPushButton*> buttonStack;

void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->text() == "")
    {
        if(buttonStack.size() % 2 == 0)
        {
            ui->pushButton->setText("O");
        }else{
            ui->pushButton->setText("X");
        }
        buttonStack.push(ui->pushButton);
    }
}

void MainWindow::do_pushButton_2_clicked()
{
    if(ui->pushButton_2->text() == "")
    {
        if(buttonStack.size() % 2 == 0)
        {
            ui->pushButton_2->setText("O");
        }else{
            ui->pushButton_2->setText("X");
        }
        buttonStack.push(ui->pushButton_2);
    }
}

void MainWindow::do_pushButton_3_clicked()
{
    if(ui->pushButton_3->text() == "")
    {
        if(buttonStack.size() % 2 == 0)
        {
            ui->pushButton_3->setText("O");
        }else{
            ui->pushButton_3->setText("X");
        }
        buttonStack.push(ui->pushButton_3);
    }
}

void MainWindow::do_pushButton_4_clicked()
{
    if(ui->pushButton_4->text() == "")
    {
        if(buttonStack.size() % 2 == 0)
        {
            ui->pushButton_4->setText("O");
        }else{
            ui->pushButton_4->setText("X");
        }
        buttonStack.push(ui->pushButton_4);
    }
}

void MainWindow::do_pushButton_5_clicked()
{
    if(ui->pushButton_5->text() == "")
    {
        if(buttonStack.size() % 2 == 0)
        {
            ui->pushButton_5->setText("O");
        }else{
            ui->pushButton_5->setText("X");
        }
        buttonStack.push(ui->pushButton_5);
    }
}

void MainWindow::do_pushButton_6_clicked()
{
    if(ui->pushButton_6->text() == "")
    {
        if(buttonStack.size() % 2 == 0)
        {
            ui->pushButton_6->setText("O");
        }else{
            ui->pushButton_6->setText("X");
        }
        buttonStack.push(ui->pushButton_6);
    }
}

void MainWindow::do_pushButton_7_clicked()
{
    if(ui->pushButton_7->text() == "")
    {
        if(buttonStack.size() % 2 == 0)
        {
            ui->pushButton_7->setText("O");
        }else{
            ui->pushButton_7->setText("X");
        }
        buttonStack.push(ui->pushButton_7);
    }
}

void MainWindow::do_pushButton_8_clicked()
{
    if(ui->pushButton_8->text() == "")
    {
        if(buttonStack.size() % 2 == 0)
        {
            ui->pushButton_8->setText("O");
        }else{
            ui->pushButton_8->setText("X");
        }
        buttonStack.push(ui->pushButton_8);
    }
}

void MainWindow::do_pushButton_9_clicked()
{
    if(ui->pushButton_9->text() == "")
    {
        if(buttonStack.size() % 2 == 0)
        {
            ui->pushButton_9->setText("O");
        }else{
            ui->pushButton_9->setText("X");
        }
        buttonStack.push(ui->pushButton_9);
    }
}

void MainWindow::do_pushButton_10_clicked()
{
    ui->pushButton->setText("");
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");
    buttonStack.clear();
}

void MainWindow::do_pushButton_11_clicked()
{
    if(buttonStack.size() > 0)
    {
        buttonStack.pop()->setText("");
    }
}


