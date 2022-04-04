#pragma once
#define BINARY_SEARCH_TREE_H

#include "TreeInterface.h"
#include "BinaryNode.h"

template <typename T>
class BinarySearchTree : public TreeInterface<T> {
    BinaryNode<T>* rootPtr;

protected:
    BinaryNode<T>* placeNode(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr);
    BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T target, bool& success);
    BinaryNode<T>* removeNode(BinaryNode<T>* nodePtr);
    BinaryNode<T>* removeLeftmostNode(BinaryNode<T>* nodePtr, T& inorderSuccessor);
    BinaryNode<T>* findNode(BinaryNode<T>* nodePtr, const T& target) const;

public:
    BinarySearchTree();

    bool add(const T& newEntry) override;
    bool remove(const T& anEntry) override;
    void clear() override;
    int getHeight() const override;
    int getNumberOfNodes() const override;
    T getRootData() const override;
    T getEntry(const T& anEntry) const override;
    bool contains(const T& anEntry) const override;
    bool isEmpty() const override;

    void preorderTraverse(void visit(T&)) const;
    void inorderTraverse(void visit(T&)) const;
    void postorderTraverse(void visit(T&)) const;

    ~BinarySearchTree();

};
#include "../src/BinarySearchTree.cpp"