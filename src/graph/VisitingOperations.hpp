#pragma once

class VisitingOperations
{
    private:
        bool visited = false;
    public:
        bool isVisited();
        void setVisited();
        void setNotVisited();
};

bool VisitingOperations::isVisited()
{
    return visited;
}

void VisitingOperations::setVisited()
{
    visited = true;
}

void VisitingOperations::setNotVisited()
{
    visited = false;
}