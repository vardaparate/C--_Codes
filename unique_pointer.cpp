#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unique_ptr<int[]> createArray(int n)
{
    auto p = make_unique<int[]>(n);
    for(int i=0; i<5; i++)
    {
        p[i] = i;
    }
    return p;
    // MOVE OPERATION; INSTEAD OF COPYING AND END OF SCOPE LIKE NORMAL PTRS
}

int main()
{
    auto a = createArray(5);
    for(int i=0; i<5; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}