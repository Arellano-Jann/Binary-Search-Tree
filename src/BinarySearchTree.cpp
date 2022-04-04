// The good stuff
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
    : rootPtr(nullptr)
{}

template <typename T>
bool BinarySearchTree<T>::add(const T& newEntry){

}

template <typename T>
bool BinarySearchTree<T>::remove(const T& anEntry){

}

template <typename T>
void BinarySearchTree<T>::clear(){

}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){ clear(); }



// Info Getters

template <typename T>
int BinarySearchTree<T>::getHeight() const{

}

template <typename T>
int BinarySearchTree<T>::getNumberOfNodes() const{

}

template <typename T>
T BinarySearchTree<T>::getRootData() const{

}

template <typename T>
T BinarySearchTree<T>::getEntry(const T& anEntry) const{

}

template <typename T>
bool BinarySearchTree<T>::contains(const T& anEntry) const{

}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const{

}



// Traversals

template <typename T>
void BinarySearchTree<T>::preorderTraverse(void visit(T&)) const{

}

template <typename T>
void BinarySearchTree<T>::inorderTraverse(void visit(T&)) const{

}

template <typename T>
void BinarySearchTree<T>::postorderTraverse(void visit(T&)) const{

}



// Protected

template <typename T>
BinaryNode<T>* placeNode(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr){

}

template <typename T>
BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T target, bool& success){

}

template <typename T>
BinaryNode<T>* removeNode(BinaryNode<T>* nodePtr){

}

template <typename T>
BinaryNode<T>* removeLeftmostNode(BinaryNode<T>* nodePtr, T& inorderSuccessor){

}

template <typename T>
BinaryNode<T>* findNode(BinaryNode<T>* nodePtr, const T& target) const{

}
