#include <signal.h>
#include <iostream>
#include <workflow/WFFacilities.h>
using std::cout;

static WFFacilities::WaitGroup waitGroup(2);

void sig_handler(int signum){
    cout << "\n done\n";
    waitGroup.done();
}

int main(){
    signal(SIGINT, sig_handler);
    waitGroup.wait();
    return 0;
}