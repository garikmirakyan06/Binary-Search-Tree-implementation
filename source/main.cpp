#include <iostream>
#include "BST.h"


int main() {
    bst<int>tree;
    tree.insert(5);
    tree.insert(52);
    tree.insert(57);
    tree.insert(53);
    tree.insert(555);
    // tree.insert(53);
    
    std::cout << tree.findMax();



    return 0;
}


