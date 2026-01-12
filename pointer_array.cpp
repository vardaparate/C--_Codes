// You are given an integer array of size N.

// Write a function that receives a pointer to the array and its size.

// The function should:

// Multiply every element by 2

// Return the sum of the modified elements

// Do not use array indexing (arr[i]) inside the function — use pointer arithmetic only.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long newSum(int *p, int sz)
{
    long long sum = 0;
    while(sz--)
    {
        *p = (*p)+(*p);
        sum += (*p);
        p++;
    }
    return sum;
}

int main()
{
    int arr[5] = {23, 4, 1, 456, 422};
    cout<<newSum(arr, 5);
    return 0;
}