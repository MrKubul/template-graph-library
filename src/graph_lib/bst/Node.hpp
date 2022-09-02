#pragma once

#include "graph_lib/UnitVisitingOperations.hpp"

// Node of Binary search tree

namespace GTL {

template<typename T_node>
class Node
{
    private:
        T_node value;
        int ID;
    public:
        Node<T_node> *left = nullptr, *right = nullptr, *parent = nullptr;
        UnitVisitingOperations visitedStatus;
        Node(const T_node &initialValue,  int initialID);
        T_node getValue() const;
        void setValue(const T_node &val);
};

template<typename T_node>
Node<T_node>::Node(const T_node &initialValue, int initialID)
{
    value = initialValue;
    ID = initialID;
}

template<typename T_node>
T_node Node<T_node>::getValue() const
{
    return value;
}

template<typename T_node>
void Node<T_node>::setValue(const T_node &val)
{
    value = val;
}

}
