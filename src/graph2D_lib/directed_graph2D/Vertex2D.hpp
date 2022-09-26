#pragma once

#include <SFML/Graphics.hpp>
#include "graph_lib/directed_graph/Vertex.hpp"
#include "graph2D_lib/Structure2D.hpp"

namespace GTL{

template<typename T_edge, typename T_vertex> 
class Vertex2D : public Vertex<T_edge, T_vertex>, public Structure2D
{

};
}
