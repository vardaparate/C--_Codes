#include<iostream>
#include<atomic>
#include<chrono>
#include<thread>
using namespace std;

atomic<int> cnt{0};
atomic<bool> running(true);

void func1()
{
    while(running)
    {
        cnt++;
    }
}

void func2()
{
    while(running)
    {
        cnt++;
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