//Binary search tree
#ifndef BST_H
#define BST_H
#include "BinaryTree.h"
#include "HelperFunctions.h"
class BST :public BinaryTree
{
public:
    BST() :BinaryTree(){};
    //create a BST from a string:
    BST(const string& input){
        vector<int> input_vect = ParseStringToVector(input);
        BuildTree(input_vect);
    }

    //create a binary tree from integer vector
    BST(const vector<int>& input){
        BuildTree(input);
    }
protected:
    virtual void BuildTree(const vector<int>& input) override
    {
        for (auto v : input) {
            if (v < MAX_INT) AddBSTNode(mRoot, v);
        }
    }
private:
    void AddBSTNode(TreeNode* & node, int val) { //note: don't forget &.
        if (!node) {
            node = new TreeNode(val);
            return;
        }
        if (val < node->val) AddBSTNode(node->left, val);
        else AddBSTNode(node->right, val);
    }
};
#endif