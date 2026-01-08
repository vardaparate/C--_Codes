#include<iostream>
#include<chrono>
using namespace std;

int main()
{
    int counter = 0;

    auto start = chrono::steady_clock::now();
    for(int i=0; i<900; i++)
    {
        counter++;
    }
    auto end = chrono::steady_clock::now();

    cout<<chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return 0;
}