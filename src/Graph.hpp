#pragma once

#include <vector>
#include "Vertex.hpp"

// Bidirected weighted graph

template<typename T_edge, typename T_vertex>    
class Graph
{
    private:
    std::vector<Vertex<T_edge, T_vertex>> vertices;

    public:
    bool checkIfVertexExists(int vertexID)
    {
        bool vertexFound = false;
        for(const auto& vertex: vertices)
        {
            if(vertex.getID() == vertexID)
            {
                vertexFound = true;
            }
        }   
        return vertexFound;
    }

    void addVertex(const Vertex<T_edge, T_vertex> &newVertex)
    {
        if(checkIfVertexExists(newVertex.getID()))
        {
            throw std::invalid_argument( "Vertex already is already in the graph" );
        }
        else
        {
            vertices.push_back(newVertex);
        }
    }

    Vertex<T_edge, T_vertex>* getVertexByID(int ID)
    {
        for(auto &vertex: vertices)
        {
            if(vertex.getID() == ID)
            {
                return &vertex;
            }
        }
        throw std::invalid_argument( "Vertex not found" );
    }

    bool checkIfEdgeExists(int fromID, int towardsID)
    {
        for(auto &vertex: vertices)
        {
            if(vertex.getID() == fromID)
            {
                for(auto &edge: vertex.getEdgeList())
                {
                    if(edge.getDestinationID() == towardsID)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void addEdge(int fromID, int towardsID, const T_edge &weight)
    {
        if (checkIfVertexExists(fromID) && checkIfVertexExists(towardsID))
        {
            if(checkIfEdgeExists(fromID, towardsID))
            {
                throw std::invalid_argument( "Edge already exist" );
            }
            else 
            {
                Vertex<T_edge, T_vertex>* vertex = getVertexByID(fromID);
                Edge<T_edge> e = Edge<T_edge>(fromID, towardsID, weight);
                vertex->addToEdgeList(e);
            }
        }
        else
        {
            throw std::invalid_argument( "One of the vertices doesn't exist" );
        }
    }

    Edge<T_edge>* getEdgeByID(int fromID, int towardsID)
    {
        if(checkIfEdgeExists(fromID, towardsID))
        {
            for(auto &vertex: vertices)
            {
                if(vertex.getID() == fromID)
                {
                    for(auto &edge: vertex.getEdgeList())
                    {
                        if(edge.getDestinationID() == towardsID)
                        {
                            return &edge;
                        }
                    }
                }
            }
        }
        else throw std::invalid_argument( "Edge doesn't exist" );
        return NULL;
    }

    T_edge getEdgeWeight(int fromID, int towardsID)
    {
        return getEdgeByID(fromID, towardsID)->getWeight();
    }

    void eraseEdgeByID(int fromID, int towardsID)
    {
        for(auto &vertex: vertices)
            {
                if(vertex.getID() == fromID)
                {
                    vertex.removeFromEdgeList(*getEdgeByID(fromID, towardsID));
                    return;
                }
            }
        throw std::invalid_argument( "Edge doesn't exist" );
    }

    void updateEdgeByID(int fromID, int towardsID, const T_edge &newWeight)
    {
        getEdgeByID(fromID, towardsID)->setWeight(newWeight);
    }

    void deleteVertexByID(int deleteID)
    {
        Vertex<T_edge, T_vertex>* vertToDelete = getVertexByID(deleteID);
        (vertToDelete->getEdgeList()).clear();
        vertices.erase(std::remove(vertices.begin(), vertices.end(), (*vertToDelete)), vertices.end());

        for(auto& vertex: vertices)
        {   
            for(auto& edge: vertex.getEdgeList())
            {
                if(edge.getDestinationID() == deleteID)
                {
                    vertex.removeFromEdgeList(edge);
                }
            }
        }
    }

    void updateVertex(int updateID, const T_vertex &value)
    {
        bool checkVertex = checkIfVertexExists(updateID);
        if(checkVertex)
        {
            for(auto& vertex: vertices)
            {
                if(vertex.getID() == updateID)
                {
                    vertex.setValue(value);
                    break;
                }
            }
        }
        else
        {
            throw std::invalid_argument( "Vertex not found" );
        }
    }

    std::vector<Vertex<T_edge, T_vertex>> getVertices()
    {
        return vertices;
    }

    Graph()
    {

    }

    Graph(const std::vector<Vertex<T_edge, T_vertex>> &initial_vertices)
    : vertices(initial_vertices) {}

    ~Graph()
    {

    }
};
