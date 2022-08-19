#include "Node.hpp" 

// Binary search tree

template<typename T_node>
class BinarySearchTree
{
    private:
        Node<T_node>* root = nullptr;
        int treeSize = 0;
    public:
    Node<T_node>* getRoot();
    int getSize();
    void setRoot(Node<T_node>* newRoot);
    Node<T_node> * search(T_node valueToSearchFor);
    Node<T_node> * search(Node<T_node> *startingNode, T_node valueToSearchFor);
    void insert(const T_node& valueToInsert);
    Node<T_node>* successor(Node<T_node>* x);
    Node<T_node>* minimumOfSubtree(Node<T_node>* x);
    void remove(T_node valueToRemove);
    void remove(Node<T_node>* rootNode, T_node valueToRemove);
    void deleteTree();
    void deleteTree(Node<T_node> *node);
    ~BinarySearchTree();
};

template<typename T_node>
Node<T_node>* BinarySearchTree<T_node>::getRoot()
{
    return this->root;
}

template<typename T_node>
int BinarySearchTree<T_node>::getSize()
{
    return treeSize;
}

template<typename T_node>
void BinarySearchTree<T_node>::setRoot(Node<T_node>* newRoot)
{
    root = newRoot;
}

template<typename T_node>
Node<T_node> * BinarySearchTree<T_node>::search(T_node valueToSearchFor)
{
    return search(root, valueToSearchFor);
}

template<typename T_node>
Node<T_node> * BinarySearchTree<T_node>::search(Node<T_node> *startingNode, T_node valueToSearchFor)
{
    Node<T_node>* parent = startingNode;
    while(parent != nullptr)
    {
        if(valueToSearchFor == parent->getValue())
        {
            return parent;
        }
        if(valueToSearchFor < parent->getValue())
        {
            parent = parent->left;
        }
        else
        {
            parent = parent->right;
        }
    }
    return nullptr;
}

template<typename T_node>
void BinarySearchTree<T_node>::insert(const T_node& valueToInsert) 
{
    if(root == nullptr) 
    {
        treeSize++;
        Node<T_node>* newNode = new Node<T_node>(valueToInsert, treeSize);
        this->setRoot(newNode);
        return;
    }


    Node<T_node>* tmp = nullptr;
    Node<T_node>* travelRoot = root; 

    while(travelRoot)
    {
        tmp = travelRoot;
        if(valueToInsert < travelRoot->getValue()) travelRoot = travelRoot->left;
        else travelRoot = travelRoot->right;
    }


    treeSize++;
    Node<T_node>* newNode = new Node<T_node>(valueToInsert, treeSize);
    newNode->parent = tmp;


    if(valueToInsert >= tmp->getValue())
    {
        tmp->right = newNode;
    }
    else tmp->left = newNode;
}

template<typename T_node>
Node<T_node>* BinarySearchTree<T_node>::successor(Node<T_node>* x)
{
    if(x->right != nullptr)
    {
        return minimumOfSubtree(x->right);
    }
    Node<T_node>* y = x->parent;
    while(y != nullptr && x->right == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

template<typename T_node>
Node<T_node>* BinarySearchTree<T_node>::minimumOfSubtree(Node<T_node>* x)
{
    while(x->left != nullptr)
    {
        x = x->left;
    }
    return x;
}

template<typename T_node>
void BinarySearchTree<T_node>::remove(T_node valueToRemove) 
{
    remove(root, valueToRemove);
}

template<typename T_node>
void BinarySearchTree<T_node>::remove(Node<T_node>* rootNode, T_node valueToRemove) 
{
    if(rootNode == NULL) return;

    Node<T_node>* targetNode = search(valueToRemove);
    Node<T_node>* x = targetNode;
    Node<T_node>* y = NULL;

    if(targetNode->left == NULL || targetNode->right == NULL)
    {
        y = targetNode;
    }
    else
    {
        y = successor(targetNode);
    }
    if(y->left != nullptr)
        x = y->left;
    else
        x = y->right;
    if(x != nullptr)
        x->parent = y->parent;
    if(y->parent == nullptr)
        root = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    if(y != targetNode)
        targetNode->setValue(y->getValue());
    delete y;
}

template<typename T_node>
void BinarySearchTree<T_node>::deleteTree()
{
    deleteTree(root);
}

template<typename T_node>
void BinarySearchTree<T_node>::deleteTree(Node<T_node> *node)
{
    if(node == root)
    {
        treeSize = 0;
    }

    if(node != NULL) {
        if(node->left) deleteTree(node->left);
        if(node->right) deleteTree(node->right);
        delete node;
    }
}

template<typename T_node>
BinarySearchTree<T_node>::~BinarySearchTree()
{   
    if(treeSize > 0) deleteTree();
}
