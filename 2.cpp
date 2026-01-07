// Two threads:

// Thread A increments count every 100 ms

// Thread B increments count every 200 ms

// Run for 3 seconds

// Print final count

#include<bits/stdc++.h>
#include<mutex>
#include<chrono>
#include<thread>
using namespace std;

struct stats {
    int count = 0;
};

stats stat;
mutex mtx;
bool running = true;

void worker_fast() {
    while (running) {
        {
            mtx.lock();
            stat.count++;
            mtx.unlock();
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void worker_slow() {
    while (running) {
        {
            mtx.lock();
            stat.count++;
            mtx.unlock();
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

int main() {
    thread t1(worker_fast);
    thread t2(worker_slow);

    this_thread::sleep_for(chrono::seconds(3));
    running = false;

    t1.join();
    t2.join();

    cout<<stat.count;
    return 0;
}
