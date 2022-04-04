// The good stuff
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
    : rootPtr(nullptr)
{}

template <typename T>
bool BinarySearchTree<T>::add(const T& newEntry){
    bool result = false;
    if(!contains(newEntry)){
        BinaryNode<T>* newNodePtr = new BinaryNode<T>(newEntry);
        rootPtr = placeNode(rootPtr, newNodePtr);
        result = true;
    }
    return result;
}

template <typename T>
bool BinarySearchTree<T>::remove(const T& anEntry){
    bool result = false;
    if(contains(anEntry)){
        rootPtr = removeValue(rootPtr, anEntry, result);
    }
    return result;
}

template <typename T>
void BinarySearchTree<T>::clear(){
    while(!isEmpty()){
        remove(getRootData());
    }
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
    T result;
    if(rootPtr != nullptr){
        result = rootPtr->getItem();
    }
    return result;
}

template <typename T>
T BinarySearchTree<T>::getEntry(const T& anEntry) const{
    T result;
    BinaryNode<T>* nodePtr = findNode(rootPtr, anEntry);
    if(nodePtr != nullptr){
        result = nodePtr->getItem();
    }
    return result;
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& anEntry) const{
    return findNode(rootPtr, anEntry) != nullptr;
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const{
    return rootPtr == nullptr;
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
BinaryNode<T>* BinarySearchTree<T>::placeNode(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr){
    if(subTreePtr == nullptr){
        subTreePtr = newNodePtr;
    }
    else if(newNodePtr->getItem() < subTreePtr->getItem()){
        subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNodePtr));
    }
    else{
        subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNodePtr));
    }
    return subTreePtr;
}

template <typename T>
BinaryNode<T>* BinarySearchTree<T>::removeValue(BinaryNode<T>* subTreePtr, const T target, bool& success){
    if(subTreePtr == nullptr){
        success = false;
    }
    else if(subTreePtr->getItem() == target){
        subTreePtr = removeNode(subTreePtr);
        success = true;
    }
    else if(subTreePtr->getItem() > target){
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
    }
    else{
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
    }
    return subTreePtr;
}

template <typename T>
BinaryNode<T>* BinarySearchTree<T>::removeNode(BinaryNode<T>* nodePtr){
    BinaryNode<T>* nodeToConnectPtr;
    if(nodePtr->isLeaf()){
        nodeToConnectPtr = nullptr;
    }
    else if(nodePtr->getLeftChildPtr() == nullptr){
        nodeToConnectPtr = nodePtr->getRightChildPtr();
    }
    else if(nodePtr->getRightChildPtr() == nullptr){
        nodeToConnectPtr = nodePtr->getLeftChildPtr();
    }
    else{
        T inorderSuccessor = findLeftmost(nodePtr->getRightChildPtr());
        nodePtr->setItem(inorderSuccessor);
        nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), inorderSuccessor));
    }
    delete nodePtr;
    return nodeToConnectPtr;
}

template <typename T>
BinaryNode<T>* BinarySearchTree<T>::removeLeftmostNode(BinaryNode<T>* nodePtr, T& inorderSuccessor){
    if(nodePtr->getLeftChildPtr() == nullptr){
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    }
    else{
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
    }
    return nodePtr;
}

template <typename T>
BinaryNode<T>* BinarySearchTree<T>::findNode(BinaryNode<T>* nodePtr, const T& target) const{
    if(nodePtr == nullptr){
        return nullptr;
    }
    else if(nodePtr->getItem() == target){
        return nodePtr;
    }
    else if(target < nodePtr->getItem()){
        return findNode(nodePtr->getLeftChildPtr(), target);
    }
    else{
        return findNode(nodePtr->getRightChildPtr(), target);
    }
}
