#pragma once

#include "src/graph_lib/directed_graph/Vertex.hpp"
#include "src/graph2D_lib/Structure2D.hpp"

namespace GTL{

template<typename T_edge, typename T_vertex> 
class Vertex2D : public Vertex, public Structure2D
{

};
}
