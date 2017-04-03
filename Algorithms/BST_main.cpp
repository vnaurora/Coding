//main for testing Binary Search Tree class
#include "BST.h"

int main()
{
    string input{ "[1, 4, 10, -3, -1, null, 2]" };
    cout << "Input string: " << input << endl;
    
    //BST empty_bst;
    //create tree:
    BST bst(input);
    cout << "Print Tree: " << endl;
    TreeHelper::PrintTree(bst.getRoot());
}
