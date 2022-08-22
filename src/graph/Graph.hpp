#pragma once

#include <vector> 
#include <queue>
#include <stack>
#include <limits>
#include <algorithm> 
#include <utility>

#include <unordered_set>
#include "Vertex.hpp"

// Directed weighted graph

template<typename T_edge, typename T_vertex>    
class Graph
{
    private:
    std::vector<Vertex<T_edge, T_vertex>> vertices;
    std::vector<int> algorithmVertexPath;

    public:
    void addBidirectionalEdge(int firstVertexID, int secondVertexID, const T_edge &weight);
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
    void resetVisited();

    Vertex<T_edge, T_vertex>* depthFirstSearch(Vertex<T_edge, T_vertex>* startVertex, const T_vertex &value);
    Vertex<T_edge, T_vertex>* breadthFirstSearch(Vertex<T_edge, T_vertex>* startVertexconst , const T_vertex &value);
    T_edge getShortestPath(Vertex<T_edge, T_vertex>* const startVertex, Vertex<T_edge, T_vertex>* const target); 
    std::vector<T_edge> calculateDijsktraPaths(Vertex<T_edge, T_vertex>* const startVertex);
    int getVertexIndex(Vertex<T_edge, T_vertex>* const vertexPtr);
    std::vector<Vertex<T_edge, T_vertex>> getVertices();

    Graph();
    Graph(const std::vector<Vertex<T_edge, T_vertex>> &initial_vertices);
};

template<typename T_edge, typename T_vertex> 
void Graph<T_edge, T_vertex>::addBidirectionalEdge(int firstVertexID, int secondVertexID, const T_edge &weight)
{
    addEdge(firstVertexID, secondVertexID,  weight);
    addEdge(secondVertexID, firstVertexID,  weight);
}

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
        auto iter = vertex.getEdgeList().begin();
        while(iter != vertex.getEdgeList().end())
        {
            if(iter->getDestinationID() == deleteID)
            {
                iter = vertex.getEdgeList().erase(iter++);
            }
            ++iter;
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
void Graph<T_edge, T_vertex>::resetVisited()
{
    for(auto &vertex: vertices)
    {
        vertex.visitedStatus.setFalse();
        for(auto &edge: vertex.getEdgeList())
        {
            edge.visitedStatus.setFalse();
        }
    }
}

template<typename T_edge, typename T_vertex> 
Vertex<T_edge, T_vertex>* Graph<T_edge, T_vertex>::depthFirstSearch(Vertex<T_edge, T_vertex>* startVertex, const T_vertex &valueToSearch)
{
    resetVisited();
    std::stack<Vertex<T_edge, T_vertex>*> to_visit;

    to_visit.push(startVertex);
    Vertex<T_edge, T_vertex>* currentVertex;

    while(!to_visit.empty())
    {
        currentVertex = to_visit.top();
        to_visit.pop();
        if(currentVertex->getValue() == valueToSearch)
        {
            return currentVertex;
        } 

        if(!(currentVertex->visitedStatus.get()))
        {
            currentVertex->visitedStatus.setTrue();
            for(auto &edge: currentVertex->getEdgeList())
            {
                if(Vertex<T_edge, T_vertex>* nextVertex = getVertexByID(edge.getDestinationID()); !(nextVertex->visitedStatus.get()))
                {
                    to_visit.push(nextVertex);
                }
            }
        }
    }
    return nullptr;
}

template<typename T_edge, typename T_vertex> 
Vertex<T_edge, T_vertex>* Graph<T_edge, T_vertex>::breadthFirstSearch(Vertex<T_edge, T_vertex>* startVertex, const T_vertex &valueToSearch)
{   
    resetVisited();
    std::queue<Vertex<T_edge, T_vertex>*> to_visit;

    to_visit.push(startVertex);
    Vertex<T_edge, T_vertex>* currentVertex;

    while (!to_visit.empty())
    {
        currentVertex = to_visit.front();
        to_visit.pop();

        if(currentVertex->getValue() == valueToSearch)
        {
            return currentVertex;
        }

        if(!(currentVertex->visitedStatus.get()))
        {
            currentVertex->visitedStatus.setTrue();
                for(auto &edge: currentVertex->getEdgeList())
                {
                    if(Vertex<T_edge, T_vertex>* nextVertex = getVertexByID(edge.getDestinationID()); !(nextVertex->visitedStatus.get()))
                    {
                        to_visit.push(nextVertex);
                    }
                }
        }
    }
    return nullptr;
}

template<typename T_edge, typename T_vertex> 
T_edge Graph<T_edge, T_vertex>::getShortestPath(Vertex<T_edge, T_vertex>* const startVertex, Vertex<T_edge, T_vertex>* const target)
{
    const T_edge INF= std::numeric_limits<T_edge>::max() / 2;
    const std::vector<T_edge> pathDistances = calculateDijsktraPaths(startVertex);

    T_edge result;
    int index = getVertexIndex(target);
    (pathDistances.at(index) >= INF / 2) ? result =  static_cast<T_edge>(-1) : result =  pathDistances.at(index);
    return result;
}

template<typename T_edge, typename T_vertex>  
std::vector<T_edge> Graph<T_edge, T_vertex>::calculateDijsktraPaths(Vertex<T_edge, T_vertex>* const startVertex)
{
    resetVisited();
    const T_edge INF = std::numeric_limits<T_edge>::max() / 2;
    std::vector<T_edge> currentDistances(vertices.size());
    std::fill(currentDistances.begin(), currentDistances.end(), INF);
    
    int index = getVertexIndex(startVertex);
    currentDistances.at(index) = static_cast<T_edge>(0);
    Vertex<T_edge, T_vertex>* currentVertex = startVertex;
    std::unordered_set<Vertex<T_edge, T_vertex>*> verticesWithVisitedParent;

    while(true)
    {   
        currentVertex->visitedStatus.setTrue();
        for(auto &edge: currentVertex->getEdgeList())
        {
            Vertex<T_edge, T_vertex>* nextVertex = getVertexByID(edge.getDestinationID());
            if(nextVertex->visitedStatus.get())
            {
                continue;
            }

            verticesWithVisitedParent.insert(nextVertex);
            T_edge oldDistance;
            T_edge newConnection;
            
            int n_index = 0;
            int t_index = 0;
            int index = 0;
            for(auto &vertex: vertices) 
            {
                if(&vertex == nextVertex)
                {
                    oldDistance = currentDistances.at(index);
                    t_index = n_index;

                }
                else n_index++;
                if(&vertex == currentVertex)
                {
                    newConnection = currentDistances.at(index);
                }
                ++index;
            }
            
            const T_edge altDistance = edge.getWeight() + newConnection;
            if(oldDistance > altDistance)
            {
                currentDistances[t_index] = altDistance;
            }
        }
        verticesWithVisitedParent.erase(currentVertex);
        if(verticesWithVisitedParent.empty())
        {
            break;
        }

        T_edge minDist = INF;
        Vertex<T_edge, T_vertex>* nextCurrentVertex;
 
        for (Vertex<T_edge, T_vertex>* neighbour: verticesWithVisitedParent) 
        {
            T_edge distToCheck;

            int index = getVertexIndex(startVertex);
            distToCheck = currentDistances.at(index);
 
            if(distToCheck < minDist)
            {
                minDist = distToCheck;
                nextCurrentVertex = neighbour;
            }
        }
        currentVertex = nextCurrentVertex;
    }
    return currentDistances;
}
template<typename T_edge, typename T_vertex> 
int Graph<T_edge, T_vertex>::getVertexIndex(Vertex<T_edge, T_vertex>* const vertexPtr)
{
    int index = 0;
    for(auto &vertex: vertices)       
    {
        if(&vertex == vertexPtr)
        {
            return index;
        }
        ++index;
    }
    throw std::invalid_argument("Vertex not found");
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
: vertices(initial_vertices) {}
