#include <iostream>
#include <fstream>
#include "../headers/BinarySearchTree.h"
#include "../headers/NumberGenerator.h"


std::ofstream outfile;
int main(){
    BinarySearchTree<int> tree;
    outfile.open("output.txt");

    outfile << "Tree is empty: " << std::boolalpha << tree.isEmpty() << std::endl;

    // Generator
    int genny = 139; // 138 generates 100 unique values in an array of size 100
    NumberGenerator gen(genny);
    // std::cout << "Generated array: ";
    // for (int i = 0; i < genny; i++){
    //     std::cout << gen.getArray()[i] << " ";
    // }
    std::cout << "This has not seg faulted. Hurray!" << std::endl;
    for (int i = 0; i < genny; i++){
        tree.add(gen.getArray()[i]);
    }


    
    outfile << "Tree height: " << tree.getHeight() << std::endl;
    outfile << "Tree size: " << tree.getNumberOfNodes() << std::endl;
    outfile << "Tree root data: " << tree.getRootData() << std::endl;
    outfile << "Tree contains 2: " << std::boolalpha << tree.contains(2) << std::endl;
    outfile << "Tree is empty: " << std::boolalpha << tree.isEmpty() << std::endl;
    
    outfile << "preorderTraverse" << std::endl;
    tree.preorderTraverse( [](int& i) mutable { outfile << std::to_string(i) << " "; } );
    outfile << std::endl << "inorderTraverse" << std::endl;
    tree.inorderTraverse( [](int& i) mutable { outfile << std::to_string(i) << " "; } );
    outfile << std::endl << "postorderTraverse" << std::endl;
    tree.postorderTraverse( [](int& i) mutable { outfile << std::to_string(i) << " "; } );
    outfile << std::endl;

    // tree.remove(2);
    // outfile  << std::endl << "Tree contains 2: " << std::boolalpha << tree.contains(2) << std::endl;
    // outfile << "inorderTraverse" << std::endl;
    // tree.inorderTraverse( [](int& i){ std::cout << i << " "; } );

    tree.clear();
    outfile  << std::endl << "Tree is empty: " << std::boolalpha << tree.isEmpty() << std::endl;
    outfile.close();
    return 0;
}