#pragma once

#include <list>
#include "Edge.hpp"

// Vertex of weighted graph

template<typename T_edge, typename T_vertex>
class Vertex
{
    private:
        unsigned int ID;
        T_vertex value;   
        bool visited;
        std::list<Edge<T_edge>> edgeList;        
                
    public:
        friend bool operator==(const Vertex<T_edge, T_vertex>& lhs, const Vertex<T_edge, T_vertex>& rhs)
        {
            return(lhs.getID() == rhs.getID());
        }

        int getID() const
        {
            return ID;
        }

        T_vertex getValue()
        {
            return value;
        }

        void setValue(const T_vertex &given_value)
        {
            value = given_value;
        }

        std::list<Edge<T_edge>> &getEdgeList() 
        {
            return edgeList;
        }

        void addToEdgeList(const Edge<T_edge> &edge)
        {
            edgeList.push_back(edge);
        }

        void removeFromEdgeList(const Edge<T_edge> &edge)
        {
            edgeList.remove(edge);
        }

        Vertex()
        {

        }

        Vertex(int initial_ID, const T_vertex &initial_value)
        {
            ID = initial_ID;
            value = initial_value;
        }

        ~Vertex()
        {

        }
};