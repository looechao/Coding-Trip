#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化好友列表
    friendList << "张三" << "李四" << "王五";

    // 创建模型
    friendModel = new QStringListModel(this);
    friendModel->setStringList(friendList);

    // 创建 QListView
    friendListView = new QListView(this);
    friendListView->setModel(friendModel);

    // 创建添加好友按钮
    QPushButton *addButton = new QPushButton("添加好友", this);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addFriend);

    // 创建布局并添加控件
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(friendListView);
    layout->addWidget(addButton);

    // 创建一个中央窗口部件并设置布局
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addFriend()
{
    // 添加新好友的名字
    QString newFriend = "新好友 " + QString::number(friendList.size() + 1);
    friendList.append(newFriend);  // 将名字添加到列表
    friendModel->setStringList(friendList);  // 更新模型
}
