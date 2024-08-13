#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/HttpUtil.h>
#include <hiredis/hiredis.h> // 引入 hiredis 库
#include <iostream>
#include <string>
#include <signal.h>

using std::cout;
using std::cerr;
using std::string;

static WFFacilities::WaitGroup waitGroup(1);

// 信号处理函数
void sigHandler(int signum) {
    cout << "done!\n";
    waitGroup.done();
}

// HTTP 回调函数
void httpCallback(WFHttpTask *httpTask) {
    // 检查错误
    int state = httpTask->get_state();
    int error = httpTask->get_error();
    switch (state) {
        case WFT_STATE_SYS_ERROR:
            cerr << "system error: " << strerror(error) << "\n";
            break;
        case WFT_STATE_DNS_ERROR:
            cerr << "DNS error: " << gai_strerror(error) << "\n";
            break;
        case WFT_STATE_SSL_ERROR:
            cerr << "SSL error: " << error << "\n";
            break;
        case WFT_STATE_TASK_ERROR:
            cerr << "Task error: " << error << "\n"; 
            break;
        case WFT_STATE_SUCCESS:
            break;
    }

    if (state != WFT_STATE_SUCCESS) {
        cerr << "Failed. Press Ctrl-C to exit.\n";
        return;
    }

    // 获取请求信息
    protocol::HttpRequest *req = httpTask->get_req();
    cout << "http request method = " << req->get_method() << "\n";
    cout << "http request uri = " << req->get_request_uri() << "\n";
    cout << "http request version = " << req->get_http_version() << "\n";

    // 获取响应信息
    cout << "--------------------------------------------------\n";
    protocol::HttpResponse *resp = httpTask->get_resp();
    cout << "http response version = " << resp->get_http_version() << "\n";
    cout << "http response status code = " << resp->get_status_code() << "\n";
    cout << "http response reason phrase = " << resp->get_reason_phrase() << "\n";

    // 解析响应体
    const void *body;
    size_t size;
    resp->get_parsed_body(&body, &size);
    string html_content(static_cast<const char*>(body), size); // 将响应体转换为字符串

    // 连接到 Redis
    redisContext *redis = redisConnect("127.0.0.1", 6379);
    if (redis == nullptr || redis->err) {
        if (redis) {
            cerr << "Error: " << redis->errstr << "\n";
            redisFree(redis);
        } else {
            cerr << "Can't allocate redis context\n";
        }
        return;
    }

    // 将 HTML 内容存入 Redis
    const char *key = "www.taobao.com"; // 设定 Redis 键
    if (redisCommand(redis, "SET %s %s", key, html_content.c_str()) == nullptr) {
        cerr << "Error storing data in Redis: " << redis->errstr << "\n";
    } else {
        cout << "Stored HTML content in Redis under key: " << key << "\n";
    }

    // 释放 Redis 连接
    redisFree(redis);
}

int main() {
    signal(SIGINT, sigHandler);
    
    // 创建 HTTP 任务
    WFHttpTask *httpTask = WFTaskFactory::create_http_task(
        "http://www.taobao.com", // URL
        10, // 最大重定向次数
        10, // 最大重试次数
        httpCallback // 回调函数
    );

    // 设置请求头
    protocol::HttpRequest *req = httpTask->get_req();
    req->add_header_pair("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3");
    // 启动 HTTP 任务
    httpTask->start();

    // 等待所有任务完成
    waitGroup.wait();
    cout << "finished!\n"; 
    return 0;
}