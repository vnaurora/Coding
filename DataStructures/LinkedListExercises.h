/**
* @file LinkedListExercises.h
*
* Copyright (c) 2016 NHQ.
*
* @brief
*   Linked list exercise codes
*/
#ifndef LINKED_LIST_EXERCISES_H
#define LINKED_LIST_EXERCISES_H

//Note: “using namespace std” in C++ considered bad practice?
//Ref: http://stackoverflow.com/questions/1452721/why-is-using-namespace-std-in-c-considered-bad-practice
using namespace std;

//Note: in std, there are two equivalent containers:
//std::forward_list = singly-linnked list (http://en.cppreference.com/w/cpp/container/forward_list)
//std::list = doubly-linked list (http://en.cppreference.com/w/cpp/container/list)

#include <sstream> //for stringstream
#include <forward_list>
template <class T>
class Node
{
public:
    T val;
    Node<T>* next;

    Node<T>(const T& new_val) : val(new_val), next() {};
};

/**
* Definition for singly-linked list in leetcode.
*/
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
typedef Node<int> ListNode;

template <class T>
class LinkedList
{
public:
    LinkedList();
    //create a linked list with a head pointer;
    LinkedList(Node<T>* rHead);
    //create a new linked list with data
    LinkedList(T* pDataArray, int size);

    ~LinkedList();

    //Add a new node to Head
    void PushNode(Node<T>* pNewNode);
    //Remove a node from Head
    void PopNode(Node<T>* pNewNode);

    void InsertNext(Node<T>* pCurrNode, Node<T>* pNewNode);
    void RemoveNext(Node<T>*pCurrNode);
    Node<T>* FindNodeByPosition(int position); //return nullptr if fails

    //insert a node into linkedList, return true if succeeds
    bool InsertNode(Node<T>* pNewNode, int position);
    
    bool RemoveNode(int position);
    //Node* findNode(int position);
    Node<T>* mHead;

};

//explicit template instantiation:
template class Node<int>;
template class LinkedList<int>;

class LinkedListExercises
{
public:
    static void RemoveDuplicates(LinkedList<int>& rList);
    static void RemoveDuplicates2(std::forward_list<int>& rList);

    static ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2);
    
    //Helper functions
    static std::stringstream PrintListToString(const LinkedList<int>& rList);
    static void PrintList(const LinkedList<int>& rList, const std::string& name);
    //compare lists. Return true if they are identical. Otherwise, return false
    static bool CompareLists(const ListNode* rBaseHead,
                             const ListNode* rTargetHead);
    static bool CompareLists(const LinkedList<int>& rBaseList,
        const LinkedList<int>& rTargetList);
};

#endif LINKED_LIST_EXERCISES_H