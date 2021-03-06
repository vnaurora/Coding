//Binary Tree

#include <string>
#include <vector>
#include <exception>
#include "HelperFunctions.h"

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int new_val) :val(new_val), left(nullptr), right(nullptr){};
};

class BinaryTree
{
public:
    BinaryTree() : mRoot(nullptr){};

    //create Binary Tree from a string vector
    //Input format: "[1, 4, 10, -3, -1, null, 2]"
    BinaryTree(const string& input) {
        //parse string, convert into vector:
        vector<int> input_vect = ParseStringToVector(input);
        //read the last one:
        //PrintVector<int>("Input vector", input_vect);
        BuildTree(input_vect);
    }

    //create a binary tree from integer vector
    BinaryTree(const vector<int>& input) {
        BuildTree(input);
    }

    ~BinaryTree() {
        cout << "Delete Tree: ";
        DeleteTree(mRoot);
        cout << endl;
    }

    TreeNode* getRoot() {
        return mRoot;
    }

protected:
    //build tree with vector
    virtual void BuildTree(const vector<int>& input) {
        if (input.empty()) {
            mRoot = nullptr;
            return;
        }
        mRoot = AddNode(input, 0);
    }
    //delete Tree:
    void DeleteTree(TreeNode* node) {
        if (!node) return;
        DeleteTree(node->left);
        DeleteTree(node->right);
        cout << node->val << " ";
        delete node;
    }

    TreeNode* mRoot;

private:
    TreeNode* AddNode(const vector<int>& input, int index) {
        TreeNode* node = nullptr;
        if ((index < input.size()) && (input[index] < MAX_INT)) {
            node = new TreeNode(input[index]);
            node->left = AddNode(input, 2 * index + 1);
            node->right = AddNode(input, 2 * index + 2);
        }
        return node;
    }
};

#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>

class TreeHelper
{
public:
    //Print binary tree diagram:
    static void PrintTree(TreeNode* root) {
        PrintTree(root, 1, 0, cout);
    }
    
    // Pretty formatting of a binary tree to the output stream
    // Ref: http://articles.leetcode.com/how-to-pretty-print-binary-tree/
    // @ param
    // level  Control how wide you want the tree to sparse 
    //(eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
    // indentSpace  Change this to add some indent space to the left 
    //(eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
    //Example:
    //cout << "Tree pretty print with level=1 and indentSpace=0\n\n";
    //// Output to console
    //PrintTree(root, 1, 0, cout);
    //cout << "\n\nTree pretty print with level=5 and indentSpace=3,\noutput to file \"tree_pretty.txt\".\n\n";
    //// Create a file and output to that file
    //ofstream fout("tree_pretty.txt");
    //// Now print a tree that's more spread out to the file
    //PrintTree(root, 5, 0, fout);

    static void PrintTree(TreeNode *root, int level, int indentSpace, ostream& out) {
        int h = maxHeight(root);
        int nodesInThisLevel = 1;

        int branchLen = 2 * ((int)pow(2.0, h) - 1) - (3 - level)*(int)pow(2.0, h - 1);  // eq of the length of branch for each node of each level
        int nodeSpaceLen = 2 + (level + 1)*(int)pow(2.0, h);  // distance between left neighbor node's right arm and right neighbor node's left arm
        int startLen = branchLen + (3 - level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

        deque<TreeNode*> nodesQueue;
        nodesQueue.push_back(root);
        for (int r = 1; r < h; r++) {
            printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
            branchLen = branchLen / 2 - 1;
            nodeSpaceLen = nodeSpaceLen / 2 + 1;
            startLen = branchLen + (3 - level) + indentSpace;
            printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

            for (int i = 0; i < nodesInThisLevel; i++) {
                TreeNode *currNode = nodesQueue.front();
                nodesQueue.pop_front();
                if (currNode) {
                    nodesQueue.push_back(currNode->left);
                    nodesQueue.push_back(currNode->right);
                }
                else {
                    nodesQueue.push_back(NULL);
                    nodesQueue.push_back(NULL);
                }
            }
            nodesInThisLevel *= 2;
        }
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
        printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
    }

    static void TraversePreOrder(TreeNode* node) {
        if (!node) return;
        //visit node
        std::cout << node->val << " ";
        TraversePreOrder(node->left);
        TraversePreOrder(node->right);
    }

    static void TraverseInOrder(TreeNode* node) {
        if (!node) return;
        TraverseInOrder(node->left);
        std::cout << node->val << " "; //visit node
        TraverseInOrder(node->right);
    }

    static void TraversePostOrder(TreeNode* node) {
        if (!node) return;
        TraversePostOrder(node->left);
        TraversePostOrder(node->right);
        std::cout << node->val << " "; //visit node
    }

private:

    // Find the maximum height of the binary tree
    static int maxHeight(TreeNode *p) {
        if (!p) return 0;
        int leftHeight = maxHeight(p->left);
        int rightHeight = maxHeight(p->right);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }

    // Convert an integer value to string
    static string intToString(int val) {
        ostringstream ss;
        ss << val;
        return ss.str();
    }

    // Print the arm branches (eg, /    \ ) on a line
    static void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out) {
        deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
        for (int i = 0; i < nodesInThisLevel / 2; i++) {
            out << ((i == 0) ? setw(startLen - 1) : setw(nodeSpaceLen - 2)) << "" << ((*iter++) ? "/" : " ");
            out << setw(2 * branchLen + 2) << "" << ((*iter++) ? "\\" : " ");
        }
        out << endl;
    }

    // Print the branches and node (eg, ___10___ )
    static void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out) {
        deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
        for (int i = 0; i < nodesInThisLevel; i++, iter++) {
            out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
            out << setw(branchLen + 2) << ((*iter) ? intToString((*iter)->val) : "");
            out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
        }
        out << endl;
    }

    // Print the leaves only (just for the bottom row)
    static void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out) {
        deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
        for (int i = 0; i < nodesInThisLevel; i++, iter++) {
            out << ((i == 0) ? setw(indentSpace + 2) : setw(2 * level + 2)) << ((*iter) ? intToString((*iter)->val) : "");
        }
        out << endl;
    }
};


#endif //BINARY_TREE_H