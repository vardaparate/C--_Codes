#include<iostream>
#include<mutex>
#include<atomic>
#include<chrono>
#include<thread>
using namespace std;

int cnt = 0;
atomic<bool> running(true);
mutex mtx;

void func1()
{
    while(running)
    {
        mtx.lock();
        cnt++;
        mtx.unlock();
    }
}

void func2()
{
    while(running)
    {
        mtx.lock();
        cnt++;
        mtx.unlock();
    }
}

int main()
{
    thread t1(func1);
    thread t2(func2);

    this_thread::sleep_for(chrono::seconds(3));
    running = false;

    t1.join();
    t2.join();

    cout<<cnt;
    return 0;
}