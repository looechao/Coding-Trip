#include <signal.h>
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/WFHttpServer.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/WFOperator.h>

using std::cout;
using std::cerr;
using std::string;

struct SeriesContext{
    string name;
    string password;
    protocol::HttpResponse* resp;
};

static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum){
    cout << "done!\n";
    waitGroup.done();
}

void redisCallback(WFRedisTask* redisTask){
    protocol::RedisResponse* respRedis = redisTask->get_resp();
    protocol::RedisValue result;
    respRedis->get_result(result);
    // 获取context
    SeriesContext* context = static_cast<SeriesContext*>(series_of(redisTask)->get_context());

    if(result.is_string() && result.string_value() == context->password){
        context->resp->append_output_body("Login Success");
    }else{
        context->resp->append_output_body("Login Fail: Invalid Username or Password");
    }
    context->resp->set_http_version("HTTP/1.1");
    context->resp->set_status_code("200");
    context->resp->set_reason_phrase("OK");
}

void process(WFHttpTask* serverTask) {
    protocol::HttpRequest* req = serverTask->get_req();
    protocol::HttpResponse* resp = serverTask->get_resp();

    string uri = req->get_request_uri();
    cout << "URI = " << uri << "\n";

    // 处理GET请求
    if (req->get_method() == "GET") {
        if (uri == "/login") {
            // 设置HTTP版本
            resp->set_http_version("HTTP/1.1");
            // 设置重定向状态码
            resp->set_status_code("302");
            // 设置重定向原因
            resp->set_reason_phrase("Found");
            // 设置Location头
            resp->add_header_pair("Location", "http://192.168.31.128/postform.html");

            // 确保响应内容为空，以避免混淆
            resp->append_output_body(""); 

            cout << "Redirecting to http://192.168.31.128/postform.html" << "\n";
            return;  // 确保函数在执行完重定向逻辑后立即返回
        } else if (uri == "/favicon.ico") {
            // 处理/favicon.ico请求，返回空内容或204
            resp->set_status_code("204");
            resp->set_reason_phrase("No Content");
            return;
        } else {
            // 处理其他未知的GET请求
            resp->set_status_code("404");
            resp->set_reason_phrase("Not Found");
            resp->append_output_body("404 Not Found");
            return;
        }
    }

    // 处理POST请求
    if (req->get_method() == "POST") {
        const void* body;
        size_t body_len;

        req->get_parsed_body(&body, &body_len);
        string body_str(static_cast<const char*>(body), body_len);
        cout << "POST body = " << body_str << "\n";

        // 解析POST请求体
        string nameKV = body_str.substr(0, body_str.find("&"));
        string passwordKV = body_str.substr(body_str.find("&") + 1);
        string name = nameKV.substr(nameKV.find("=") + 1);
        string password = passwordKV.substr(passwordKV.find("=") + 1);
        cout << "name = " << name << ", password = " << password << "\n";

        // 创建context并存储用户名和密码
        SeriesContext* context = new SeriesContext;
        context->name = name;
        context->password = password;
        context->resp = resp;
        series_of(serverTask)->set_context(context);

        // 创建Redis任务
        WFRedisTask* redisTask = WFTaskFactory::create_redis_task(
            "redis://127.0.0.1:6379",
            10,
            redisCallback
        );
        redisTask->get_req()->set_request("HGET", { "USERINFO", name });

        // 将Redis任务加入到任务链中
        series_of(serverTask)->push_back(redisTask);
    }
}

int main(){
    signal(SIGINT, sighandler);
    WFHttpServer server(process);
    if(server.start(12345) == 0){
        //start非阻塞了
        waitGroup.wait();
        cout << "finished!\n";
        server.stop();
        return 0;
    } else {
        perror("server start fail!\n");
        return -1;
    }
}