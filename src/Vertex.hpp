#pragma once

#include <list>
#include "Edge.hpp"

// Vertex of weighted graph

template<typename T_edge, typename T_vertex>
class Vertex
{
    private:
        unsigned int ID;
        bool visited;
        T_vertex value;   
        std::list<Edge<T_edge>> edgeList;        
                
    public:
        template<typename T_operatorEdge, typename T_operatorVertex>
        friend bool operator==(const Vertex<T_operatorEdge, T_operatorVertex>& lhs, const Vertex<T_operatorEdge, T_operatorVertex>& rhs);
        int getID() const;
        T_vertex getValue() const;
        void setValue(const T_vertex &given_value);
        std::list<Edge<T_edge>> &getEdgeList();
        void addToEdgeList(const Edge<T_edge> &edge);
        void removeFromEdgeList(const Edge<T_edge> &edge);
        Vertex(int initial_ID, const T_vertex &initial_value);
};

template<typename T_edge, typename T_vertex>
bool operator==(const Vertex<T_edge, T_vertex>& lhs, const Vertex<T_edge, T_vertex>& rhs)
{
    return(lhs.getID() == rhs.getID());
}

template<typename T_edge, typename T_vertex>
int Vertex<T_edge, T_vertex>::getID() const
{
    return ID;
}

template<typename T_edge, typename T_vertex>
T_vertex Vertex<T_edge, T_vertex>::getValue() const
{
    return value;
}

template<typename T_edge, typename T_vertex>
void Vertex<T_edge, T_vertex>::setValue(const T_vertex &given_value)
{
    value = given_value;
}

template<typename T_edge, typename T_vertex>
std::list<Edge<T_edge>> &Vertex<T_edge, T_vertex>::getEdgeList() 
{
    return edgeList;
}

template<typename T_edge, typename T_vertex>
void Vertex<T_edge, T_vertex>::addToEdgeList(const Edge<T_edge> &edge)
{
    edgeList.push_back(edge);
}

template<typename T_edge, typename T_vertex>
void Vertex<T_edge, T_vertex>::removeFromEdgeList(const Edge<T_edge> &edge)
{
    edgeList.remove(edge);
}

template<typename T_edge, typename T_vertex>
Vertex<T_edge, T_vertex>::Vertex(int initial_ID, const T_vertex &initial_value)
: ID(initial_ID), value(initial_value) {};