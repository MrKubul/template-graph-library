#pragma once

#include "./graph/Graph.hpp"
#include "Vertex2D.hpp"

//Check if all methods work properly with 2D type

template<typename T_edge, typename T_vertex>   
class Graph2D : public Graph
{
private:
    std::vector<Vertex2D<T_edge, T_vertex>> vertices;
public:
    Graph2D();
    ~Graph2D();
};

template<typename T_edge, typename T_vertex>   
Graph2D<T_edge, T_vertex>::Graph2D()
{
}

template<typename T_edge, typename T_vertex>   
Graph2D<T_edge, T_vertex>::~Graph2D()
{
}


