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
struct CallRequest
{
    int level; //difficult level
    int priority;
};

typedef std::shared_ptr<CallRequest> CallRequestPtr;

class Employee
{
public:
    Employee(int id, std::string name):
        mID(id),
        mName(name)
    {};
    virtual ~Employee(){};

    virtual bool HandleRequest(CallRequestPtr rRequest)
    {
        if (rRequest->level > mAbility)
        {
            //too hard. Can't handle!
            return false;
        }
        else
        {
            //Do processing...
            return true;
        }
    }
    enum JobTitle {FR, TL, PM};
protected:
    int mID;
    std::string mName;
    JobTitle mTitle;
    int mAbility;
};

class Fresher : public Employee
{
public:
    Fresher(int id, std::string name) :
        Employee(id, name)
    {
        mTitle = JobTitle::FR;
        mAbility = 1;
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
        mAbility = 3;
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
        mAbility = 5;
    };
    ~ProductManager(){};
};

class CallHandler
{


};

#endif CALL_CENTER_H