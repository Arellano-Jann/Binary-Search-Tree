template <typename T>
BinaryNode<T>::BinaryNode()
    : item(T()) // wtf is this? declare a variable of type T and initialize it to the default value of T?
    , leftChildPtr(nullptr)
    , rightChildPtr(nullptr)
    {}

template <typename T>
BinaryNode<T>::BinaryNode(const T& anItem, BinaryNode<T>* leftPtr, BinaryNode<T>* rightPtr)
// BinaryNode<T>::BinaryNode(const T& anItem, BinaryNode<T>* leftPtr = nullptr, BinaryNode<T>* rightPtr = nullptr) // not sure if this or above works
    : item(anItem)
    , leftChildPtr(leftPtr)
    , rightChildPtr(rightPtr)
    {}

template <typename T>
void BinaryNode<T>::setItem(const T& anItem){ item = anItem; }

template <typename T>
void BinaryNode<T>::setLeftChildPtr(BinaryNode<T>* newLeftChildPtr){ leftChildPtr = newLeftChildPtr; }

template <typename T>
void BinaryNode<T>::setRightChildPtr(BinaryNode<T>* newRightChildPtr){ rightChildPtr = newRightChildPtr; }

template <typename T>
 T BinaryNode<T>::getItem() const{ return item; }

template <typename T>
BinaryNode<T>* BinaryNode<T>::getLeftChildPtr() const{ return leftChildPtr; }

template <typename T>
BinaryNode<T>* BinaryNode<T>::getRightChildPtr() const{ return rightChildPtr; }

template <typename T>
bool BinaryNode<T>::isLeaf() const{ 
    return (leftChildPtr == nullptr && rightChildPtr == nullptr);
}