/*************************
* @file CallCenter.h
*
* Copyright (c) 2016 NHQ.
*
* @brief
*   Design a call center:
*
*   Imagine you have a call center with three levels of employees : fresher, technical lead
*   (TL), product manager(PM) There can be multiple employees, but only one TL or PM
*   An incoming telephone call must be allocated to a fresher who is free If a fresher
*   can’t handle the call, he or she must escalate the call to technical lead If the TL is
*   not free or not able to handle it, then the call should be escalated to PM Design the
*   classes and data structures for this problem Implement a method getCallHandler()
*************************/

#ifndef CALL_CENTER_H
#define CALL_CENTER_H

#include <string>
#include <memory> //smart pointers
#include <queue>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <chrono>

static const int FRESHER_ABILITY = 1;
static const int TECHLEADER_ABILITY = 3;
static const int PRODUCTMANAGER_ABILITY = 5;

struct Call
{
    int level; //difficult level
    int priority;
    Call(int l, int p) : level(l), priority(p) {};
};

typedef std::shared_ptr<Call> CallPtr;

class Employee
{
public:
    Employee(int id, std::string name):
        mID(id),
        mName(name),
        mTitle(JobTitle::FR), //fresher by default
        mAbility(FRESHER_ABILITY)        
    {
        mIsBusy = false;
    };
    virtual ~Employee()
    {
        //wait for thread finish.
        if (mWorkingThread.joinable) mWorkingThread.join();
    };

    virtual bool ReceiveCall(CallPtr rRequest)
    {
        mIsBusy = true; //no need for mutex cause it's atomic
        if (rRequest->level > mAbility)
        {
            //too hard. Can't handle!
            return false;
        }
        
        //Otherwise, do processing in another thread.
        mWorkingThread = std::thread(&ProcessCall, rRequest);

        mIsBusy = false;
        return true;
    }
    bool IsBusy()
    {
        return mIsBusy;
    }
protected:
    virtual void ProcessCall(CallPtr rRequest)
    {
        //Working hard here!
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }
    enum JobTitle { FR, TL, PM };

    int mID;
    std::string mName;
    JobTitle mTitle;
    int mAbility;
    std::atomic_bool mIsBusy;
    std::thread mWorkingThread;
};

class Fresher : public Employee
{
public:
    Fresher(int id, std::string name) :
        Employee(id, name)
    {
        mTitle = JobTitle::FR;
        mAbility = FRESHER_ABILITY;
    };
    ~Fresher(){};
};

class TechLeader : public Employee
{
public:
    TechLeader(int id, std::string name) :
        Employee(id, name)
    {
        mTitle = JobTitle::TL;
        mAbility = TECHLEADER_ABILITY;
    };
    ~TechLeader(){};
};

class ProductManager : public Employee
{
public:
    ProductManager(int id, std::string name) :
        Employee(id, name)
    {
        mTitle = JobTitle::PM;
        mAbility = PRODUCTMANAGER_ABILITY;
    };
    ~ProductManager(){};
};

typedef std::shared_ptr<Fresher> FRPtr;
typedef std::shared_ptr<TechLeader> TLPtr;
typedef std::shared_ptr<ProductManager> PMPtr;

class CallHandler
{
public:
    CallHandler(int fresher_num)
    {
        mFRList.resize(fresher_num);
        int id = 1;
        mPM = std::make_shared<PMPtr>(id, "PM");
        id++;
        mTL = std::make_shared<TLPtr>(id, "TL");
        id++;
        for (auto pFr : mFRList)
        {
            pFr = std::make_shared<FRPtr>(id, "AAA");
            id++;
        }
        
        Init();
    }
    ~CallHandler()
    {
        mRunning = false; //stop threads
        //wait for threads to finish
        if (mAssignThread.joinable()) mAssignThread.join();
    }

    void Init()
    {
        mRunning = true;
        //create thread
        mAssignThread = std::thread(&AssignThread);            
    }
    void ReceiveCall(int level, int priority)
    {
        CallPtr r(new Call(level, priority));
        std::lock_guard<std::mutex> lock(mReqQueueMutex);
        mReqQueue.push(r);
        mReqQueueCondition.notify_one();
    }

    void AssignThread()
    {
        while (mRunning)
        {
            //wait if no new request
            while (mReqQueue.empty())
            {                
                std::unique_lock<std::mutex> lock(mReqQueueMutex);
                mReqQueueCondition.wait(lock);
            }
            std::shared_ptr<Call> call = mReqQueue.top();

            if (call->level > PRODUCTMANAGER_ABILITY)
            {
                //the call is too tough, can't handle.
                //ignore it
                mReqQueue.pop();
                continue;
            }

            bool is_call_accepted = false;
            for (FRPtr fresher : mFRList)
            {
                if (!fresher->IsBusy())
                {
                    is_call_accepted = fresher->ReceiveCall(call);
                    if (is_call_accepted)
                        break;
                }
            }

            if (!is_call_accepted && (!mTL->IsBusy()))
            {
                is_call_accepted = mTL->ReceiveCall(call);
            }

            if (!is_call_accepted && (!mPM->IsBusy()))
            {
                is_call_accepted = mPM->ReceiveCall(call);
            }
            if (is_call_accepted)
            {
                //call is being processed.
                mReqQueue.pop();
            }
            else
            {
                //everyone is busy. Sleep for a while and come back
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        } //while (mRunning)
    }

private:
    bool compare(CallPtr lhs, CallPtr rhs)
    {
        return (lhs->priority < (rhs->priority));
    }
    std::priority_queue < CallPtr, std::vector<CallPtr>, decltype(compare)> mReqQueue;
    
    std::vector<FRPtr> mFRList;
    TLPtr mTL;
    PMPtr mPM;
    std::atomic_bool mRunning;
    std::thread mAssignThread;
    std::mutex mReqQueueMutex;
    std::condition_variable mReqQueueCondition;
};

void test_CallCenter()
{
    CallHandler myCallHandler(5);
    myCallHandler.ReceiveCall(4, 2);

}

#endif CALL_CENTER_H