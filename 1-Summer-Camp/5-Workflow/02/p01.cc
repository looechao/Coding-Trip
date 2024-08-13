// WaitGroup 让某个线程处于等待状态
#include <workflow/WFFacilities.h> // 引入 workflow 框架的基础设施
#include <workflow/WFHttpServer.h> // 包含 HTTP 服务器类的设计
#include <iostream> // 引入输入输出流库
#include <string> // 引入字符串类
#include <signal.h> // 引入信号处理库
#include <unistd.h> // 引入 POSIX 操作系统 API
using std::cout; // 使用 cout 以简化代码
using std::string; // 使用 string 以简化代码

// 定义一个结构体 SeriesContext，用于存储每个请求的上下文信息
struct SeriesContext {
    string name; // 存储用户名
    string password; // 存储用户密码
    protocol::HttpResponse *resp; // 指向 HTTP 响应对象，决定回复给客户端的内容
};

// 创建一个 WaitGroup，初始计数为 1，用于控制线程同步
static WFFacilities::WaitGroup waitGroup(1);

// 信号处理函数，处理 SIGINT（通常是 Ctrl+C）
void sigHandler(int signum) {
    cout << "done!\n"; // 打印结束信息
    waitGroup.done(); // 结束 WaitGroup 的等待状态
}

// Redis 回调函数，用于处理 Redis 任务的结果
void redisCallback(WFRedisTask * redisTask) {
    // 获取 Redis 的执行结果
    protocol::RedisValue result; // 存储 Redis 返回的结果
    protocol::RedisResponse * resp = redisTask->get_resp(); // 获取 Redis 响应
    resp->get_result(result); // 获取执行结果

    // 访问上下文
    SeriesContext * context = static_cast<SeriesContext *>(series_of(redisTask)->get_context()); // 获取当前任务上下文
    // 检查 Redis 返回的结果是否为字符串，并与存储的密码进行比较
    if(result.is_string() && result.string_value() == context->password) {
        cout << context->name << " success\n"; // 打印成功信息
        context->resp->append_output_body("<html>success</html>"); // 回复成功 HTML 内容
    } else {
        cout << context->name << " fail\n"; // 打印失败信息
        context->resp->append_output_body("<html>fail</html>"); // 回复失败 HTML 内容
    }
}

// 处理 HTTP 请求的函数
void process(WFHttpTask *serverTask) {
    protocol::HttpRequest *req = serverTask->get_req(); // 获取请求对象
    string uri = req->get_request_uri(); // 获取请求的 URI
    cout << uri << "\n"; // 打印请求的 URI
    // 解析 URI，提取用户名和密码
    string nameKV = uri.substr(0, uri.find("&")); // 提取用户名部分
    string passwordKV = uri.substr(uri.find("&") + 1); // 提取密码部分
    string name = nameKV.substr(nameKV.find("=") + 1); // 获取用户名
    string password = passwordKV.substr(passwordKV.find("=") + 1); // 获取密码
    cout << "name = " << name << ", password = " << password << "\n"; // 打印用户名和密码

    // 申请一片内存空间，用于序列内的任务共享数据
    SeriesContext * context = new SeriesContext; // 创建 SeriesContext 对象
    context->name = name; // 设置用户名
    context->password = password; // 设置密码
    context->resp = serverTask->get_resp(); // 设置响应对象
    series_of(serverTask)->set_context(context); // 将上下文与当前任务关联

    // 创建一个 Redis 任务
    WFRedisTask * redisTask = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379", 10, redisCallback); // 创建 Redis 任务
    // 构造 Redis 请求，获取指定用户的密码
    redisTask->get_req()->set_request("HGET", {"57user", name}); // HGET 命令以获取用户的密码
    series_of(serverTask)->push_back(redisTask); // 将 Redis 任务添加到任务序列中
}

int main() {
    signal(SIGINT, sigHandler); // 注册信号处理函数
    WFHttpServer server(process); // 创建 HTTP 服务器，指定处理函数
    // 启动服务器，监听 12345 端口
    if(server.start(12345) == 0) {
        waitGroup.wait(); // 等待所有任务完成
        server.stop(); // 服务器停止运行
    } else {
        perror("server start failed!"); // 如果服务器启动失败，输出错误信息
        return -1; // 返回错误代码
    }
    cout << "finished!\n"; // 输出结束信息
    return 0; // 正常结束程序
}