#include <iostream>
#include "../headers/BinarySearchTree.h"
#include "../headers/NumberGenerator.h"

int main(){
    BinarySearchTree<int> tree;
    NumberGenerator gen(100);
    std::cout << "Generated array: ";
    for (int i = 0; i < 100; i++){
        std::cout << gen.getArray()[i] << " ";
    }
    tree.add(1);
    for (int i = 0; i < 100; i++){
        tree.add(gen.getArray()[i]);
        tree.add(i);
    }
    tree.add(2);
    std::cout << "Tree height: " << tree.getHeight() << std::endl;
    std::cout << "Tree size: " << tree.getNumberOfNodes() << std::endl;
    std::cout << "Tree root data: " << tree.getRootData() << std::endl;
    
    std::cout << "preorderTraverse" << std::endl;
    tree.preorderTraverse( [](int& i){ std::cout << i << " "; } );
    std::cout << std::endl << "inorderTraverse" << std::endl;
    tree.inorderTraverse( [](int& i){ std::cout << i << " "; } );
    std::cout << std::endl << "postorderTraverse" << std::endl;
    tree.postorderTraverse( [](int& i){ std::cout << i << " "; } );
    return 0;
}