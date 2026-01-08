#include <iostream>
#include <chrono>

void coldFunction() {
    // std::cout << "Cold path executed" << std::endl;
}

int main() {
    int counter = 0;
    auto hotStart = std::chrono::steady_clock::now();

    for(int i = 1; i <= 100000; i++) {
        counter++;  // hot path

        if(i % 10000 == 0) {
            auto coldStart = std::chrono::steady_clock::now();
            coldFunction();  // cold path
            auto coldEnd = std::chrono::steady_clock::now();
            std::cout << "Cold path time: " 
                      << std::chrono::duration_cast<std::chrono::microseconds>(coldEnd - coldStart).count()
                      << " us" << std::endl;
        }
    }

    auto hotEnd = std::chrono::steady_clock::now();
    std::cout << "Hot path time: " 
              << std::chrono::duration_cast<std::chrono::microseconds>(hotEnd - hotStart).count() 
              << " us" << std::endl;

    return 0;
}
