#pragma once

#include "src/graph_lib/bst/BinarySearchTree.hpp"
#include "Node2D.hpp"

namespace GTL{

template<typename T_node>
class BinarySearchTree2D : public BinarySearchTree, public Structure2D
{
private:
    Node2D<T_node>* root = nullptr;
public:
    BinarySearchTree2D();
    ~BinarySearchTree2D();
};

template<typename T_node>
BinarySearchTree2D<T_node>::BinarySearchTree2D()
{
}

template<typename T_node>
BinarySearchTree2D<T_node>::~BinarySearchTree2D()
{
}
}
