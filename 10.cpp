// Task:

// You have 1 million sensor readings (integers).

// You need to compute the sum of squares of all readings frequently (hot path).

// Occasionally, you log the maximum reading (cold path).

// Requirements:

// Use data-oriented design → separate arrays for data if needed.

// Use zero-copy → pass pointers or references.

// Clearly separate hot path (sum of squares) from cold path (max logging).

// Measure time using chrono.

#include<iostream>
#include<chrono>
#include<vector>
#include<algorithm>
using namespace std;

void func1(vector<int> &vec, long long &sum)
{
    for(int i=0; i<vec.size(); i++)
    {
        sum += vec[i]*vec[i];
    }
}

void func2(vector<int> &vec)
{
    cout<<"func2 = "<<*max_element(vec.begin(), vec.end());
}

int main()
{
    int size = 100000;
    vector<int> vec(size);
    for(int i=0; i<size; i++)
    {
        vec[i] = i;
    }

    
    for(int i=0; i<10; i++)
    {
        long long sum = 0;
        auto s = chrono::steady_clock::now();
        func1(vec, sum);
        auto e = chrono::steady_clock::now();
        auto diff = chrono::duration_cast<chrono::microseconds>(e - s).count();
        cout<<"func1 = "<<sum<<", time = "<<diff<<endl;

        if(i%5 == 0)
        {
            auto s1 = chrono::steady_clock::now();
            func2(vec);
            auto e1 = chrono::steady_clock::now();
            auto diff1 = chrono::duration_cast<chrono::microseconds>(e1 - s1).count();
            cout<<" time = "<<diff1<<endl;
        }
    }

    return 0;
}