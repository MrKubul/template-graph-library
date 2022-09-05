#pragma once

namespace GTL {

class UnitVisitingOperations
{
    private:
        enum class VisitStatus{ Visited, Unvisited };
        VisitStatus visitStatus = VisitStatus::Unvisited;
    public:
        bool get() const;
        void setTrue();
        void setFalse();
};

inline bool UnitVisitingOperations::get() const
{
    return (visitStatus == VisitStatus::Visited);
}

inline void UnitVisitingOperations::setTrue()
{
    visitStatus = VisitStatus::Visited;
}

inline void UnitVisitingOperations::setFalse()
{
    visitStatus = VisitStatus::Unvisited;
}

}
