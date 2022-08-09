#pragma once

// Edge of weighted graph

template <typename T_edge>
class Edge 
{
    private:
        unsigned int sourceVertexID;
	    unsigned int destinationVertexID;
	    T_edge weight;
	    bool visited = false;

    public:
        friend bool operator==(const Edge<T_edge>& lhs, const Edge<T_edge>& rhs)   
        {
            return (lhs.destinationVertexID == rhs.destinationVertexID 
                    && lhs.weight == rhs.weight
                    && lhs.sourceVertexID == rhs.sourceVertexID);
        }

        void setWeight(const T_edge &value)
        {
            weight = value;
        }

        T_edge getWeight() const
        {
            return weight;
        }

        void setDestinationID(int dest_id) 
        {
            destinationVertexID = dest_id;
        }

        int getDestinationID() const
        {
            return destinationVertexID;
        }

        bool isVisited()
        {
            return visited;
        }

        void setVisitedTrue()
        {
            visited = true;
        }

        void setVisitedFalse()
        {
            visited = false;
        }

        Edge(int srcID, int destID, const T_edge &w) 
        {
            sourceVertexID = srcID;
            destinationVertexID = destID;
            weight = w;
        }

        ~Edge()
        {

        }
};