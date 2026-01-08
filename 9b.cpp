// FALSE SHARING

#include<iostream>
#include<atomic>
#include<thread>
#include<chrono>
using namespace std;


    atomic<long long> cnt1{0};
    atomic<long long> cnt2{0};


atomic<bool> running{true};

void func1()
{
    while(running) 
    {
        cnt1++;
    }
}

void func2()
{
    while(running)
    {
        cnt2++;
    }
}

int main()
{

    thread t1(func1);
    thread t2(func2);

    this_thread::sleep_for(chrono::seconds(2));
    running = false;

    t1.join();
    t2.join();

    cout<<cnt1<<endl;
    cout<<cnt2;

    return 0;

}