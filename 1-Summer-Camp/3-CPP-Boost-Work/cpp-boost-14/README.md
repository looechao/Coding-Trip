ReactorV2版本特征：

1、封装了IO多路复用epoll的三个函数，这三个函数的封装，希望大家写出来，目的是熟悉epoll的使用

2、TCP网络通信过程中的三个事件是什么？连接建立、连接断开、消息到达（文件描述符可读），三个事件使用回调函数的写法，注册回调函数与执行回调函数。（这是一个难点，大家重点关注，搞懂并封装出来）

3、三个事件都是与TcpConnection相关的，但是需要通过EventLoop中转，因为TcpConnection是在EventLoop中创建出来的，所以EventLoop只中转，只注册不执行，但是TcpConnection既要注册也要执行

4、其他语法特性：键值对map或者unordered_map、智能指针以及智能指针的误用

搞清楚上述几点后，将ReactorV2的流程搞清楚，然后自己独立实现出来
