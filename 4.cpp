// Task

// Create a shared integer buffer:

// int buffer = 0;


// Create two threads:

// Producer: increments buffer every 100ms

// Consumer: prints and decrements buffer every 150ms, only if buffer > 0

// Run program for 3-5 seconds

// Use mutex to protect buffer


#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
#include<atomic>
using namespace std;

int buffer = 0;
mutex mtx;
atomic<bool> running{true};

void producer()
{
    while(running)
    {
        mtx.lock();
        buffer++;
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer()
{
    while(running)
    {
        mtx.lock();
        if(buffer > 0)
        {
            cout<<buffer<<endl;
            buffer--;
        }
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

int main()
{
    thread t1(producer);
    thread t2(consumer);

    this_thread::sleep_for(chrono::seconds(3));
    running = false;

    t1.join();
    t2.join();

    return 0;
}