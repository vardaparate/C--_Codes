//EXERCISE 5 — Thread-safe statistics collector

// (mutex + chrono + shared state)

// Goal

// Multiple threads update shared statistics safely and periodically.

// Task

// Create a struct:

// struct Stats {
//     int produced;
//     int consumed;
// };


// Two producer threads:

// Increment produced every 100 ms

// One consumer thread:

// Increments consumed every 150 ms

// One monitor thread:

// Every 1 second, prints both values

// Program runs for ~5 seconds

// Rules

// Use one mutex to protect Stats

// No atomics allowed

// What this tests

// ✔ Shared struct protection
// ✔ Multiple threads, one lock
// ✔ Time-based behavior

#include<bits/stdc++.h>
using namespace std;
#include<chrono>
#include<thread>

struct Stats
{
    int produced;
    int consumed;
};
int time = 0;

void produce(Stats *p)
{
    while(produced<)
    {
        p->produced++;
        std::this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consume(Stats *p)
{
    p->consumed++;
}

int main()
{
    cout<<"yess";
    return 0;

    Stats stats;
    stats.produced = 0;
    stats.consumed = 0;



}