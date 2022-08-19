#pragma once

#include "./graph/BinarySearchTree.hpp"
#include "Node2D.hpp"

//TODO I GUESS WE HAVE TO OVERRIDE METHODS TO ACCEPT NEW TYPE OF Node :/

template<typename T_node>
class BinarySearchTree2D : public BinarySearchTree
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
