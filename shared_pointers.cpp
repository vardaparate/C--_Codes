#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Data
{
    int val;
};

int main()
{
    shared_ptr<Data> p1 = make_shared<Data>();
    p1->val = 10;
    cout<<p1.use_count()<<endl;

    shared_ptr<Data> p2 = p1;
    cout<<p2.use_count()<<endl;

    shared_ptr<Data> p3 = p2;
    cout<<p3.use_count()<<endl;

    weak_ptr<Data> p4 = p3;
    cout<<p4.use_count()<<endl;

    auto check = p4.lock();
    if(check)
    cout<<check->val<<endl;

    check.reset(); //CHECK ALSO CREATES A SHARED PTR, HENCE NEED TO RESET IT !!

    p1.reset();
    p2.reset();
    p3.reset();

    check = p4.lock();
    if(check)
    cout<<check->val<<endl;
    else
    cout<<"naaaa";

    return 0;
}