#include "Node.hpp" 

// weighted Binary search tree

namespace GTL {

template<typename T_node>
class BinarySearchTree
{
    private:
        Node<T_node>* root = nullptr;
        int treeSize = 0;
        Node<T_node>* successor(Node<T_node>* x);
        Node<T_node>* minimumOfSubtree(Node<T_node>* x);
    public:
    ~BinarySearchTree();
    BinarySearchTree() = default;
    Node<T_node>* getRoot() const;
    int getSize() const;
    void setRoot(Node<T_node>* newRoot);
    Node<T_node>* search(T_node valueToSearchFor) const;
    Node<T_node>* search(Node<T_node> *startingNode, T_node valueToSearchFor) const;
    void insert(const T_node& valueToInsert);
    void remove(T_node valueToRemove);
    void remove(Node<T_node>* rootNode, T_node valueToRemove);
    bool deleteSubtree();
    bool deleteSubtree(Node<T_node> *node);
};

template<typename T_node>
Node<T_node>* BinarySearchTree<T_node>::getRoot() const
{
    return root;
}

template<typename T_node>
int BinarySearchTree<T_node>::getSize() const
{
    return treeSize;
}

template<typename T_node>
void BinarySearchTree<T_node>::setRoot(Node<T_node>* newRoot)
{
    root = newRoot;
}

template<typename T_node>
Node<T_node>* BinarySearchTree<T_node>::search(T_node valueToSearchFor) const
{
    return search(root, valueToSearchFor);
}

template<typename T_node>
Node<T_node>* BinarySearchTree<T_node>::search(Node<T_node> *startingNode, T_node valueToSearchFor) const
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
    ++treeSize;
    Node<T_node>* newNode = new Node<T_node>(valueToInsert, treeSize);

    if(root == nullptr) 
    {
        this->setRoot(newNode);
        return;
    }

    Node<T_node>* tmp = nullptr;
    Node<T_node>* travelRoot = root; 

    while(travelRoot)
    {
        tmp = travelRoot;
        if(valueToInsert < travelRoot->getValue()) 
        {
            travelRoot = travelRoot->left;
        }
        else travelRoot = travelRoot->right;
    }

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
    if(rootNode == NULL)
    {
        return;
    }

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
    {
        x = y->left;
    }
    else
    {
        x = y->right;
    }
    if(x != nullptr)
    {
        x->parent = y->parent;
    }
    if(y->parent == nullptr)
    {
        root = x;
    }
    else if(y == y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }
    if(y != targetNode)
    {
        targetNode->setValue(y->getValue());
    }
    delete y;
    treeSize--;
}

template<typename T_node>
bool BinarySearchTree<T_node>::deleteSubtree()
{
    return deleteSubtree(root);
}

template<typename T_node>
bool BinarySearchTree<T_node>::deleteSubtree(Node<T_node> *node)
{
    if(node != NULL) {
        if(node->left) deleteSubtree(node->left);
        if(node->right) deleteSubtree(node->right);
        delete node;
        treeSize--;
    }
    return true;
}

template<typename T_node>
BinarySearchTree<T_node>::~BinarySearchTree()
{   
    if(treeSize > 0)
    {
        deleteSubtree();
    } 
}

}
