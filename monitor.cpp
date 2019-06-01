// Chad Weirick
// CST-221
// This is a sample of a monitor process
// This will simulate bank transactions

#include <thread>
#include <string>
#include <mutex>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;
float balance = 1000.00;
int flag = 0;
int a = 0;

void workerProcess(){
    // set id
    a++;
    std::cout << "Worked Process " << a << " started \n";
    // this will put a limit in how long the worker will perform - in reality we could let this go on forever
    for (int i = 0; i < 10000000; i++){
        if (flag == 1){
            flag = 0;
            std::cout << "Worked Process " << a << "\n";
            balance = balance - a;
        }
    }    
}

int main(){
    
    std::cout << "starting work for 1000 times!\n";
    std::thread t1(workerProcess);
    std::thread t2(workerProcess);
    std::thread t3(workerProcess);
       t1.join();
        t2.join();
        t3.join();
    for (int i = 0; i < 1000; i++){
 
        flag = 1;
        std::cout << "unlocked flag \n";
    }
    return 0;
    exit(1);
}
