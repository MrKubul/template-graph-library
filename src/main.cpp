#include <SFML/Graphics.hpp>
#include "gui/UserInterface.hpp"

int main()
{
    UserInterface interface = UserInterface();
    interface.setUpGUI();
    interface.displayGUI();
    return 0;
}