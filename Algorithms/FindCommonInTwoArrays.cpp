// given two sorted integer arrays - find the common integers appearing in both arrays
//Ref: http://articles.leetcode.com/here-is-phone-screening-question-from/
//Ex: a= [1, 3, 5,6] 
//    b= [3,4,6,8] 

//    => 3,6

#include <iostream>
#include <vector>
using namespace std;

void FindCommonInt(const vector<int> &a, const vector<int> &b)
{
    if (a.empty() || b.empty()) return;
    auto pa = a.begin();
    auto pb = b.begin();
    cout << "[ ";
    while (pa != a.end() && pb != b.end())
    {
        if (*pa == *pb)
        {
            std::cout << *pa << " ";
            pa++; pb++;
        }
        else if (*pa < *pb)
        {
            pa++;
        }
        else
        {
            pb++;
        }
    }
    cout << "]";
    return;
}

int main()
{
    vector<int> a{ 1, 3, 5, 6 };
    vector<int> b{ 3, 4, 6, 8, 9 };
    FindCommonInt(a, b);
    return 0;
}