#include "AlgoEx01.h"
#include <algorithm>
#include <queue>
#include <functional>
#include <iterator>

#ifndef MAX_INT
#define MAX_INT 2147483647
#endif
#ifndef MIN_INT
#define MIN_INT -MAX_INT
#endif
std::pair<int, int> AlgoEx01::FindMinRangeOfKSortedLists(std::vector<std::vector<int>>& rLists)
{
    //Note: this is unnecessary because the lists are sorted.
    for (auto it = rLists.begin(); it != rLists.end(); it++)
    {
        //sort list in ascending order
        std::sort((*it).begin(), (*it).end(), [](int a, int b){ return a < b; });
    }

    int val_min = MAX_INT;
    int val_max = MIN_INT;
    int val_range = val_max - val_min;

    typedef std::vector<std::vector<int>>::iterator ListIter;
    typedef std::vector<int>::iterator ItemIter;
    //a new type to save the value and also which list it belongs to.
    typedef std::pair<int, ListIter> QueueNode;


    auto cmp = [](const QueueNode& a, const QueueNode& b) {return a.first > b.first; };
    std::priority_queue<QueueNode, std::vector<QueueNode>, decltype(cmp)> q;
    //std::vector<int> v(rLists.size());
    std::vector<int> vect_it(rLists.size(),0); //store the current position of each list
    //Push first K elements in the queue
    for (auto it = rLists.begin(); it != rLists.end(); it++)
    {
        q.push(std::make_pair(*(*it).begin(), it));
    }
    //std::vector<decltype(std::distance((*rLists.begin()).begin(), (*rLists.begin()).end()))> b;

    while (1)
    {
        ListIter list_iter = q.top().second; //get the list iter of the top of the queue
        auto list_index = std::distance(rLists.begin(), list_iter); //convert iter to index int
        ItemIter it = (*list_iter).begin();
        //increase item iter of that list.
        std::advance(it, ++vect_it[list_index]);
        if (it == (*list_iter).end()) //if end of that list
        {
            break; //end loop
        }
        if (*it < q.top().first)
        {
            q.pop();
            q.push(std::make_pair(*it, list_iter));
            //update
            if (*it > val_max)
            {
                val_max = *it;
                val_range = val_max - val_min;
            }
            else if (*it < val_min)
            {
                val_min = *it;
                val_range = val_max - val_min;
            }
        }
    }
    //NOTE: UNFINISHED, NOT TESTED YET.
    return std::make_pair(val_min, val_min + val_range);
}

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
std::vector<std::vector<std::string>> AlgoEx01::findLadders(std::string beginWord,
    std::string endWord, std::unordered_set<std::string> &wordList)
{
    std::vector<std::vector<std::string>> ret;
    
    return ret;
}

bool TestDiff(std::string w1, std::string w2)
{
    int diff_count = 0;
    for (auto i: w1)
    {
        if (w1[i] != w2[i])
        {
            diff_count++;
        }
    }
    return (diff_count == 1) ? true : false;
}

std::vector<std::vector<std::string>> FindNextWord(const std::string& rWord,
    const std::string& rEndWord,
    std::unordered_map<std::string, bool> & rUsedList)
{
    typedef std::vector<std::string> stringlist;
    typedef std::vector<stringlist> transformlist;
    if (TestDiff(rWord, rEndWord))
    {
        //last transform
        stringlist sl = { rWord };
        transformlist tl = { sl };
        return tl;
    }
    else
    {
        int i = -1;
        transformlist min_path;
        for (auto next_word : rUsedList) //Note: iterator of rWordList is different to that of the rUsedList
        {
            i++;
            if (!next_word.second) //check if it's used (false = not used)
            {
                if (TestDiff(rWord, next_word.first))
                {
                    //transformlist path = FindNextWord(next_word.first, rEndWord, rUsedList)
                }
                //(TestDiff(rWord, rWordList[it])))
            }
        }
    }
}

/**
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
**/
/**
* Definition for a binary tree node.
**/

bool AlgoEx01::SearchNode(TreeNode* r, TreeNode* n)
{
    if (!r) return false;
    if (r == n) return true;
    return (SearchNode(r->left, n) || SearchNode(r->right, n));
}

//UNFINISHED!
TreeNode* AlgoEx01::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if (!root) return nullptr;

    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    if (!l) return l;

    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if (!r) return r;

    if (SearchNode(root, p) && SearchNode(root, q))
        return root;

    return nullptr;
}

/**************************************
Capture surrounded regions
https://leetcode.com/problems/surrounded-regions/
***************************************/
#include <stack>
void AlgoEx01::CaptureRegions(std::vector<std::vector<char>> & board)
{
    int row_num = board.size();
    if (row_num == 0) return;
    int col_num = board[0].size();
    if (col_num == 0) return;
    std::stack<std::pair<int, int>> todo;
    //check first and last row
    for (int c = 0; c < col_num; c++)
    {
        if (board[0][c] == 'O') {
            board[0][c] = 'A';
            todo.push(std::make_pair(0, c));
        }
        if (board[row_num-1][c] == 'O') {
            board[row_num - 1][c] = 'A';
            todo.push(std::make_pair(row_num - 1, c));
        }
    }
    //check first and last column
    for (int r = 1; r < row_num; r++)
    {
        if (board[r][0] == 'O') {
            board[r][0] = 'A';
            todo.push(std::make_pair(r, 0));
        }
        if (board[r][col_num - 1] == 'O') {
            board[r][col_num - 1] = 'A';
            todo.push(std::make_pair(r, col_num - 1));
        }
    }

    while (!todo.empty())
    {
        std::pair<int, int> p = todo.top();
        todo.pop();
        //check left:
        if (p.second > 1) {
            if (board[p.first][p.second - 1] == 'O') {
                board[p.first][p.second - 1] = 'A';
                todo.push(std::make_pair(p.first, p.second - 1));
            }
        }
        //check right:
        if (p.second < col_num-1) {
            if (board[p.first][p.second + 1] == 'O') {
                board[p.first][p.second + 1] = 'A';
                todo.push(std::make_pair(p.first, p.second + 1));
            }
        }
        //check top
        if (p.first > 1){
            if (board[p.first-1][p.second] == 'O') {
                board[p.first-1][p.second] = 'A';
                todo.push(std::make_pair(p.first-1, p.second));
            }
        }
        //check down
        if (p.first < row_num - 1){
            if (board[p.first + 1][p.second] == 'O') {
                board[p.first + 1][p.second] = 'A';
                todo.push(std::make_pair(p.first + 1, p.second));
            }
        }
    }

    for (int r = 0; r < row_num; r++) {
        for (int c = 0; c < col_num; c++) {
            if (board[r][c] == 'O') board[r][c] = 'X';
            if (board[r][c] == 'A') board[r][c] = 'O';
        }
    }
}

/**************************************
Decode ways
https://leetcode.com/problems/decode-ways/
Too long!! 
Good solution using dynamic programming:
https://discuss.leetcode.com/topic/7025/a-concise-dp-solution/12
***************************************/
int numDecodings(std::string s)
{
    if (s.size() == 0) return 0;
    return computeDecodeWays(s, 0);
}

int computeDecodeWays(const std::string& s, int pos)
{
    if (pos == s.size()) return 1;
    if (pos == (s.size() - 1)) {
        return (s[pos] != '0') ? 1 : 0;
    }

    if (s[pos] > '2') {
        return computeDecodeWays(s, pos + 1);
    }
    else if (s[pos] == '1') {
        return computeDecodeWays(s, pos + 1) + computeDecodeWays(s, pos + 2);
    }
    else if (s[pos] == '2') {
        return (s[pos + 1] <= '6') ?
            computeDecodeWays(s, pos + 1) + computeDecodeWays(s, pos + 2) : computeDecodeWays(s, pos + 1);
    }
    else { //s[pos] == '0'
        return 0;
    }
}

/**************************************
Permutation
https://leetcode.com/problems/permutations/
***************************************/
#include <queue>
vector<vector<int>> permute(vector<int> & nums)
{
    typedef vector<vector<int>> PerList;
    if (nums.empty()) return PerList();

    queue<vector<int>> prev, curr;
    prev.push(vector<int>{nums[0]});
    for (int i = 0; i < nums.size(); i++)
    {
        while (!prev.empty()) {
            auto v = prev.front();
            prev.pop();
            for (int j = 0; j <= v.size(); j++) {
                auto v2 = v;
                v2.insert(v2.begin(), j, nums[i]);
                curr.push(v2);
            }
        }
        curr.swap(prev);
    }
    PerList ret;
    while (!prev.empty()) {
        ret.push_back(prev.front());
        prev.pop();
    }
}
