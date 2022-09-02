#pragma once

namespace GTL {

class UnitVisitingOperations
{
    private:
        enum class VisitStatus{ Visited, Unvisited };
        VisitStatus visitStatus = VisitStatus::Unvisited;
    public:
        bool get();
        void setTrue();
        void setFalse();
};

inline bool UnitVisitingOperations::get()
{
    return (this->visitStatus == VisitStatus::Visited ? true : false);
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
