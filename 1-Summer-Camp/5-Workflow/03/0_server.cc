#include <signal.h>
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/WFHttpServer.h>

using std::cout;
using std::cerr;

static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum){
    cout << "done!\n";
    waitGroup.done();
}

void process(WFHttpTask* serverTask){
    protocol::HttpRequest* req = serverTask->get_req();
    protocol::HttpResponse* resp = serverTask->get_resp();
    const void* body;
    size_t size;
    req->get_parsed_body(&body, &size);
    resp->append_output_body(body, size);
}

int main(){
    signal(SIGINT, sighandler);
    WFHttpServer server(process);
    if(server.start(12345) == 0){
        waitGroup.wait();
        cout << "finished!\n";
        server.stop();
        return 0;
    }else{
        perror("server start fail!\n");
        return -1;
    }
}