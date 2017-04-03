//main  for testing Binary Tree class

#include "BinaryTree.h"

int main()
{
    string input{ "[1, 4, 10, -3, -1, null, 2]" };
    cout << "Input string: " << input << endl;

    //create tree:
    BinaryTree b_tree(input);
    cout << "Print Tree: " << endl;
    TreeHelper::PrintTree(b_tree.getRoot());

    cout << "Pre-order traversal: ";
    TreeHelper::TraversePreOrder(b_tree.getRoot());
    cout << endl;

    cout << "In-order traversal: ";
    TreeHelper::TraverseInOrder(b_tree.getRoot());
    cout << endl;

    cout << "Post-order traversal: ";
    TreeHelper::TraversePostOrder(b_tree.getRoot());
    cout << endl;



    TreeNode *root = new TreeNode(30);
    root->left = new TreeNode(20);
    root->right = new TreeNode(40);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(25);
    root->right->left = new TreeNode(35);
    root->right->right = new TreeNode(50);
    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(15);
    root->left->right->right = new TreeNode(28);
    root->right->right->left = new TreeNode(41);

    cout << "Tree pretty print with level=1 and indentSpace=0\n\n";
    // Output to console
    TreeHelper::PrintTree(root, 1, 0, cout);

    cout << "\n\nTree pretty print with level=5 and indentSpace=3,\noutput to file \"tree_pretty.txt\".\n\n";
    // Create a file and output to that file
    ofstream fout("tree_pretty.txt");
    // Now print a tree that's more spread out to the file
    TreeHelper::PrintTree(root, 5, 0, cout);
    return 0;
}