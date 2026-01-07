// TWO THREADS, ONE ATOMIC

#include<iostream>
#include<thread>
#include<chrono>
#include<atomic>
using namespace std;

atomic<int> counter{0};
bool running = true;

void thread1()
{
    while(running)
    {
        counter++;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void thread2()
{
    while(running)
    {
        counter++;
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

int main()
{
    thread t1(thread1);
    thread t2(thread2);

    this_thread::sleep_for(chrono::seconds(3));
    running = false;

    t1.join();
    t2.join();

    cout<<counter;
    return 0;
}