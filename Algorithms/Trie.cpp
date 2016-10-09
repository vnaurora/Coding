/**************************************
Permutation
https://leetcode.com/problems/implement-trie-prefix-tree/
***************************************/
#include <string>
#include <iostream>

using namespace std;
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():isKey(false) {
        memset(children, NULL, sizeof(TrieNode*) * 26);
    }
    TrieNode* children[26];
    bool isKey;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if (word.empty()) return;
        TrieNode* t = root;
        for (char c : word){
            if (!t->children[c - 'a']) {
                t->children[c - 'a'] = new TrieNode;
            }
            t = t->children[c - 'a'];
        }
        t->isKey = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if (word.empty()) return false;

        TrieNode* t = root;
        for (char c : word) {
            if (t->children[c - 'a']) {
                t = t->children[c - 'a'];
            }
            else{
                return false;
            }
        }
        return t->isKey;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* t = root;
        for (char c : prefix) {
            if (t->children[c - 'a']) {
                t = t->children[c - 'a'];
            }
            else{
                return false;
            }
        }

        for (int i = 0; i < 25; i++)
        {
            if (t->children[i - 'a']){
                return true;
            }
        }
        return false;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

void main()
{
    Trie my_trie;
    my_trie.insert("abc");
    my_trie.insert("def");
    std::cout << my_trie.search("abc")<<std::endl;
    std::cout << my_trie.search("aaa") << std::endl;
    std::cout << my_trie.startsWith("de") << std::endl;
    std::cout << my_trie.startsWith("df") << std::endl;
}