#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

std::atomic<int> hotCounter{0};
std::atomic<bool> running{true};

void hotPath() {
    while(running) {
        hotCounter++;  // frequent work
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void coldPath() {
    while(running) {
        std::cout << "Cold path running" << std::endl; // infrequent
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    std::thread t1(hotPath);
    std::thread t2(coldPath);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    running = false;

    t1.join();
    t2.join();

    std::cout << "Hot path count: " << hotCounter << std::endl;
    return 0;
}
