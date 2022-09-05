#pragma once

#include <memory>

//everything class needs to have to be 2D

class Structure2D
{
    private:
        struct Coordinates
            {
                int x;
                int y;

            Coordinates(int initialX, int initialY)
            {       
                x = initialX;
                y = initialY;
            }
        };
        std::unique_ptr<Coordinates> coordinates;
    public:
        Structure2D(const int &initialX, const int &initalY);
        Coordinates getCoordinates() const;
        void setCoordinates(const int &targetX, const int &targetY);

};

Structure2D::Structure2D(const int &initialX, const int &initialY)
{
    coordinates = std::make_unique<Coordinates>(initialX, initialY);
}

Structure2D::Coordinates Structure2D::getCoordinates() const
{
    return *coordinates;
}

void Structure2D::setCoordinates(const int &targetX, const int &targetY)
{
    coordinates->x = targetX;
    coordinates->y = targetY;
}

