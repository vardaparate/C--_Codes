// Write a function that:

// void allocateAndFill(int** arr, int size);


// The function should:

// Dynamically allocate an integer array of given size

// Fill it with squares of indices (i * i)

// Return it via the double pointer

// In main():

// Call the function

// Print the array

// Free the memory properly

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void allocate(int **p, int sz)
{
    int *a = new int[sz];
    for(int i=0; i<sz; i++)
    {
        a[i] = i*i;
    }
    *p = a;
}

int main()
{
    int *p = nullptr;
    allocate(&p, 5);
    for(int i=0;i<5;i++, p++)
    {
        cout<<(*p)<<" ";
    }
    delete[] p;
    return 0;
}