#pragma once 

//everything class needs to be 2D

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
        Coordinates coordinates;
    public:
        Coordinates getCoordinates();
        void setCoordinates(const int &targetX, const int &targetY);

};

Structure2D::Coordinates Structure2D::getCoordinates()
{
    return coordinates;
}

void Structure2D::setCoordinates(const int &targetX, const int &targetY)
{
    coordinates.x = targetX;
    coordinates.y = targetY;
}
