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
    void addEdge(int fromID, int towardsID, const T_edge &weight);
    bool checkIfEdgeExists(int fromID, int towardsID);
    void addVertex(const Vertex<T_edge, T_vertex> &newVertex);
    bool checkIfVertexExists(int vertexID);
    T_edge getEdgeWeight(int fromID, int towardsID);
    Edge<T_edge>* getEdgeByID(int fromID, int towardsID);
    void updateEdgeByID(int fromID, int towardsID, const T_edge &newWeight);
    void eraseEdgeByID(int fromID, int towardsID);
    void deleteVertexByID(int deleteID);
    Vertex<T_edge, T_vertex>* getVertexByID(int ID);
    void updateVertex(int updateID, const T_vertex &value);
    std::vector<Vertex<T_edge, T_vertex>> getVertices();
    Graph();
    Graph(const std::vector<Vertex<T_edge, T_vertex>> &initial_vertices);
};

template<typename T_edge, typename T_vertex> 
void Graph<T_edge, T_vertex>::addEdge(int fromID, int towardsID, const T_edge &weight)
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

template<typename T_edge, typename T_vertex> 
bool Graph<T_edge, T_vertex>::checkIfEdgeExists(int fromID, int towardsID)
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

template<typename T_edge, typename T_vertex> 
void Graph<T_edge, T_vertex>::addVertex(const Vertex<T_edge, T_vertex> &newVertex)
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

template<typename T_edge, typename T_vertex> 
bool Graph<T_edge, T_vertex>::checkIfVertexExists(int vertexID)
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

template<typename T_edge, typename T_vertex> 
T_edge Graph<T_edge, T_vertex>::getEdgeWeight(int fromID, int towardsID)
{
    return getEdgeByID(fromID, towardsID)->getWeight();
}

template<typename T_edge, typename T_vertex> 
Edge<T_edge>* Graph<T_edge, T_vertex>::getEdgeByID(int fromID, int towardsID)
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

template<typename T_edge, typename T_vertex> 
void Graph<T_edge, T_vertex>::updateEdgeByID(int fromID, int towardsID, const T_edge &newWeight)
{
    getEdgeByID(fromID, towardsID)->setWeight(newWeight);
}

template<typename T_edge, typename T_vertex> 
void Graph<T_edge, T_vertex>::eraseEdgeByID(int fromID, int towardsID)
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

template<typename T_edge, typename T_vertex> 
void Graph<T_edge, T_vertex>::deleteVertexByID(int deleteID)
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

template<typename T_edge, typename T_vertex> 
Vertex<T_edge, T_vertex>* Graph<T_edge, T_vertex>::getVertexByID(int ID)
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

template<typename T_edge, typename T_vertex> 
void Graph<T_edge, T_vertex>::updateVertex(int updateID, const T_vertex &value)
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

template<typename T_edge, typename T_vertex> 
std::vector<Vertex<T_edge, T_vertex>> Graph<T_edge, T_vertex>::getVertices()
{
    return vertices;
}

template<typename T_edge, typename T_vertex> 
Graph<T_edge, T_vertex>::Graph()
{

}

template<typename T_edge, typename T_vertex> 
Graph<T_edge, T_vertex>::Graph(const std::vector<Vertex<T_edge, T_vertex>> &initial_vertices)
: vertices(initial_vertices) {};
