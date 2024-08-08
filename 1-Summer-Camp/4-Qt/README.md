# 01

根据如下ui绘制一个计算器，先不实现计算的功能，只实现显示表达式和编辑表达式的功能

QString的append方法可以追加一个字符





实现一个井字棋 点击空白按钮可以显示'X'或者'O'

 

# 02

1. **书写一个函数MyIntersection，可以支持两个相同的QList或者QSet的取交集的操作，返回新集合。**
   **书写一个函数MyOdd，可以将一个QMap<int,int>的所有奇数的键或者是值搜集起来，返回新QList。**

  ```cpp
#include "mainwindow.h"

#include <QApplication>

#include <QDebug>

#include <QList>

#include <QSet>

#include <QMap>

QList<int>& Myintersection(QList<int>& ql, QSet<int>& qs)
{
    QList<int>* res = new QList<int>;
    for(auto &it : ql){
        if(qs.contains(it)){
            res->append(it);
        }
    }
    return *res;
}

QList<int>& MyOdd(QMap<int, int>& qm)
{
    QList<int>* res = new QList<int>;
    for(auto &it : qm)
    {
        if(it % 2 != 0)
        {
            res->append(it);
        }
        if(qm.key(it) %2 != 0)
        {
            res->append(qm.key(it));
        }
    }
    return *res;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "hello world!";
    QList<int> ql1 = {1, 2, 3, 4, 5};
    QSet<int> b = {1, 2, 4, 9, 10};
    QList<int> res = Myintersection(ql1, b);
    QMap<int, int> qm;
    qm.insert(8, 9);
    qm.insert(3, 7);
    qm.insert(6, 4);
    QList<int> res2 = MyOdd(qm);
    qDebug() << res;
    qDebug() << res2;
    return a.exec();
}
  ```

2. **给出一个路径'/usr/include/dir1/dir2'：**

   - **将路径切割并存入一个栈中。**

   - **实现cd 子目录和cd 上一级功能，返回路径的字符串。**

   ```cpp
   #include "mainwindow.h"
   
   #include <QApplication>
   #include <QString>
   #include <QDebug>
   #include <QStack>
   
   QStack<QString> qs;
   
   QStack<QString>& makestack(QString filepath){
       QStack<QString>* res = new QStack<QString>;
       QStringList list = filepath.split("/");
       for(int i = 0; i < list.size(); i++)
       {
           if(list[i] != "")
           {
               res->push(list[i]);
           }
       }
       return *res;
   }
   
   QString& cd(QString str)
   {
       QString* file_res = new QString;
   
       if(str == ".")
       {
           while(!qs.empty())
           {
               file_res->prepend("/").prepend(qs.pop());
           }
   
           return *file_res;
       }
   
       if(str == "..")
       {
           qs.pop();
           while(!qs.empty())
           {
               file_res->prepend("/").prepend(qs.pop());
           }
   
           return *file_res;
       }
   
       while(!qs.empty())
       {
           file_res->prepend("/").prepend(qs.pop());
       }
       file_res->append(str);
       return *file_res;
   }
   
   int main(int argc, char *argv[])
   {
       QApplication a(argc, argv);
       QString filepath = "/usr/include/dir1/dir2";
   
       qs = makestack(filepath);
       QString filepath_cd = cd(".");
       qDebug() << filepath_cd;
   
       qs = makestack(filepath_cd);
       filepath_cd = cd("..");
       qDebug() << filepath_cd;
   
       qs = makestack(filepath_cd);
       filepath_cd = cd("..");
       qDebug() << filepath_cd;
   
       qs = makestack(filepath_cd);
       filepath_cd = cd("dir1");
       qDebug() << filepath_cd;
   
       qs = makestack(filepath_cd);
       filepath_cd = cd("dir2");
       qDebug() << filepath_cd;
   
   
       qs = makestack(filepath_cd);
       filepath_cd = cd("dir3");
       qDebug() << filepath_cd;
       return a.exec();
   }
   ```

3. **实现一个井字棋 点击空白按钮可以显示'X'或者'O'**
   **使用sender和qobject_cast改写一下**

   ```CPP
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
   
   ```

4. **使用元对象系统的注意事项有哪些？**

   1. 继承OBject,第一个基类
   2. 使用Q_OBJECT宏函数
   3. 使用元对象的类不能放在main.cpp

5. **信号和槽机制的目的是什么？**

   目的是实现对象间的通信

   **书写代码实现一个自定义信号和自定义槽函数。**

   ```cpp
   #include <QObject>
   #include <QDebug>
   
   class MyClass : public QObject
   {
       Q_OBJECT
   
   public:
       MyClass(QObject *parent = nullptr) : QObject(parent) {}
   
   signals:
       void mySignal();
   
   public slots:
       void mySlot()
       {
           qDebug() << "Slot called!";
       }
   };
   
   int main(int argc, char *argv[])
   {
       QCoreApplication app(argc, argv);
   
       MyClass obj1;
       MyClass obj2;
   
       QObject::connect(&obj1, &MyClass::mySignal, &obj2, &MyClass::mySlot);
   
       emit obj1.mySignal();
   
       return app.exec();
   }
   ```

   

6. **connect函数有几种重载形式？哪一种更好为什么？**

   1. **基于函数指针的连接**：

      cpp

      Copy code

      ```
      connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));
      ```

   2. **基于`QMetaObject::Connection`的连接**：

      cpp

      Copy code

      ```
      QMetaObject::Connection connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection);
      ```

   3. **基于`Functor`的连接**（C++11及以上）：

      cpp

      Copy code

      ```
      connect(sender, &QObject::signal, receiver, &QObject::slot);
      ```

   4. **基于`Lambda`表达式的连接**（C++11及以上）：

      cpp

      Copy code

      ```
      connect(sender, &QObject::signal, [=](){ /* lambda code */ });
      ```

      基于`Functor`的连接（第三种）通常被认为是更好的选择，原因如下：

      - **类型安全**：基于函数指针的连接在编译时不会进行类型检查，而基于`Functor`的连接在编译时会进行类型检查，减少了运行时错误的可能性。
      - **性能**：基于`Functor`的连接通常比基于函数指针的连接更快，因为它避免了字符串比较和查找。
      - **简洁性**：基于`Functor`的连接代码更简洁，易于阅读和维护。

7. **现在有三个对象A，B，C**

   **需要实现下面效果：**

   **A发射信号会导致 B调用槽函数 C调用槽函数**

   **B发射信号会导致 C调用槽函数**

   **C发射信号会导致 A发射信号**

   ```cpp
   #include <QObject>
   #include <QDebug>
   
   class A : public QObject
   {
       Q_OBJECT
   
   public:
       A(QObject *parent = nullptr) : QObject(parent) {}
   
   signals:
       void signalA();
   
   public slots:
       void slotA()
       {
           qDebug() << "A's slot called!";
           emit signalA();
       }
   };
   
   class B : public QObject
   {
       Q_OBJECT
   
   public:
       B(QObject *parent = nullptr) : QObject(parent) {}
   
   signals:
       void signalB();
   
   public slots:
       void slotB()
       {
           qDebug() << "B's slot called!";
           emit signalB();
       }
   };
   
   class C : public QObject
   {
       Q_OBJECT
   
   public:
       C(QObject *parent = nullptr) : QObject(parent) {}
   
   signals:
       void signalC();
   
   public slots:
       void slotC()
       {
           qDebug() << "C's slot called!";
           emit signalC();
       }
   };
   
   int main(int argc, char *argv[])
   {
       QCoreApplication app(argc, argv);
   
       A a;
       B b;
       C c;
   
       QObject::connect(&a, &A::signalA, &b, &B::slotB);
       QObject::connect(&a, &A::signalA, &c, &C::slotC);
       QObject::connect(&b, &B::signalB, &c, &C::slotC);
       QObject::connect(&c, &C::signalC, &a, &A::signalA);
   
       emit a.signalA();
   
       return app.exec();
   }
   ```


# 04

**现在有三个对象ABC，A的父亲是B，B的父亲是C**

**点击A的内部，要求执行：**

**A的filter、event和event_handler**

**B的filter、event**

> ```cpp
> #include <QApplication>
> #include <QMainWindow>
> #include <QFrame>
> #include <QPushButton>
> #include <QVBoxLayout>
> #include <QDebug>
> #include <QMouseEvent>
> 
> class A : public QPushButton {
>     Q_OBJECT
> public:
>     A(QWidget *parent = nullptr) : QPushButton("Button A (Click Me)", parent) {
>         // 安装事件过滤器
>         installEventFilter(this);
>     }
> 
> protected:
>     bool eventFilter(QObject *obj, QEvent *event) override {
>         if (event->type() == QEvent::MouseButtonPress) {
>             qDebug() << "A's event filter triggered";
>         }
>         return QPushButton::eventFilter(obj, event);  // 继续事件处理
>     }
> 
>     void mousePressEvent(QMouseEvent *event) override {
>         qDebug() << "A's mousePressEvent";
>         QPushButton::mousePressEvent(event);  // 调用基类处理
>     }
> };
> 
> class B : public QFrame {
>     Q_OBJECT
> public:
>     B(QWidget *parent = nullptr) : QFrame(parent) {
>         setFrameStyle(QFrame::StyledPanel);
>         setStyleSheet("background-color: lightblue;"); // 设置背景颜色
>         QVBoxLayout *layout = new QVBoxLayout(this);
>         layout->addWidget(new A(this));  // 添加 A
>         setLayout(layout);
>     }
> 
> protected:
>     bool event(QEvent *event) override {
>         if (event->type() == QEvent::MouseButtonPress) {
>             qDebug() << "B's event triggered";
>         }
>         return QFrame::event(event);  // 继续事件处理
>     }
> };
> 
> class C : public QMainWindow {
>     Q_OBJECT
> public:
>     C(QWidget *parent = nullptr) : QMainWindow(parent) {
>         setWindowTitle("Event Propagation Example");
>         setFixedSize(400, 300);
>         
>         B *b = new B(this);  // 创建 B
>         setCentralWidget(b);  // 设置 B 为中心控件
>         
>         // 设置窗口的背景颜色
>         setStyleSheet("background-color: lightgray;");
>     }
> };
> 
> int main(int argc, char *argv[]) {
>     QApplication app(argc, argv);
>     C c;  // 创建主窗口 C
>     c.show();  // 显示窗口
>     return app.exec();  // 进入应用程序主循环
> }
> 
> #include "main.moc"
> ```



**实现一个“打蚊子”游戏**

**在屏幕中央有一个600*400的QWidget，一个用来统计分数的QLabel**

**一开始会在QWidget内部随机位置生成一个蚊子，当鼠标点击到蚊子以后，旧蚊子消失然后在另一个位置生成新的蚊子，分数增加。**

**提示：这里需要继承QWidget类然后重写paintEvent，在paintEvent当中可以创建QPainter对象绘制各种图形和图片**

> ```cpp
> class MyWidget : public QWidget
> {
>     Q_OBJECT
> public:
>     explicit MyWidget(QWidget *parent = nullptr);
>     void paintEvent(QPaintEvent *ev);
>     void mouseReleaseEvent(QMouseEvent *ev) override{
>         if (ev->button() == Qt::LeftButton) {
>                    // 检查点击是否在蚊子区域内
>                    if (ev->x() >= posX && ev->x() <= posX + 50 &&
>                        ev->y() >= posY && ev->y() <= posY + 50) {
>                        // 生成随机位置
>                        posX = QRandomGenerator::global()->bounded(width() - 50);
>                        posY = QRandomGenerator::global()->bounded(height() - 50);
> 
>                        // 请求重新绘制
>                        score++;
>                        qDebug() << score;
>                        myLabel->setText(QString("score: %1").arg(score));
>                        update();
>                    }
>         }
>     }
> 
> private:
>     QLabel *myLabel;
>     int posX; //蚊子图片的x坐标
>     int posY; //蚊子图片的y坐标
>     int score; //积分
> signals:
> 
> };
> ```



**什么是窗口？怎么样创建一个窗口**

> ### 使用 Qt 创建一个基本窗口的步骤
>
> 1. **安装 Qt**：确保您已经安装了 Qt 和 Qt Creator。
> 2. **创建一个新的 Qt Widgets Application**：
>    - 打开 Qt Creator。
>    - 选择“File” -> “New File or Project”。
>    - 选择“Qt Widgets Application”，然后点击“Choose”。
>    - 填写项目名称和路径，点击“Next”。
>    - 选择合适的 Qt 版本和构建套件，点击“Next”。
>    - 点击“Finish”完成项目创建。