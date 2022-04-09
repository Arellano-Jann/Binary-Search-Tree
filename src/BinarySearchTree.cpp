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
        // rootPtr = placeNode(rootPtr, newNodePtr);
        placeNode(rootPtr, newNodePtr);
        return true;
    }
    return false;
}

// removes the node recursively
template <typename T>
bool BinarySearchTree<T>::remove(const T& anEntry){
    bool result = false;
    if(contains(anEntry)){
        // rootPtr = removeValue(rootPtr, anEntry, result); // doesnt make sense right now. it sets the root ptr to be the removed values subTree?
        placeNode(rootPtr, removeValue(rootPtr, anEntry, result));

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

/**
 * @brief Find's the longest edge path from the root to a leaf.
 * @details Checks the left and right heights of the root. This recursively returns the longest path by checking each subsequent subtree's left and right heights.
 * 
 * @tparam T The type of data in the tree.
 * @return int The maximum height of the tree.
 */
template <typename T>
int BinarySearchTree<T>::getHeight() const{
    if (rootPtr == nullptr) return -1;
    else{ // might return double the height
        int leftHeight = 1 + getHeight(rootPtr->getLeftChildPtr());
        int rightHeight = 1 + getHeight(rootPtr->getRightChildPtr());
        return (leftHeight > rightHeight) ? leftHeight : rightHeight;
    }
}

/**
 * @brief Finds the number of nodes in the tree.
 * 
 * @tparam T The type of data in the tree.
 * @return int The number of nodes in the tree.
 */
template <typename T>
int BinarySearchTree<T>::getNumberOfNodes() const{
    if (rootPtr == nullptr) return 0; // might need to return 1 instead idk
    else{ // not sure if this returns double the number of nodes in the tree
        int leftNodes = 1 + getNumberOfNodes(rootPtr->getLeftChildPtr());
        int rightNodes = 1 + getNumberOfNodes(rootPtr->getRightChildPtr());
        return leftNodes + rightNodes;
        // int leftNodes = getNumberOfNodes(rootPtr->getLeftChildPtr());
        // int rightNodes = getNumberOfNodes(rootPtr->getRightChildPtr());
        // return 1 + leftNodes + rightNodes;
    }
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

// Overloaded the function so that it only has one parameter
// template <typename T>
// void BinarySearchTree<T>::preorderTraverse(void visit(T&)) const{
//     preorderTraverse(visit, rootPtr);
// }

/**
 * @brief Recursively traverses the tree in the preorder which means "Node, Left, Right". While traversing, the passed in visit function is called on each node.
 * 
 * @tparam T The type of data in the tree.
 * @param visit The passed in function to be called on each node's data/item.
 * @param nodePtr The node of the tree to be visited.
 */
template <typename T>
void BinarySearchTree<T>::preorderTraverse(void visit(T&), BinaryNode<T>* nodePtr) const{
    visit(nodePtr->getItem());
    if (nodePtr->getLeftChildPtr() != nullptr){
        preorderTraverse(visit, nodePtr->getLeftChildPtr());
    }
    if (nodePtr->getRightChildPtr() != nullptr){
        preorderTraverse(visit, nodePtr->getRightChildPtr());
    }
}

/**
 * @brief Recursively traverses the tree in the inorder which means "Left, Node, Right". While traversing, the passed in visit function is called on each node.
 * 
 * @tparam T The type of data in the tree.
 * @param visit The passed in function to be called on each node's data/item.
 * @param nodePtr The node of the tree to be visited.
 */
template <typename T>
void BinarySearchTree<T>::inorderTraverse(void visit(T&), BinaryNode<T>* nodePtr) const{
    if (nodePtr->getLeftChildPtr() != nullptr){
        preorderTraverse(visit, nodePtr->getLeftChildPtr());
    }
    visit(nodePtr->getItem());
    if (nodePtr->getRightChildPtr() != nullptr){
        preorderTraverse(visit, nodePtr->getRightChildPtr());
    }
}

/**
 * @brief Recursively traverses the tree in the postorder which means "Left, Right, Node". While traversing, the passed in visit function is called on each node.
 * 
 * @tparam T The type of data in the tree.
 * @param visit The passed in function to be called on each node's data/item.
 * @param nodePtr The node of the tree to be visited.
 */
template <typename T>
void BinarySearchTree<T>::postorderTraverse(void visit(T&), BinaryNode<T>* nodePtr) const{
    if (nodePtr->getLeftChildPtr() != nullptr){
        preorderTraverse(visit, nodePtr->getLeftChildPtr());
    }
    if (nodePtr->getRightChildPtr() != nullptr){
        preorderTraverse(visit, nodePtr->getRightChildPtr());
    }
    visit(nodePtr->getItem());
}



// Protected

// Recursive algorithm to find and place node in tree
/**
 * @brief Recursively find the place to insert the node in the tree.
 * @details 1. If the subTreeRootPtr is empty, then the node is placed as the root.
 *         2. The node is placed in the left subtree if the new node is less than the current node
 *          3. The node is placed in the right subtree if the new node is greater than the current node.
 * 
 * @tparam T The type of data in the tree.
 * @param subTreeRootPtr The root of the subtree to search.
 * @param newNodePtr The node to be placed in the tree.
 * @return BinaryNode<T>* The root of the subtree.
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
    return subTreeRootPtr;
}


/**
 * @brief Recursively searches for the target in the subTree and removes it if found. This is a helper method to remove.
 * @details 1. Returns false if the tree is empty or target is not in subTree. \n
 *         2. Checks if subTreeRootPtr is greater than the target. \n
 *        3. If so, recursively searches the left subtree with the removeValue function. \n
 *       4. If not, recursively searches the right subtree with the removeValue function. \n
 *     5. If the target is found, the node is removed with the removeNode function and the function returns true. \n
 * 
 * @tparam T The type of data in the tree.
 * @param subTreeRootPtr The current root of the subTree.
 * @param target The target to delete.
 * @param success Returns true if found and deleted.
 * @return BinaryNode<T>* Returns the filled subtree of the deleted node.
 */
template <typename T>
BinaryNode<T>* BinarySearchTree<T>::removeValue(BinaryNode<T>* subTreeRootPtr, const T target, bool& success){
    if(subTreeRootPtr == nullptr){ // Step 1. // returns false if tree is empty
        success = false;
    }
    else if(subTreeRootPtr->getItem() == target){ // Step 5. // removes node if subTreeRootPtr is the target
        subTreeRootPtr = removeNode(subTreeRootPtr); // what if removal node has a child?
        success = true;
    }
    else if(subTreeRootPtr->getItem() > target){ // Step 3. // target has to be in the left side of the tree if it is less than subTreeRootPtr
        subTreeRootPtr->setLeftChildPtr(removeValue(subTreeRootPtr->getLeftChildPtr(), target, success)); // recursively sets the left child of subTreeRootPtr to the target cascadingly with the removeNode method called at the end
    }
    else{ // Step 4. // target has to be in the right side of the tree if it is greater than subTreeRootPtr
        subTreeRootPtr->setRightChildPtr(removeValue(subTreeRootPtr->getRightChildPtr(), target, success)); // recursively sets the right child of subTreeRootPtr to the target cascadingly with the removeNode method called at the end
    }
    return subTreeRootPtr;
}


/**
 * @brief Removes nodePtr and returns the children of nodePtr. It returns this value to connect to the upper tree. This is a helper method to removeValue.
 * @details 1. If nodePtr is a leaf, there is nothing to connect. \n
 *          2. If nodePtr has a right child, the right child is returned. \n
 *          3. If nodePtr has a left child, the left child is returned. \n
 *         4. If nodePtr has both children, the smallest value in the right subTree of nodePtr is found. Replace the "to be deleted" node's data with the smallest value. Remove the smallest value found in the right subtree since this is now a duplicate. \n
 *          5. This workes because the smallest value in a right subtree should have no left nodes. The only possible nodes for a smallest value in a subtree is right nodes. \n
 * 
 * @tparam T The type of data in the tree.
 * @param nodePtr The node to be deleted.
 * @return BinaryNode<T>* Returns the filled subtree of the deleted node for further connections to the parent.
 */
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
    // this should go to the right side of the nodeTree
    // and find the smallest value in the right subtree
    // and replace the node to be removed with that smallest value
    // afterwards, it should remove the smallest value in the right subtree (which is now a duplicate)
    // Properties: the smallest value in a right subtree should have no left nodes. The only possible nodes for a smallest value in a subtree is right nodes.
        nodeToConnectPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), nodePtr->getItem());
        return nodeToConnectPtr;
        // this modified nodePtr instead of deleting it

        // T inorderSuccessor = findLeftmost(nodePtr->getRightChildPtr()); // there is no findLeftMost method?
        // nodePtr->setItem(inorderSuccessor);
        // nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), inorderSuccessor)); // wtf does this do?
    }
    delete nodePtr;
    return nodeToConnectPtr; // return subtree
}

/**
 * @brief Finds the least value in the tree using subTreeRootPtr as the root. It saves the least value to inorderSuccessor. It then deletes the least value while keeping the structure in tact. This is a helper method to removeNode.
 * @details 1. If subTreeRootPtr has a left child, execute recursively until the least value is found. \n
 *        1b. Set as subTreeRootPtr \n 
 *        2. Set the inorderSuccessor to be the least value. \n
 *        3. Delete the subTreeRootPtr (which is the leastmost value) using removeNode method. This method returns the right subtree of subTreeRootPtr since subTreeRootPtr should not have a left subtree. \n
 *        4. Return the right subtree to use later for connections.
 * 
 * @tparam T The type of the data in the tree.
 * @param subTreeRootPtr The current root of the subTree.
 * @param inorderSuccessor The value to be changed to the least value. Passed in by reference.
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

/**
 * @brief Recursively finds the node in nodePtr with the data value of target.
 * @details 1. If nodePtr is nullptr, return nullptr for not found. \n
 *          2. If nodePtr is the target, return nodePtr. \n
 *          3. If nodePtr is greater than target, execute recursively on the left child. This is the left child because of the equality system of a binary tree. \n
 *          4. If nodePtr is less than target, execute recursively on the right child. \n
 *          5. Repeat recursively until the target is found.
 * 
 * @tparam T The type of the data in the tree.
 * @param nodePtr 
 * @param target Data value to be found.
 * @return BinaryNode<T>* 
 */
template <typename T>
BinaryNode<T>* BinarySearchTree<T>::findNode(BinaryNode<T>* nodePtr, const T& target) const{
    if(nodePtr == nullptr){
        return nullptr;
    }
    else if(nodePtr->getItem() == target){
        return nodePtr;
    }
    else if(nodePtr->getItem() > target){
        return findNode(nodePtr->getLeftChildPtr(), target);
    }
    else{
        return findNode(nodePtr->getRightChildPtr(), target);
    }
}
