#ifndef BSTNODE_H
#define BSTNODE_H

template <typename T>
class bstnode {
public:
    T data;
    bstnode* left;
    bstnode* right;
    bstnode* parent;

    bstnode() : left(nullptr), right(nullptr), parent(nullptr) {}
    bstnode(const T& data) : data(data), left(nullptr), right(nullptr), parent(nullptr) {} 

    bool addLeft(bstnode* l);
    bool addRight(bstnode* r);


};


template <typename T>
bool bstnode<T>::addLeft(bstnode* l) {
    if(left)
        return false;
 
    left = l;
    left->parent = this;
    return true;
}


template <typename T>
bool bstnode<T>::addRight(bstnode* r) {
    if(right)
        return false;
 
    right = r;
    right->parent = this;
    return true;
}




#endif