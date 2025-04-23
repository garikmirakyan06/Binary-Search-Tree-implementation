#include <iostream>
#include "BST.h"


int main() {
    bst<int>tree;
	
	tree.insert(3);
	tree.insert(3);
	tree.insert(3);
	tree.insert(5);
	tree.insert(3);
	tree.printBFS();
	tree.erase(5);
	tree.printBFS();
	
	
	std::cout << tree.size();


    return 0;
}


