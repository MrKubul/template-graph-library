#pragma once

#include "src/graph_lib/bst/Node.hpp"
#include "Structure2D.hpp"

namespace GTL{

template<typename T_edge, typename T_vertex> 
class Node2D : public Node, public Structure2D
{

};
}