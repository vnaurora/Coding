//Count and Say
//The count - and - say sequence is the sequence of integers beginning as follows :
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.
//https://leetcode.com/problems/count-and-say/

#include <iostream>
#include <string>
using namespace std;
string CountAndSay(int n) {
    if (n == 1) return "1";
    if (n == 2) return "11";
    string cur = "11";
    string next;
    int count;
    for (int loop = 3; loop <= n; loop++) {
        count = 1;
        for (int i = 1; i< cur.size(); i++) {
            if (cur[i] == cur[i - 1]){
                count++;
            }
            else {
                next += to_string(count) + cur[i - 1];
                count = 1;
            }
        }
        next += to_string(count) + cur[cur.size() - 1];
        next.swap(cur);
        next.erase();
    }
    return cur;
}

int main()
{
    for (int i = 1; i < 10; i++) {
        cout << CountAndSay(i) << endl;
    }
}