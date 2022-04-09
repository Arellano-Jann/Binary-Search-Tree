// The good stuff

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
    : rootPtr(nullptr)
{}

// adds the node recursively
template <typename T>
bool BinarySearchTree<T>::add(const T& newEntry){
    if(!contains(newEntry)){
        BinaryNode<T>* newNodePtr = new BinaryNode<T>(newEntry);
        rootPtr = placeNode(rootPtr, newNodePtr);
        return true;
    }
    return false;
}

// removes the node recursively
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

// Recursive algorithm to find and place node in tree
/**
 * @brief DO THIS
 * 
 * @tparam T The type of data in the tree.
 * @param subTreeRootPtr 
 * @param newNodePtr 
 * @return BinaryNode<T>* 
 */
template <typename T>
BinaryNode<T>* BinarySearchTree<T>::placeNode(BinaryNode<T>* subTreeRootPtr, BinaryNode<T>* newNodePtr){
    if(subTreeRootPtr == nullptr){ // places node in subTreeRootPtr if subTree is empty
        subTreeRootPtr = newNodePtr;
    }
    else if(newNodePtr->getItem() < subTreeRootPtr->getItem()){ // places node in left subtree if newNode is less than subTreeRootPtr
        subTreeRootPtr->setLeftChildPtr(placeNode(subTreeRootPtr->getLeftChildPtr(), newNodePtr));
    }
    else{ // places node in right subtree if newNode is greater than to subTreeRootPtr
    // this will never be equal to the subTreeRootPtr because this method is only used in the add method and the add method has a check if the node is in the tree
        subTreeRootPtr->setRightChildPtr(placeNode(subTreeRootPtr->getRightChildPtr(), newNodePtr));
    }
    return subTreePtr;
}

// Recursive algorithm to remove node from tree
template <typename T>
BinaryNode<T>* BinarySearchTree<T>::removeValue(BinaryNode<T>* subTreeRootPtr, const T target, bool& success){
    if(subTreeRootPtr == nullptr){ // returns false if tree is empty
        success = false;
    }
    else if(subTreeRootPtr->getItem() == target){ // removes node if subTreeRootPtr is the target
        subTreeRootPtr = removeNode(subTreeRootPtr); // what if removal node has a child?
        success = true;
    }
    else if(subTreeRootPtr->getItem() > target){ // target has to be in the left side of the tree if it is less than subTreeRootPtr
        subTreeRootPtr->setLeftChildPtr(removeValue(subTreeRootPtr->getLeftChildPtr(), target, success)); // recursively sets the left child of subTreeRootPtr to the target cascadingly with the removeNode method called at the end
    }
    else{ // target has to be in the right side of the tree if it is greater than subTreeRootPtr
        subTreeRootPtr->setRightChildPtr(removeValue(subTreeRootPtr->getRightChildPtr(), target, success)); // recursively sets the right child of subTreeRootPtr to the target cascadingly with the removeNode method called at the end
    }
    return subTreeRootPtr;
}

// helper method to removeValue. connects the children of the node to be removed to the upper tree
template <typename T>
BinaryNode<T>* BinarySearchTree<T>::removeNode(BinaryNode<T>* nodePtr){
    BinaryNode<T>* nodeToConnectPtr;
    if(nodePtr->isLeaf()){ // if there are no children, this doesn't matter
        nodeToConnectPtr = nullptr;
    }
    else if(nodePtr->getLeftChildPtr() == nullptr){ // if there is only a right child, set nodeToConnect as the right child
        nodeToConnectPtr = nodePtr->getRightChildPtr();
    }
    else if(nodePtr->getRightChildPtr() == nullptr){ // if there is only a left child, set nodeToConnect as the left child
        nodeToConnectPtr = nodePtr->getLeftChildPtr();
    }
    else{ // if there is 2 children, this executes
    // this should find the go to the right side of the nodeTree
    // and find the smallest value in the right subtree
    // and replace the node to be removed with that smallest value
    // afterwards, it should remove the smallest value in the right subtree (which is now a duplicate)
    // Properties: the smallest value in a right subtree should have no left nodes. The only possible nodes for a smallest value in a subtree is right nodes.
        T inorderSuccessor = findLeftmost(nodePtr->getRightChildPtr()); // there is no findLeftMost method?
        nodePtr->setItem(inorderSuccessor);
        nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), inorderSuccessor)); // wtf does this do?
    }
    delete nodePtr;
    return nodeToConnectPtr; // return subtree if 0 or 1 child
}

/**
 * @brief Finds the least value in the tree using subTreeRootPtr as the root. It then deletes the least value while keeping the structure in tact.
 * @details 1. If subTreeRootPtr has a left child, execute recursively until the least value is found. \n
 *        1b. Set as subTreeRootPtr \n 
 *        2. Set the inorderSuccessor to be the least value. \n
 *        3. Delete the subTreeRootPtr using removeNode method. This method returns the right subtree of subTreeRootPtr since subTreeRootPtr should not have a left subtree. \n
 *        4. Return the right subtree to use later for connections.
 * 
 * @tparam T The type of the data in the tree.
 * @param subTreeRootPtr The current root of the subTree.
 * @param inorderSuccessor The least value. Passed in by reference.
 * @return BinaryNode<T>* Returns the right subtree of the leftmost node.
 */
template <typename T>
BinaryNode<T>* BinarySearchTree<T>::removeLeftmostNode(BinaryNode<T>* subTreeRootPtr, T& inorderSuccessor){
    if(subTreeRootPtr->getLeftChildPtr() == nullptr){ // Step 1b. // if there is no further left pointer, this sets the inorderSuccessor to be the least most value
        inorderSuccessor = subTreeRootPtr->getItem(); // Step 2.
        return removeNode(subTreeRootPtr); // Step 3 and 4. // this then removes the node that was copied from and connects to the parent using the removeNode method
    }
    else{ // Step 1. // if there is a left child, then there is something of a lesser value and this executes recursively finding the least value
        subTreeRootPtr->setLeftChildPtr(removeLeftmostNode(subTreeRootPtr->getLeftChildPtr(), inorderSuccessor));
    }
    return subTreeRootPtr;
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
