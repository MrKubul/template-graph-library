#pragma once

#include "./graph/BinarySearchTree.hpp"
#include "Node2D.hpp"


template<typename T_node>
class BinarySearchTree2D : public BinarySearchTree, public Structure2D
{
private:
    Node2D<T_node>* root = nullptr;
public:
    BinarySearchTree2D(/* args */);
    ~BinarySearchTree2D();
};

template<typename T_node>
BinarySearchTree2D<T_node>::BinarySearchTree2D(/* args */)
{
}

template<typename T_node>
BinarySearchTree2D<T_node>::~BinarySearchTree2D()
{
}
