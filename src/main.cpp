#include <iostream>
#include "../headers/BinarySearchTree.h"
#include "../headers/NumberGenerator.h"

int main(){
    BinarySearchTree<int> tree;
    std::cout << "Tree is empty: " << std::boolalpha << tree.isEmpty() << std::endl;
    std::cout << "Tree contains 50: " << std::boolalpha << tree.contains(50) << std::endl;
    int genny = 138; // 138 generates 100 unique values in an array of size 100
    NumberGenerator gen(genny);
    // std::cout << "Generated array: ";
    // for (int i = 0; i < genny; i++){
    //     std::cout << gen.getArray()[i] << " ";
    // }
    std::cout << std::endl;
    tree.add(50);
    for (int i = 0; i < genny; i++){
        tree.add(gen.getArray()[i]);
    }
    tree.add(2);
    std::cout << "Tree height: " << tree.getHeight() << std::endl;
    std::cout << "Tree size: " << tree.getNumberOfNodes() << std::endl;
    std::cout << "Tree root data: " << tree.getRootData() << std::endl;
    std::cout << "Tree contains 50: " << std::boolalpha << tree.contains(50) << std::endl;
    std::cout << "Tree contains 2: " << std::boolalpha << tree.contains(2) << std::endl;
    std::cout << "Tree is empty: " << std::boolalpha << tree.isEmpty() << std::endl;
    
    std::cout << "preorderTraverse" << std::endl;
    tree.preorderTraverse( [](int& i){ std::cout << i << " "; } );
    std::cout << std::endl << "inorderTraverse" << std::endl;
    tree.inorderTraverse( [](int& i){ std::cout << i << " "; } );
    std::cout << std::endl << "postorderTraverse" << std::endl;
    tree.postorderTraverse( [](int& i){ std::cout << i << " "; } );
    std::cout << std::endl;

    tree.remove(2);
    std::cout  << std::endl << "Tree contains 2: " << std::boolalpha << tree.contains(2) << std::endl;
    std::cout << "inorderTraverse" << std::endl;
    tree.inorderTraverse( [](int& i){ std::cout << i << " "; } );

    tree.clear();
    std::cout  << std::endl << "Tree is empty: " << std::boolalpha << tree.isEmpty() << std::endl;
    return 0;
}