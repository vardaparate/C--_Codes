// Design an event system where:

// Components can subscribe to events

// Events may outlive the subscriber

// Triggering an event must not crash even if subscribers are destroyed


#include<iostream>
#include<vector>
#include<memory>

using namespace std;

class Subscriber 
{
    public:
        void notify() 
        {
            cout<<"event received"<<endl;
        }
};

class Event 
{
    vector<weak_ptr<Subscriber>> vec;

    public:
        void subscribe(shared_ptr<Subscriber> &s) 
        {
            vec.push_back(s);
        }

        void trigger() 
        {
            for (auto it=vec.begin(); it!=vec.end(); ) 
            {
                if (auto s = it->lock()) 
                {
                    s->notify();
                    ++it;
                } 
                else 
                {
                    it = vec.erase(it);
                }
            }
        }
};

int main() 
{
    Event event;

    {
        auto s1 = make_shared<Subscriber>();
        auto s2 = make_shared<Subscriber>();

        // auto s1 = make_unique<Subscriber>();
        // event.subscribe(move(s1));
        // WHOLE CONTROL GOES TO EVENT. NOT DESTROYED UNTILL event DESTROYED

        // Subscriber s1;
        // event.subscribe(&s1);
        // delete(s1);
        // DANGLING POINTER INSIDE event

        event.subscribe(s1);
        event.subscribe(s2);

        event.trigger();
    } 
    // s1, s2 DESTROYED

    event.trigger(); 
    cout<<"triggering again"<<endl;
    // NO CRASH

    return 0;
}
