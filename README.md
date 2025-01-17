# Binary-Search-Tree-Implementation

This repository contains an implementation of a generic Binary Search Tree (BST) in C++. The implementation provides essential methods for searching, inserting, deleting, and traversing elements within the tree. The structure is designed to be efficient and easy to use for various data types.

## Features

- **Generic Implementation**: The BST is implemented as a templated class, making it compatible with any data type that supports comparison operators.
- **Core Functionalities**:
  - **Find Minimum**: Retrieve the smallest value in the tree.
  - **Find Maximum**: Retrieve the largest value in the tree.
  - **Breadth-First Search (BFS)**: Print all nodes in level-order traversal.
  - **Insert**: Add a new element to the tree.
  - **Erase**: Remove an element from the tree.
  - **Find**: Check if an element exists in the tree.
  - **Size**: Retrieve the number of elements in the tree.
- **Time Complexities**:
  - `findMin()` and `findMax()`: **O(log n)** (average case)
  - `insert()` and `find()`: **O(log n)** (average case)
  - `erase()`: **O(n)** (worst case for unbalanced trees)
  - `printBFS()`: **O(n)**

## Methods

### `T findMin() const`
Returns the smallest value in the BST.

- **Time Complexity**: O(log n) (average case)
- **Returns**: Minimum element of type `T`.

### `T findMax() const`
Returns the largest value in the BST.

- **Time Complexity**: O(log n) (average case)
- **Returns**: Maximum element of type `T`.

### `void printBFS() const`
Prints the tree's nodes in level-order traversal.

- **Time Complexity**: O(n)

### `size_t size() const`
Returns the number of elements in the tree.

- **Time Complexity**: O(1)

### `bool insert(const T& obj)`
Inserts an element into the BST.

- **Time Complexity**: O(log n) (average case)
- **Parameters**: `obj` - the element to be inserted.
- **Returns**: `true` if the insertion is successful, `false` if the element already exists.

### `bool erase(const T& obj)`
Removes an element from the BST.

- **Time Complexity**: O(n) (worst case for unbalanced trees)
- **Parameters**: `obj` - the element to be removed.
- **Returns**: `true` if the removal is successful, `false` if the element does not exist.

### `bool find(const T& obj) const`
Searches for an element in the BST.

- **Time Complexity**: O(log n) (average case)
- **Parameters**: `obj` - the element to find.
- **Returns**: `true` if the element is found, `false` otherwise.

## Usage

```cpp
#include <iostream>
#include "BST.h"


int main() {
    bst<int> tree;

    // Insert elements
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    // Find elements
    if (tree.find(10)) {
        std::cout << "10 is in the tree!" << std::endl;
    }

    // Print elements in BFS order
    tree.printBFS();

    // Find minimum and maximum
    std::cout << "Minimum: " << tree.findMin() << std::endl;
    std::cout << "Maximum: " << tree.findMax() << std::endl;

    // Erase an element
    tree.erase(5);

    // Check size
    std::cout << "Tree size: " << tree.size() << std::endl;

    return 0;
}
