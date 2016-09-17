/**
* @file StackQueueExercises.h
*
* Copyright (c) 2016 NHQ.
*
* @brief
*   Stack & queue exercise implementation
*/
#ifndef STACK_QUEUE_EXERCISES_H
#define STACK_QUEUE_EXERCISES_H
//Note: relevant containers in std:
// std::stack: http://en.cppreference.com/w/cpp/container/stack
//std::queue: http://en.cppreference.com/w/cpp/container/queue
//std::priority_queue: http://en.cppreference.com/w/cpp/container/priority_queue
//std::deque: http://en.cppreference.com/w/cpp/container/deque

//#include "LinkedListExercises.h"

//*******************************************
// Stack definition
//*******************************************
template <class T>
class Stack
{
public:
    Stack();
    Stack(int maxSize);
    ~Stack();
    T Top();
    void Pop();
    bool Push(const T& rVal);
    int GetSize();
    int GetMaxSize();
    bool IsFull();

    ////copy constructor:
    //Stack(const Stack& rStack);
    ////assignment operator:
    //Stack& operator=(const Stack<T>& other);

    //bool operator==(const Stack<T>& lhs);
private:

    template <class T>
    class Node
    {
    public:
        T val;
        Node<T>* next;

        Node<T>(const T& new_val) : val(new_val), next() {};
    };

    Node<T>* mpTop;
    int mSize;
    int mMaxSize;
};


class StackQueueExercises
{
public:

private:
};

#endif STACK_QUEUE_EXERCISES_H