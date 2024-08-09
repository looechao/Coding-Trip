#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QListView>
#include <QPushButton>
#include <QVBoxLayout>

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
    void addFriend(); // 槽函数，用于添加新好友

private:
    Ui::MainWindow *ui;
    QListView *friendListView;        // 用于显示好友列表的视图
    QStringListModel *friendModel;    // 模型
    QStringList friendList;            // 好友列表
};

#endif // MAINWINDOW_H
