/**
* @file AlgoEx01.h
*
* Copyright (c) 2016 NHQ.
*
* @brief
*   Algorithm exercise codes (part 01)
*/
#ifndef ALGO_EX_01_H
#define ALGO_EX_01_H
#include <utility>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class AlgoEx01
{
public: 
    /**

    You have k lists of sorted integers.Find the smallest range that includes at least one number from each of the k lists.

    For example,
    List 1: [4, 10, 15, 24, 26]
    List 2 : [0, 9, 12, 20]
    List 3 : [5, 18, 22, 30]

    The smallest range here would be[20, 24] as it contains 24 from list 1, 20 from list 2, and 22 from list 3.
    */
    static std::pair<int, int> FindMinRangeOfKSortedLists(std::vector<std::vector<int>>& rLists);


    /**
    https://leetcode.com/problems/word-ladder-ii/
    Given two words(beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the word list
    For example,

    Given:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot", "dot", "dog", "lot", "log"]
    Return
    [
    ["hit", "hot", "dot", "dog", "cog"],
    ["hit", "hot", "lot", "log", "cog"]
    ]
    Note:
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    **/
    std::vector<std::vector<std::string>> findLadders(std::string beginWord,
        std::string endWord, std::unordered_set<std::string> &wordList);


    /**************************************
    Find lowest common ancestor
    https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
    ***************************************/
    bool SearchNode(TreeNode* r, TreeNode* n);
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

private:

    bool TestDiff(std::string w1, std::string w2);
    std::vector<std::vector<std::string>> FindNextWord(std::string b,
        std::string end,
        std::unordered_map<std::string, bool> & rUsedList);

};

#endif ALGO_EX_01_H