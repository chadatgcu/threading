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
std::mutex balanceMutex;
float balance = 1000.00;

void shared_balanceUpdate(float change, string origin, int id){
    balanceMutex.lock();
    float newBalance = balance + change;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << "Function: " << origin << "id: " << id << " balance: $" << balance << " adjustment: $" << change << " new balance: $" << newBalance << "\n";
    balance = newBalance;
    balanceMutex.unlock();
}

void additionSimulator(){
    int multiplierVar = std::rand();
    for (int i = 0; i<1000; i++){
        float roundThis = ((int)(i * multiplierVar * 100 + 0.5) / 100.00);
        shared_balanceUpdate(roundThis, "addition sim", i);
    }
}

void subtractionSimulator(){
    int multiplierVar = std::rand();
    for (int i = 0; i>-1000; i--){
        float roundThis = ((int)(i * multiplierVar * 100 + 0.5) / 100.00);
        shared_balanceUpdate(roundThis, "subtraction sim", (i * (0-1)));
    }
}

int main(){
    std::thread t1(additionSimulator);
    std::thread t2(subtractionSimulator);
    t1.join();
    t2.join();
    return 0;
}