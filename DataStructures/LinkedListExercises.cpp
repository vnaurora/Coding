#include "LinkedListExercises.h"
#include <iostream>
#include <assert.h>
#include <unordered_map>

//*******************************************
// LinkedList functions
//*******************************************
template <class T>
LinkedList<T>::LinkedList():
mHead(nullptr)
{

}

template <class T>
LinkedList<T>::LinkedList(Node<T>* rHead) :
mHead(rHead)
{
}

template <class T>
LinkedList<T>::LinkedList(T* pDataArray, int size) :
mHead(nullptr)
{
    //check if size is valid
    assert(size > 0);
    mHead = new Node<T>(pDataArray[0]);
    Node<T>* pNode = mHead;
    Node<T>* pNewNode;
    for (int i = 1; i < size; i++)
    {
        pNewNode = new Node<T>(pDataArray[i]);
        pNode->next = pNewNode;
        pNode = pNewNode;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    while (mHead != nullptr)
    {
        Node<T>* pNode = mHead;
        mHead = mHead->next;
        delete pNode;
    }
}


template <class T>
void LinkedList<T>::PushNode(Node<T>* pNewNode)
{
    assert(pNewNode != nullptr);

}

template <class T>
void LinkedList<T>::InsertNext(Node<T>* pCurrNode, Node<T>* pNewNode)
{
    pNewNode->next = pCurrNode->next;
    pCurrNode->next = pNewNode;
}

template <class T>
void LinkedList<T>::RemoveNext(Node<T>* pCurrNode)
{
    if (pCurrNode->next != nullptr)
    {
        Node<T>* p = pCurrNode->next;
        pCurrNode->next = p->next;
        delete p;       
    }
}

template <class T>
Node<T>* LinkedList<T>::FindNodeByPosition(int position)
{
    assert(position > 0);
    Node<T>* pCurrNode = mHead;
    int current_pos = 1;
    while ((current_pos < position) && (pCurrNode->next != nullptr))
    {
        pCurrNode = pCurrNode->next;
        current_pos++;
    }
    if (current_pos != position)
    {
        //fails
        return nullptr;
    }
    else
    {
        return pCurrNode;
    }
}

template <class T>
bool LinkedList<T>::InsertNode(Node<T>* pNewNode, int position)
{
    if (position == 1) //insert to the head position
    {
        pNewNode->next = mHead;
        mHead = pNewNode;
        return true;
    }
    
    Node<T>* pCurrNode = FindNodeByPosition(position - 1);
    if (pCurrNode == nullptr)
    {
        cout << "ERROR Node can't be added" << endl;
        return false;
    }

    InsertNext(pCurrNode, pNewNode);
    return true;
}





//*******************************************
// Excercises
//*******************************************

/*
Write code to remove duplicates from an unsorted linked list
FOLLOW UP
How would you solve this problem if a temporary buﬀer is not allowed ?
Ref: Cracking Code interview Ex2.1 (p50)
*/
void LinkedListExercises::RemoveDuplicates(LinkedList<int>& rList)
{
    std::unordered_map<int, int> my_table;
    std::unordered_map<int, int>::const_iterator found_pos;
    Node<int>* pNode = rList.mHead;
    Node<int>* pPrevNode = rList.mHead;
    while (pNode)
    {
        found_pos = my_table.find(pNode->val);
        if (found_pos != my_table.end())
        {
            //if it's found in the hash table,
            //then the current pNode is a duplicate => remove it
            pPrevNode->next = pNode->next;
            delete pNode;
            pNode = pPrevNode->next;
        }
        else
        {
            //this is a new key, insert it into the hash table
            my_table.insert(std::make_pair(pNode->val, 1));
            pPrevNode = pNode;
            pNode = pPrevNode->next;
        }
    }
}

void LinkedListExercises::RemoveDuplicates2(std::forward_list<int>& rList)
{
    std::unordered_map<int, int> my_table;
    std::unordered_map<int, int>::const_iterator found_pos;
    std::forward_list<int>::const_iterator it = rList.begin();
    std::forward_list<int>::const_iterator prev_it = rList.begin();
    while (it!=rList.end())
    {
        found_pos = my_table.find(*it);
        if (found_pos != my_table.end())
        {
            it++; //Note: could use it = std::next(it)
            rList.erase_after(prev_it);
        }
        else
        {
            my_table.insert(std::make_pair(*it, 1));
            prev_it = it;
            it++;
        }
    }
}


/**
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain 
a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Ref: https://leetcode.com/problems/add-two-numbers/
Ref: Cracking Code interview Ex2.4 (p50)
*/
ListNode* LinkedListExercises::AddTwoNumbers(ListNode* l1, ListNode* l2)
{
    //check valid conditions!!
    //assume ok!
    if (!l1 && !l2)
    {
        return nullptr;
    }
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    int sum_val;
    int carry_val = 0;
    while (l1 || l2 || (carry_val>0))
    {     
        sum_val = carry_val;
        carry_val = 0;
        if (l1)
        {
            sum_val += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum_val += l2->val;
            l2 = l2->next;
        }
        if (sum_val >= 10)
        {
            carry_val = 1;
            sum_val -= 10;
        }
        if (curr)
        {
            curr->next = new ListNode(sum_val);
            curr = curr->next;
        }
        else //first node
        {
            curr = new ListNode(sum_val);
            head = curr;
        }
    }
    return head;
}

//*******************************************
// Helper functions
//*******************************************

std::stringstream LinkedListExercises::PrintListToString(const LinkedList<int>& rList)
{
    std::stringstream ret_val;
    ret_val << "Start list:";
    Node<int>* pNode = rList.mHead;
    while (pNode)
    {
        ret_val << pNode->val << " ";
        pNode = pNode->next;
    }
    return ret_val;
}

void LinkedListExercises::PrintList(const LinkedList<int>& rList, const std::string& name)
{
    std::stringstream buffer = PrintListToString(rList);
    std::cout << name << ":" << buffer.str() << std::endl;
}

bool LinkedListExercises::CompareLists(const ListNode* rBaseHead,
                                       const ListNode* rTargetHead)
{
    const ListNode* pBaseNode = rBaseHead;
    const ListNode* pTargetNode = rTargetHead;
    while (pBaseNode && pTargetNode)
    {
        //compare data from both list
        if (pBaseNode->val != pTargetNode->val)
        {
            return false;
        }
        pBaseNode = pBaseNode->next;
        pTargetNode = pTargetNode->next;
    }

    if (pBaseNode || pTargetNode)
    {
        //one list is shorter than the other
        return false;
    }
    return true;
}

bool LinkedListExercises::CompareLists(const LinkedList<int>& rBaseList,
    const LinkedList<int>& rTargetList)
{
    return CompareLists(rBaseList.mHead, rTargetList.mHead);
}