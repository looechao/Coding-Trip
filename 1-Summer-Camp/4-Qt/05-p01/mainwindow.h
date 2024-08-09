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
    void on_btn_clicked();

    void on_actionopen_triggered();

    void on_pushButton_clicked();

    void do_radiobtn_clicked();

    void do_checkbtn_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    Qt::WindowFlags _type;
    Qt::WindowFlags _hints;
};
#endif // MAINWINDOW_H
