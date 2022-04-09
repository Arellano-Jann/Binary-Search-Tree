#include <iostream>
#include 
#include "../headers/BinarySearchTree.h"

int main(){
    BinarySearchTree<int> tree;

    tree.add(5);
    tree.add(3);
    tree.add(10);
    tree.add(2);
    tree.add(4);
    tree.add(8);
    tree.add(9);
    tree.add(11);
    return 0;
}