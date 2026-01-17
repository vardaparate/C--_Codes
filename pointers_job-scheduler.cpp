// Design a job scheduler:

// Jobs are created and submitted to the scheduler

// Once submitted, the creator must not access the job

// Jobs must be cleaned automatically after execution

#include<iostream>
#include<memory>
#include<queue>
using namespace std;

class Job 
{
public:
    void run() 
    {
        cout<<"job running"<<endl;
    }
};

class Scheduler 
{
    queue<unique_ptr<Job>> jobs;

public:
    void submit(unique_ptr<Job> job) 
    {
        jobs.push(move(job));
    }

    void execute() 
    {
        while (!jobs.empty())
        {
            jobs.front()->run();
            jobs.pop();  // AUTOMATIC CLEANING
        }
    }
};

int main() 
{
    Scheduler s;
    auto p1 = make_unique<Job>();
    s.submit(move(p1));

    // SUBMITTED POINTER
    auto p2 = make_unique<Job>();
    s.submit(move(p2));

    // cout<<p2<<endl;

  // COMPLETED JOBS CANT ACCESS BY USERS  
    s.execute();

    
    return 0;
}
