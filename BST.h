#ifndef BST_H
#define BST_H
#include "BSTNode.h"
#include <iostream>
#include <queue>


template <typename T>
class bst {
private:
    bstnode<T>* root;
    size_t m_size;

    bstnode<T>* findHelper(const T& obj) const;
    bstnode<T>* nextNode(bstnode<T>* node) const;
    void deleteTree(bstnode<T>* node);


public: 
    bst() : root(nullptr), m_size(0) {}
    bst(bstnode<T>* r) : root(r), m_size(0) {}
    ~bst() {
        deleteTree(root);
    }

    T findMin() const;         // O(logn)
    T findMax() const;         // O(logn)
    void printBFS() const; // O(n)
    size_t size() const;

    bool insert(const T& obj);     // O(logn) 
    bool erase(const T& obj);      // O(n) 
    bool find(const T& obj) const; // O(logn)
    

};

// deleteTree 
template <typename T>
void bst<T>::deleteTree (bstnode<T>* node) {
    if(node->left)
        deleteTree(node->left);
    if(node->right)
        deleteTree(node->right);
    
    delete node;
}


// size
template <typename T>
size_t bst<T>::size() const { 
    return m_size;
}


// erase 
template <typename T>
bool bst<T>::erase(const T& obj) {
    bstnode<T>* node = findHelper(obj);

    if(node == nullptr) {
        return false;
    }
    m_size--;
    // case 1 (the deleting node is leaf)
    if(node->left == nullptr && node->right == nullptr) {
        if(!node->parent) { // if node does not have parent node
            root = nullptr;
        }
        else if(node->data > node->parent->data) { // if node is right child
            node->parent->right = nullptr;
        }
        else { // is node is left child
            node->parent->left = nullptr;
        }
        return true;
    }

    // case 2 (deleting node have only one child)
    if(node->left == nullptr) {
        if(!node->parent) { 
            root = node->right;
            root->parent = nullptr;
        }
        else if(node->parent->data > node->data) {
            node->parent->left = node->right;
            node->right->parent = node->parent; // updating the parent node                                
        }
        else {
            node->parent->right = node->right;
            node->right->parent = node->parent; // updating the parent node                                
        }
        return true;
    }
    if(node->right == nullptr) {
        if(!node->parent) { 
            root = node->left;
            root->parent = nullptr;
        }
        else if(node->parent->data > node->data) { // node is left child
            node->parent->left = node->left;
            node->left->parent = node->parent; // updating the parent node                                
        }
        else { // node is right child
            node->parent->right = node->left;
            node->left->parent = node->parent; // updating the parent node                                
        }
        return true;
    }

    // case 3 (have two childs)
    bstnode<T>* next = nextNode(node);
    // if next is leaf next->right will be nullptr
    // else it will have only right child
    if(next->data > next->parent->data) { // next is right child
        next->parent->right = next->right;
        if(next->right)
            next->right->parent = next->parent;
    }
    else { // next is left child

        next->parent->left = next->right;
        if(next->right)   
            next->right->parent = next->parent;
    }
    node->data = next->data;

    return true;
}


// nextNode
template <typename T>
bstnode<T>* bst<T>::nextNode(bstnode<T>* node) const {
    auto temp = node->right;
    while(temp->left) {
        temp = temp->left;
    }
    return temp;
}



// findHelper
template <typename T>
bstnode<T>* bst<T>::findHelper(const T& obj) const {
    if(!root) {
        return nullptr;
    }
    auto temp = root;
    while(temp) {
        if(temp->data == obj) {
            return temp;
        }
        if(temp->data > obj) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return nullptr;
}

// find
template <typename T>
bool bst<T>::find(const T& obj) const {
    if(findHelper(obj) == nullptr) {
        return false;
    }
    return true;
}

// printBFS
template <typename T>
void bst<T>::printBFS() const {
    if(!root) {
        return;
    }
    std::queue<bstnode<T>*>q;
    q.push(root);
    while(!q.empty()) {
        int qsize = q.size();
        for(int i = 0; i < qsize; i++) {
            auto node = q.front();
            std::cout << node->data << ' ';
            q.pop();
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        std::cout << '\n';


    }
    std::cout << '\n';
} 


// insert 
template <typename T>
bool bst<T>::insert(const T& obj) {
    if(!root) {
        root = new bstnode<T>(obj);
        m_size++;
        return true;
    }

    bstnode<T>* temp = root, *parentNode = root;
    while(temp) {
        if(temp->data == obj) {
            return false;
        }
        if(temp->data > obj) {
            parentNode = temp;
            temp = temp->left;
        }
        else {
            parentNode = temp;
            temp = temp->right;
        }
    }
    auto newnode = new bstnode<T>(obj);
    if(obj > parentNode->data) {
        parentNode->addRight(newnode);
    }
    else {
        parentNode->addLeft(newnode);
    }

    m_size++;
    return true;

}

// min 
template <typename T>
T bst<T>::findMin() const {
    if(root == nullptr) {
        throw std::logic_error("Tree is empty\n");
    }

    auto temp = root;

    while(temp->left) {
        temp = temp->left;
    }
    return temp->data;
}


// max
template <typename T>
T bst<T>::findMax() const {
    if(root == nullptr) {
        throw std::logic_error("Tree is empty\n");
    }

    auto temp = root;

    while(temp->right) {
        temp = temp->right;
    }
    return temp->data;
}



#endif 
