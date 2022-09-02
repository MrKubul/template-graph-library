#pragma once

#include "UnitVisitingOperations.hpp"

// Edge of weighted graph

template <typename T_edge>
class Edge 
{
    private:
        unsigned int sourceVertexID;
	    unsigned int destinationVertexID;
        T_edge weight;

    public:
        template <typename T_operator>
        friend bool operator==(const Edge<T_operator>& lhs, const Edge<T_operator>& rhs);
        UnitVisitingOperations visitedStatus;
        void setWeight(const T_edge &value);
        T_edge getWeight() const;
        void setDestinationID(int dest_id);
        int getDestinationID() const;
        Edge(int srcID, int destID, const T_edge &w);
};

template <typename T_edge>
bool operator==(const Edge<T_edge>& lhs, const Edge<T_edge>& rhs)   
{
    return (lhs.destinationVertexID == rhs.destinationVertexID 
            && lhs.weight == rhs.weight
            && lhs.sourceVertexID == rhs.sourceVertexID);
}

template <typename T_edge>
void Edge<T_edge>::setWeight(const T_edge &value)
{
    weight = value;
}

template <typename T_edge>
T_edge Edge<T_edge>::getWeight() const
{
    return weight;
}

template <typename T_edge>
void Edge<T_edge>::setDestinationID(int dest_id) 
{
    destinationVertexID = dest_id;
}

template <typename T_edge>
int Edge<T_edge>::getDestinationID() const
{
    return destinationVertexID;
}

template <typename T_edge>
Edge<T_edge>::Edge(int srcID, int destID, const T_edge &w)
: sourceVertexID(srcID), destinationVertexID(destID), weight(w) {}
