#pragma once

#include "src/graph_lib/directed_graph/Graph.hpp"
#include "Vertex2D.hpp"

namespace GTL {

template<typename T_edge, typename T_vertex>   
class Graph2D : public Graph
{
private:
    std::vector<Vertex2D<T_edge, T_vertex>> vertices;
public:

};
}
