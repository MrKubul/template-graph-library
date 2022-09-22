#include <SFML/Graphics.hpp>

#include "src/gui/UserInterface.hpp"

int main()
{
    UserInterface interface = UserInterface();
    interface.setUpGUI();
    interface.displayGUI();
    return 0;
}