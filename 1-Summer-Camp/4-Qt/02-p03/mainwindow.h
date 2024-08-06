#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include <QStack>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void do_btn_clicked(){
        QPushButton * btn = qobject_cast<QPushButton *> (sender());
        if(btn->text() == "" && buttonStack.size()%2 == 0)
        {
            btn->setText("O");
            buttonStack.push_back(btn);
        };
        if(btn->text() == "" && buttonStack.size()%2 != 0)
        {
            btn->setText("X");
            buttonStack.push_back(btn);
        };
    }
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QStack<QPushButton*> buttonStack;

};
#endif // MAINWINDOW_H
