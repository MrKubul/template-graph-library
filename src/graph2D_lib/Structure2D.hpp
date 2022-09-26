#pragma once

namespace GTL{

class Structure2D
{
    private:
        struct Coordinates
            {
                float x;
                float y;

            Coordinates(float initialX, float initialY)
            {       
                x = initialX;
                y = initialY;
            }
        };
        Coordinates* coordinates;
    public:
        Structure2D(const float initialX, const float initalY);
        ~Structure2D();
        Coordinates getCoordinates() const;
        void setCoordinates(const float targetX, const float targetY);

};

Structure2D::Structure2D(const float initialX, const float initialY)
{
    coordinates = new Coordinates(initialX, initialY);
}

Structure2D::~Structure2D()
{
    delete coordinates;
}

Structure2D::Coordinates Structure2D::getCoordinates() const
{
    return *coordinates;
}

void Structure2D::setCoordinates(const float targetX, const float targetY)
{
    coordinates->x = targetX;
    coordinates->y = targetY;
}
}

