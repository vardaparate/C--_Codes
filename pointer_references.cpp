// Create a function:

// int findMax(const int* arr, int size);


// Then:

// Use this function to find the maximum element of an array.

// The function must:

// Not modify the array

// Use pointer arithmetic only

// In main():

// Try modifying the array through the pointer (observe compiler error)

// Explain why the error occurs

#include<bits/stdc++.h>
using namespace std;

int findMax(const int *p, int sz)
{
    int maxi = *p;
    const int *end = (p+sz);
    while(p < end)
    {
        maxi = max(maxi, (*p));
        p++;
    }
    return maxi;
}

int main()
{
    int arr[5] = {43, 2, 87, 5, 7025};
    cout<<findMax(arr, 5);
    return 0;
}