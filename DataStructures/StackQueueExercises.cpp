#include "StackQueueExercises.h"


//*******************************************
// Stack implementation
//*******************************************

template<class T>
Stack<T>::Stack():
mpTop(),
mSize(0),
mMaxSize(100)
{
}

template<class T>
Stack<T>::Stack(int maxSize) :
mpTop(),
mSize(0),
mMaxSize(maxSize)
{
}

template<class T>
Stack<T>::~Stack()
{
    while (mpTop != nullptr)
    {
        this->pop();
    }
}

template<class T>
T Stack<T>::Top()
{
    return mpTop->val;
}

template<class T>
void Stack<T>::Pop()
{
    if (mpTop != nullptr)
    {
        Node<T>* p = mpTop;
        mpTop = mpTop->next;
        delete p;
    }
}

template<class T>
bool Stack<T>::Push(const T& rVal)
{
    if (mSize < mMaxSize)
    {
        Node<T> n = new Node<T>(rVal);
        n.next = mpTop;
        mpTop = &n;
        mSize++;
        return true;
    }
    else
    { 
        //stack is full. Can't push more in.
        return false;
    }
}

template<class T>
int Stack<T>::GetSize()
{
    return mSize;
}

template<class T>
int Stack<T>::GetMaxSize()
{

}

template<class T>
bool Stack<T>::IsFull()
{
    return (mSize < mMaxSize);
}

//template<class T>
//Stack<T>::Stack(const Stack& rStack):
//mSize(rStack.Size()),
//mMaxSize(rStack.MaxSize)
//{
//
//}