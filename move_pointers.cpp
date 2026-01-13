#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void processData(unique_ptr<int> a)
{
    cout<<*a<<endl;
    *a = 20;
    cout<<*a<<endl;
}

int main()
{
    unique_ptr<int> p = make_unique<int>(10);
    processData(move(p));
    cout<<*p;
    return 0;
}