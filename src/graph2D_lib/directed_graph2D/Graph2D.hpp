#pragma once

#include "./graph/Graph.hpp"
#include "Vertex2D.hpp"

template<typename T_edge, typename T_vertex>   
class Graph2D : public Graph, public Structure2D
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


