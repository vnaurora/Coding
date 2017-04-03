/**************************************
Permutation
https://leetcode.com/problems/permutations/
***************************************/
#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
vector<vector<int>> permute(vector<int> & nums)
{
    typedef vector<vector<int>> PerList;
    if (nums.empty()) return PerList();

    queue<vector<int>> prev, curr;
    prev.push(vector<int>{nums[0]}); //note vectorint>(n) makes an vector of n ints.
    for (int i = 1; i < nums.size(); i++)
    {
        while (!prev.empty()) {
            auto & v = prev.front(); //auto & => reference, not copy.
            for (int j = 0; j <= v.size(); j++) {
                auto v2 = v; //=> copy to a new vector here
                v2.insert(v2.begin()+j, nums[i]);
                curr.push(v2);
            }
            prev.pop(); //pop after use, otherwise, v is deleted.
        }
        curr.swap(prev);
    }
    PerList ret;
    while (!prev.empty()) {
        ret.push_back(prev.front());
        prev.pop();
    }
    return ret;
}

//Note: time complexity is O(n!) (most efficent because it does n! things)
// space complexity is O(N)

void PrintVector(vector<int> v)
{
    std::cout << "[";
    for (auto i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" <<std::endl;
}

void main()
{
    std::vector<int> nums{ 1, 2, 3, 4 };
    vector<vector<int>> per_list = permute(nums);
    std::cout << "Total = " << per_list.size() << std::endl;
    for (auto v : per_list) {
        PrintVector(v);
    }
}