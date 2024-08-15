#include <signal.h>
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/WFHttpServer.h>
#include <workflow/WFTaskFactory.h>
#include <fstream>

using std::cout;
using std::cerr;
using std::string;

struct SeriesContext {
    string name;
    string password;
    protocol::HttpResponse* resp;
};

static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum) {
    cout << "done!\n";
    waitGroup.done();
}

void redisCallback(WFRedisTask* redisTask) {
    protocol::RedisResponse* respRedis = redisTask->get_resp();
    protocol::RedisValue result;
    respRedis->get_result(result);

    SeriesContext* context = static_cast<SeriesContext*>(series_of(redisTask)->get_context());

    if (result.is_string() && result.string_value() == context->password) {
        context->resp->append_output_body("Success");
    } else {
        context->resp->append_output_body("Fail");
    }
}

void process(WFHttpTask* serverTask) {
    protocol::HttpRequest* req = serverTask->get_req();
    protocol::HttpResponse* resp = serverTask->get_resp();
    string uri = req->get_request_uri();
    const char* method = req->get_method();

    if (strcmp(method, "GET") == 0 && uri == "/login") {
        resp->set_status_code("302");
        resp->add_header_pair("Location", "http://192.168.31.128/postform.html");
        return;
    }else if (strcmp(method, "POST") == 0 && uri == "/login") {
    const void* body;
    size_t body_length;
    req->get_parsed_body(&body, &body_length);

    std::string body_str(static_cast<const char*>(body), body_length);
    std::string name = body_str.substr(body_str.find("username=") + 9, body_str.find("&") - (body_str.find("username=") + 9));
    std::string password = body_str.substr(body_str.find("password=") + 9);

    cout << "name = " << name << ", password = " << password << "\n";

    SeriesContext* context = new SeriesContext;
    context->name = name;
    context->password = password;
    context->resp = resp;
    series_of(serverTask)->set_context(context);

    WFRedisTask* redisTask = WFTaskFactory::create_redis_task(
        "redis://127.0.0.1:6379",
        10,
        redisCallback
    );
    redisTask->get_req()->set_request("HGET", {"USERINFO", name});
    series_of(serverTask)->push_back(redisTask);
}
}

int main() {
    signal(SIGINT, sighandler);
    WFHttpServer server(process);

    if (server.start(12345) == 0) {
        // Start is non-blocking
        waitGroup.wait();
        cout << "finished!\n";
        server.stop();
        return 0;
    } else {
        perror("server start fail!\n");
        return -1;
    }
}