#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();

    void do_pushButton_2_clicked();

    void do_pushButton_3_clicked();

    void do_pushButton_4_clicked();

    void do_pushButton_5_clicked();

    void do_pushButton_6_clicked();

    void do_pushButton_7_clicked();

    void do_pushButton_8_clicked();

    void do_pushButton_9_clicked();

    void do_pushButton_10_clicked();

    void do_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
