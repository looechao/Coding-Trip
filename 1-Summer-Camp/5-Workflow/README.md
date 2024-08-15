# 01
**Nginx和Apache最大区别是什么？**

> Apache 是基于进程或线程的，会为每一个请求分配一个线程
>
> Nginx是基于异步事件驱动架构的，可同时处理大量链接而不会为每个连接分配单独的进程或线程

> 因此Nginx更加简单，性能更好
>
> 而Apache适合处理连接数量不多但是每个连接处理业务很麻烦的场景

---

**使用Nginx部署一个产品的帮助文档服务器。**

![](./assets/01-04.png)

---

**阅读下面的链接**

**[9.3 高性能网络模式：Reactor 和 Proactor | 小林coding (xiaolincoding.com)](https://www.xiaolincoding.com/os/8_network_system/reactor.html#演进)**

```mermaid
graph LR
A[高性能网络模式] --> B[Reactor模式]
A --> C[Proactor模式]
A --> D[总结与应用]

B --> |定义| B1[事件驱动模式]
B1 --> B1a[非阻塞同步网络模式]
B --> |演进| B2[多线程与资源复用]
B2 --> B2a[I/O多路复用技术]
B --> |核心组成| B3[Reactor与处理资源池]
B3 --> B3a[事件监听与分发]
B3 --> B3b[业务逻辑处理]
B --> |实现方案| B4[方案类型]
B4 --> B4a[单Reactor单进程/线程]
B4 --> B4b[单Reactor多线程/进程]
B4 --> B4c[多Reactor多进程/线程]

C --> |定义| C1[异步网络模式]
C1 --> C1a[基于已完成的I/O事件]
C --> |工作流程| C2[Proactor流程]
C2 --> C2a[Proactor Initiator]
C2 --> C2b[Asynchronous Operation Processor]
C2 --> C2c[事件回调Handler]
C --> |平台支持| C3[操作系统支持]
C3 --> C3a[Linux的局限性]
C3 --> C3b[Windows的IOCP]

D --> |Reactor方案| D1[不同Reactor方案]
D1 --> D1a[单Reactor单进程/线程]
D1 --> D1b[单Reactor多线程]
D1 --> D1c[多Reactor多进程/线程]
D --> |Proactor优势| D2[异步I/O优势]
D2 --> D2a[操作系统自动处理]
D --> |实际应用| D3[应用示例]
D3 --> D3a[Redis]
D3 --> D3b[Netty]
D3 --> D3c[Memcache]
D3 --> D3d[Nginx]
```





---

**有哪些负载均衡策略？各有什么优缺点？**

1. 轮询\随机访问：每次都是从第一个开始轮询访问，效率太低，不能充分利用缓存

   <img src="./assets/01-01.png" style="zoom: 33%;" />

2. 利用hash策略，可以让每次访问的后端固定（提高了利用率，但是还是会产生雪崩效应）

   <img src="./assets/01-02.png" style="zoom:33%;" />

3. 改用环形哈希（一致性哈希），防止了缓存大面积失效

   <img src="./assets/01-03.png" style="zoom:33%;" />



**尝试给下面的代码补充一下注释**

```cpp
// WaitGroup 让某个线程处于等待状态
#include <workflow/WFFacilities.h>
// WFTaskFactory.h文件里面包含了所有创建任务相关的函数
#include <workflow/WFTaskFactory.h>
// HttpUtil.h 文件包含了处理HTTP的工具
#include <workflow/HttpUtil.h>
#include <iostream>
#include <string>
#include <signal.h>
using std::cout;
using std::cerr;
using std::string;
static WFFacilities::WaitGroup waitGroup(1);
void sigHandler(int signum){
    cout << "done!\n";
    waitGroup.done();
}
void httpCallback(WFHttpTask *httpTask){
    // 检查报错
    int state = httpTask->get_state(); //获取状态
	int error = httpTask->get_error(); //获取errno
	switch (state){
	case WFT_STATE_SYS_ERROR:
		cerr << "system error: " << strerror(error) << "\n";
		break;
	case WFT_STATE_DNS_ERROR:
		cerr << "DNS error: " << gai_strerror(error) << "\n";
		break;
	case WFT_STATE_SSL_ERROR:
		cerr <<"SSL error: " << error << "\n";
		break;
	case WFT_STATE_TASK_ERROR:
		cerr <<"Task error: " << error << "\n"; 
		break;
	case WFT_STATE_SUCCESS:
		break;
	}
	if (state != WFT_STATE_SUCCESS){
		cerr << "Failed. Press Ctrl-C to exit.\n";
		return;
	}
    // 请求的信息
    protocol::HttpRequest * req = httpTask->get_req();
    cout << "http request method = " << req->get_method() << "\n";
    cout << "http request uri = " << req->get_request_uri() << "\n";
    cout << "http request version = " << req->get_http_version() << "\n";
    // 遍历首部字段
    protocol::HttpHeaderCursor reqCursor(req);
    string key,value;
    while(reqCursor.next(key,value)){
        cout << "key = " << key << " value = " << value << "\n";
    }
    // 响应的信息
    cout << "--------------------------------------------------\n";
    protocol::HttpResponse *resp = httpTask->get_resp();
    cout << "http response version = " << resp->get_http_version() << "\n";
    cout << "http response status code = " << resp->get_status_code() << "\n";
    cout << "http response reason phrase = " << resp->get_reason_phrase() << "\n";
    protocol::HttpHeaderCursor respCursor(resp);
    while(respCursor.next(key,value)){
        cout << "key = " << key << " value = " << value << "\n";
    }

    // workflow框架里面 http报文头和报文体不在一起
    const void *body; //不可修改指向的内容，可以修改指向
    size_t size;
    resp->get_parsed_body(&body,&size);
    cout << static_cast<const char *>(body) << "\n";
}
int main(){
    signal(SIGINT,sigHandler);
    WFHttpTask * httpTask = WFTaskFactory::create_http_task( // 创建任务
        "http://www.baidu.com", // url
        10, // 重定向次数上限
        10, // 重试次数
        //nullptr); //回调函数
        httpCallback); //新的回调函数
    // 在启动任务之前，设置任务的属性
    // 只能改请求，不能改响应
    protocol::HttpRequest * req = httpTask->get_req();
    req->add_header_pair("key1","value1");
    // 启动任务
    httpTask->start();
    waitGroup.wait();
    cout << "finished!\n"; 
    return 0;
}
```

这段代码使用了**Workflow**库（通常用于高并发的网络编程）来创建并执行一个 HTTP 请求。下面是对代码的详细解读，包括其结构、功能、以及如何使用它。

> ### 代码结构与功能
>
> 1. **头文件引入**：
>
>    ```cpp
>    #include <workflow/WFFacilities.h>
>    #include <workflow/WFTaskFactory.h>
>    #include <workflow/HttpUtil.h>
>    #include <iostream>
>    #include <string>
>    #include <signal.h>
>    ```
>
>    - `WFFacilities.h` 提供了等待组（`WaitGroup`）功能，用于控制主线程的等待和同步。
>    - `WFTaskFactory.h` 包含创建任务的相关函数。
>    - `HttpUtil.h` 处理 HTTP 请求和响应。
>    - `iostream` 和 `string` 用于输入输出和字符串操作。
>    - `signal.h` 用于处理信号。
>
> 2. **全局变量**：
>
>    ```cpp
>    static WFFacilities::WaitGroup waitGroup(1);
>    ```
>
>    - 创建一个 `WaitGroup` 实例，初始计数为 1，用于等待 HTTP 请求的完成。
>
> 3. **信号处理函数**：
>
>    ```cpp
>    void sigHandler(int signum){
>        cout << "done!\n";
>        waitGroup.done();
>    }
>    ```
>
>    - 当接收到 `SIGINT` 信号（通常是 Ctrl+C）时，输出 "done!"，并通知 `WaitGroup` 任务已完成。
>
> 4. **HTTP 回调函数**：
>
>    ```cpp
>    void httpCallback(WFHttpTask *httpTask){
>        // 检查报错
>        int state = httpTask->get_state(); // 获取状态
>        int error = httpTask->get_error(); // 获取错误码
>        ...
>    }
>    ```
>
>    - 该函数处理 HTTP 请求的响应，检查状态并输出请求和响应的信息。
>    - 根据不同的状态，输出相应的错误信息。
>
> 5. **主函数**：
>
>    ```cpp
>    int main(){
>        signal(SIGINT,sigHandler); // 注册信号处理函数
>        WFHttpTask * httpTask = WFTaskFactory::create_http_task( 
>            "http://www.baidu.com", // URL
>            10, // 重定向次数上限
>            10, // 重试次数
>            httpCallback); // 回调函数
>        ...
>        waitGroup.wait(); // 等待任务完成
>        cout << "finished!\n"; 
>        return 0;
>    }
>    ```
>
>    - 在主函数中，设置信号处理程序，创建 HTTP 任务，设置请求头，启动任务，并等待任务完成。
>    - 最后输出 "finished!"，表示程序执行结束。
>
> ### 主要功能详解
>
> 1. **任务创建**：
>
>    ```cpp
>    WFHttpTask * httpTask = WFTaskFactory::create_http_task(
>        "http://www.baidu.com", // URL
>        10, // 重定向次数上限
>        10, // 重试次数
>        httpCallback // 回调函数
>    );
>    ```
>
>    - 创建一个 HTTP 任务请求 `"http://www.baidu.com"`，设置重定向和重试次数，并指定回调函数处理响应。
>
> 2. **请求信息设置**：
>
>    ```cpp
>    protocol::HttpRequest * req = httpTask->get_req();
>    req->add_header_pair("key1","value1");
>    ```
>
>    - 获取请求对象，并添加一个自定义 HTTP 请求头。
>
> 3. **任务启动**：
>
>    ```cpp
>    httpTask->start();
>    ```
>
>    - 启动 HTTP 请求任务。
>
> 4. **响应处理**：
>    在 `httpCallback` 函数中，处理 HTTP 响应并输出请求和响应的详细信息，包括：
>
>    - 请求方法、URI、HTTP 版本。
>    - 请求和响应的头部信息。
>    - 响应体内容。
>
> ### 错误处理
>
> 在 `httpCallback` 函数中，使用 `switch` 语句处理请求状态，包括：
>
> - `WFT_STATE_SYS_ERROR`：系统错误
> - `WFT_STATE_DNS_ERROR`：DNS 错误
> - `WFT_STATE_SSL_ERROR`：SSL 错误
> - `WFT_STATE_TASK_ERROR`：任务错误
> - `WFT_STATE_SUCCESS`：请求成功
>
> 每种状态下，根据具体错误输出相应的信息。

---
# 02
**尝试给下面的代码补充一下注释**
```cpp
// WaitGroup 让某个线程处于等待状态
#include <workflow/WFFacilities.h>
// WFHttpServer.h 包含server类的设计
#include <workflow/WFHttpServer.h>
#include <iostream>
#include <string>
#include <signal.h>
#include <unistd.h>
using std::cout;
using std::string;
struct SeriesContext{
    string name;
    string password;
    protocol::HttpResponse *resp; // 决定了回复给客户端的内容
};
static WFFacilities::WaitGroup waitGroup(1);
void sigHandler(int signum){
    cout << "done!\n";
    waitGroup.done();
}
void redisCallback(WFRedisTask * redisTask){
    // 获取redis的执行结果
    protocol::RedisValue result;
    protocol::RedisResponse * resp = redisTask->get_resp();
    resp->get_result(result);

    // 访问context
    SeriesContext * context =  static_cast<SeriesContext *>(series_of(redisTask)->get_context());
    if(result.is_string() && result.string_value() == context->password){
        cout << context->name << " success\n";
        context->resp->append_output_body("<html>success</html>");
    }else{
        cout << context->name << " fail\n";
        context->resp->append_output_body("<html>fail</html>");
    }
}
void process(WFHttpTask *serverTask){ //回复给客户端的响应 一定是serverTask的resp决定的
    protocol::HttpRequest *req = serverTask->get_req();
    string uri = req->get_request_uri();
    cout << uri << "\n";
    // /login?username=niqiu&password=123
    string nameKV = uri.substr(0,uri.find("&"));
    string passwordKV = uri.substr(uri.find("&")+1);
    string name = nameKV.substr(nameKV.find("=")+1);
    string password = passwordKV.substr(passwordKV.find("=")+1);
    cout << "name = " << name << ", password = " << password << "\n";
    // 申请一片内存空间，用于序列内的任务共享数据
    SeriesContext * context = new SeriesContext;
    context->name = name;
    context->password = password;
    context->resp = serverTask->get_resp();
    series_of(serverTask)->set_context(context);
    // 创建一个redis任务
    WFRedisTask * redisTask = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",10,redisCallback);
    // hget 57user niqiu
    redisTask->get_req()->set_request("HGET",{"57user",name});
    series_of(serverTask)->push_back(redisTask);
}
int main(){
    signal(SIGINT,sigHandler);
    WFHttpServer server(process);
    if(server.start(12345) == 0){
        waitGroup.wait();
        server.stop();
    }
    else{
        perror("server start failed!");
        return -1;
    }
    cout << "finished!\n"; 
    return 0;
}
```

> adsf
> adsf
> adfdaf
> adfsdf

**存在下列的redis键值映射关系，使用workflow的redis任务和序列，假如只知道"x1"，如何找到最终的"100"？**
"x1" --> "x2"
"x2" --> "x3"
"x3" --> "x4"
"x4" --> "100"


**读取某个网站的内容，并且存入redis服务端当中**
**（比如先访问淘宝，再set www.taobao.com 淘宝的html内容）**


# 03

**部署一个登录网站**

**1、在redis服务端当中插入一条用户注册信息（比如 HSET USERINFO LIAO 123）**
**2、当用户向ip:port/login发生请求的时候，返回postform.html（在今日的共享目录当中有提供）静态资源**
**3、在用户获取完网页界面之后，在网页上输入用户名和密码，再点击按钮，即可产生一个POST请求**
**4、使用wireshark可以获取报文的具体格式，并且根据请求数据，返回登录的结果**





**阅读下面的代码并尝试添加注释**

```cpp
#include <workflow/WFFacilities.h>
#include <workflow/MySQLUtil.h>
#include <workflow/MySQLResult.h>
#include <iostream>
#include <signal.h>
using std::string;
using std::cerr;
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    std::cout << "signum = " << signum << "\n";
    waitGroup.done();
}
void mysqlCallback(WFMySQLTask * mysqlTask){
    if(mysqlTask->get_state() != WFT_STATE_SUCCESS){
        // 在系统层面报错，权限or密码
        cerr << "error_msg =  " << WFGlobal::get_error_string(mysqlTask->get_state(), mysqlTask->get_error()) << "\n";
        return;
    }
    protocol::MySQLResponse * resp = mysqlTask->get_resp();
    if(resp->get_packet_type() == MYSQL_PACKET_ERROR){
        // 在SQL语句报错
        cerr << "error_code = " << resp->get_error_code() << " error_msg = " << resp->get_error_msg() << "\n";
        return;
    }
    protocol::MySQLResultCursor cursor(resp);
    do{
        if(cursor.get_cursor_status() == MYSQL_STATUS_OK){
            // 写类型的SQL语句
            cerr << "write \n";
            cerr << cursor.get_affected_rows() << " rows affected\n";
        }
        else if(cursor.get_cursor_status() == MYSQL_STATUS_GET_RESULT){
            // 读类型的SQL语句
            cerr << "read \n";
            // 读表头 列的信息 field
            const protocol::MySQLField * const * fieldArr;
            fieldArr = cursor.fetch_fields();
            for(int i = 0; i < cursor.get_field_count(); ++i){
                cerr << "db = " << fieldArr[i]->get_db()
                     << " table = " << fieldArr[i]->get_table()
                     << " name = " << fieldArr[i]->get_name()
                     << " type = " << datatype2str(fieldArr[i]->get_data_type()) << "\n";
            }
            // 读表的内容 每一行每一列
            // bool fetch_all(std::vector<std::vector<MySQLCell>>& rows);
            std::vector<std::vector<protocol::MySQLCell>> rows;
            cursor.fetch_all(rows);
            for(auto &row:rows){
                for(auto &cell:row){
                    if(cell.is_int()){
                        cerr << cell.as_int();
                    }
                    else if(cell.is_string()){
                        cerr << cell.as_string();
                    }
                    else if(cell.is_datetime()){
                        cerr << cell.as_datetime();
                    }
                    cerr << "\t";
                }
                cerr << "\n";
            } 
        }
    }while(cursor.next_result_set()); //mysql 任务支持一个任务处理多个SQL语句
}
int main(){
    signal(SIGINT,sighandler);
    WFMySQLTask * mysqlTask =  WFTaskFactory::create_mysql_task("mysql://root:123@localhost",1,mysqlCallback);
    string sql = "insert into mycloud.tbl_user_token (user_name,user_token) values ('Caixukun','singdancerap');";
    //string sql;
    sql += "select * from mycloud.tbl_user_token;";
    mysqlTask->get_req()->set_query(sql);
    mysqlTask->start();
    waitGroup.wait();
    return 0;
}
```

# 04

**将项目代码中函数体长度超过10行的lambda表达式替换成std::bind + 成员函数**

# 05

