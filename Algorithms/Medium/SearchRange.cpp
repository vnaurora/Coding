//Given a sorted array of integers, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].
//
//For example,
//Given[5, 7, 7, 8, 8, 10] and target value 8,
//return[3, 4].

//https://leetcode.com/problems/search-for-a-range/


#include <utility>
#include <vector>
#include <iostream>
using namespace std;

pair<int, int> search(vector<int>& nums, int target, int start, int end) {
    if ((nums[start] == target) && (nums[end] == target)) return make_pair(start, end);
    else if ((nums[start]>target) || (nums[end] < target) || start == end) return make_pair(-1, -1);

    int mid = (start + end) / 2;
    auto pair1 = search(nums, target, start, mid);
    auto pair2 = search(nums, target, mid + 1, end);
    auto invalid_pair = make_pair(-1, -1);
    if ((pair1 != invalid_pair) && (pair2 != invalid_pair)) {
        return make_pair(pair1.first, pair2.second);
    }
    else if (pair1 != invalid_pair) {
        return pair1;
    }
    else if (pair2 != invalid_pair) {
        return pair2;
    }

    return make_pair(-1, -1);
}

vector<int> searchRange(vector<int>& nums, int target) {
    auto p = search(nums, target, 0, nums.size() - 1);
    return vector<int> {p.first, p.second};
}

int main()
{
    vector<int> in{ 1, 2, 3, 4, 4, 4, 4, 4, 5, 7, 9, 10 };
    vector <int>out = searchRange(in, 4);
    for (auto v : out) {
        cout << v << " ";
    }
}