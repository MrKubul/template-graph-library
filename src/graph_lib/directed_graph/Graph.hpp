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

namespace GTL {

template<typename T_edge, typename T_vertex>    
class Graph
{
    private:
    std::vector<Vertex<T_edge, T_vertex>> vertices;

    public:
    Graph(const std::vector<Vertex<T_edge, T_vertex>> &initial_vertices);
    Graph() = default;

    void addBidirectionalEdge(unsigned int firstVertexID, unsigned int secondVertexID, const T_edge &weight);
    void addEdge(unsigned int fromID, unsigned int towardsID, const T_edge &weight);
    bool checkIfEdgeExists(unsigned int fromID, unsigned int towardsID);
    void addVertex(const Vertex<T_edge, T_vertex> &newVertex);
    bool checkIfVertexExists(unsigned int vertexID);
    T_edge getEdgeWeight(unsigned int fromID, unsigned int towardsID);
    Edge<T_edge>* getEdgeByID(unsigned int fromID, unsigned int towardsID);
    void updateEdgeByID(unsigned int fromID, unsigned int towardsID, const T_edge &newWeight);
    void eraseEdgeByID(unsigned int fromID, unsigned int towardsID);
    void deleteVertexByID(unsigned int deleteID);
    Vertex<T_edge, T_vertex>* getVertexByID(unsigned int ID);
    void updateVertex(unsigned int updateID, const T_vertex &value);
    void resetVisited();

    Vertex<T_edge, T_vertex>* depthFirstSearch(Vertex<T_edge, T_vertex>* startVertex, const T_vertex &value);
    Vertex<T_edge, T_vertex>* breadthFirstSearch(Vertex<T_edge, T_vertex>* startVertexconst , const T_vertex &value);
    T_edge getShortestPath(Vertex<T_edge, T_vertex>* const startVertex, Vertex<T_edge, T_vertex>* const target); 
    std::vector<T_edge> calculateDijsktraPaths(Vertex<T_edge, T_vertex>* const startVertex);
    int getVertexIndex(Vertex<T_edge, T_vertex>* const vertexPtr);
    std::vector<Vertex<T_edge, T_vertex>> getVertices() const;
};

template<typename T_edge, typename T_vertex> 
Graph<T_edge, T_vertex>::Graph(const std::vector<Vertex<T_edge, T_vertex>> &initial_vertices)
: vertices(initial_vertices) {}

template<typename T_edge, typename T_vertex> 
void Graph<T_edge, T_vertex>::addBidirectionalEdge(unsigned int firstVertexID, unsigned int secondVertexID, const T_edge &weight)
{
    addEdge(firstVertexID, secondVertexID,  weight);
    addEdge(secondVertexID, firstVertexID,  weight);
}

template<typename T_edge, typename T_vertex> 
void Graph<T_edge, T_vertex>::addEdge(unsigned int fromID, unsigned int towardsID, const T_edge &weight)
{
    if (checkIfVertexExists(fromID) && checkIfVertexExists(towardsID))
    {
        if(checkIfEdgeExists(fromID, towardsID))
        {
            return;
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
bool Graph<T_edge, T_vertex>::checkIfEdgeExists(unsigned int fromID, unsigned int towardsID) 
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
bool Graph<T_edge, T_vertex>::checkIfVertexExists(unsigned int vertexID)
{
    for(const auto& vertex: vertices)
    {
        if(vertex.getID() == vertexID)
        {
            return true;
        }
    }   
    return false;
}

template<typename T_edge, typename T_vertex> 
T_edge Graph<T_edge, T_vertex>::getEdgeWeight(unsigned int fromID, unsigned int towardsID) 
{
    return getEdgeByID(fromID, towardsID)->getWeight();
}

template<typename T_edge, typename T_vertex> 
Edge<T_edge>* Graph<T_edge, T_vertex>::getEdgeByID(unsigned int fromID, unsigned int towardsID)
{
    if(!checkIfEdgeExists(fromID, towardsID))
    {
        throw std::invalid_argument("Edge doesn't exist");
    }
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
    return nullptr;
}

template<typename T_edge, typename T_vertex> 
void Graph<T_edge, T_vertex>::updateEdgeByID(unsigned int fromID, unsigned int towardsID, const T_edge &newWeight)
{
    getEdgeByID(fromID, towardsID)->setWeight(newWeight);
}

template<typename T_edge, typename T_vertex> 
void Graph<T_edge, T_vertex>::eraseEdgeByID(unsigned int fromID, unsigned int towardsID)
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
void Graph<T_edge, T_vertex>::deleteVertexByID(unsigned int deleteID)
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
Vertex<T_edge, T_vertex>* Graph<T_edge, T_vertex>::getVertexByID(unsigned int ID)
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
void Graph<T_edge, T_vertex>::updateVertex(unsigned int updateID, const T_vertex &value)
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
        std::cout<<"checking node: "<<currentVertex->getID()<<std::endl;

        currentVertex->visitedStatus.setTrue();
        for(auto &edge: currentVertex->getEdgeList())
        {
            Vertex<T_edge, T_vertex>* nextVertex = getVertexByID(edge.getDestinationID());
            if(nextVertex->visitedStatus.get())
            {
                continue;
            }

            verticesWithVisitedParent.insert(nextVertex);
            std::cout<<"neighbour: "<<nextVertex->getID()<<std::endl;

            const T_edge oldDistance = currentDistances[getVertexIndex(nextVertex)];
            const T_edge altDistance = currentDistances[getVertexIndex(currentVertex)] + edge.getWeight();
                  
            if(oldDistance > altDistance)
            {
                currentDistances[getVertexIndex(nextVertex)] = altDistance;
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
            T_edge distToCheck = currentDistances.at(getVertexIndex(neighbour));
 
            if(distToCheck < minDist)
            {
                minDist = distToCheck;
                nextCurrentVertex = neighbour;
            }
        }
        currentVertex = nextCurrentVertex;
    }
    std::cout<<std::endl;
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
std::vector<Vertex<T_edge, T_vertex>> Graph<T_edge, T_vertex>::getVertices() const
{
    return vertices;
}

}