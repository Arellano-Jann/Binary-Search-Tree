#pragma once
#define BINARY_NODE_H

template <typename T>
class BinaryNode {
    T item;
    BinaryNode<T>* leftChildPtr;
    BinaryNode<T>* rightChildPtr;
public:
    BinaryNode();
    BinaryNode(const T& anItem, BinaryNode<T>* leftPtr, BinaryNode<T>* rightPtr);

    void setItem(const T& anItem);
    void setLeftChildPtr(BinaryNode<T>* newLeftChildPtr);
    void setRightChildPtr(BinaryNode<T>* newRightChildPtr);

    T getItem() const;
    BinaryNode<T>* getLeftChildPtr() const;
    BinaryNode<T>* getRightChildPtr() const;

    bool isLeaf() const;
};

#include "../src/BinaryNode.cpp"