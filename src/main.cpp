#include <iostream>
#include "../headers/BinarySearchTree.h"
#include "../headers/NumberGenerator.h"

int main(){
    BinarySearchTree<int> tree;
    NumberGenerator gen(100);
    for (int i = 0; i < 100; i++){
        tree.add(gen.getArray()[i]);
    }
    tree.preorderTraverse( [] (int& i){ std::cout << i << " "; } );
    return 0;
}