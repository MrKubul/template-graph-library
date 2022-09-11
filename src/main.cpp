#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "src/gui/Button.hpp"
#include "src/gui/Canvas.hpp"
#include "ActionType.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "GraphsGUI");
    window.clear(sf::Color(255, 255, 255, 255));
    std::vector<Button> buttons;
    

    //Setting up Buttons: , move it to UserInterface.cpp setup then

    Button b1 = Button("Create Node", (40, 20), ActionType::AddNodeButton);
    b1.setPosition();
    Button b2 = Button("Delete Node", (40, 20), ActionType::DeleteNodeButton);
    b1.setPosition();
    Button b3 = Button("Create Node", (40, 20), ActionType::AddEdgeButton);
    b1.setPosition();
    Button b4 = Button("Create Node", (40, 20), ActionType::DeleteEdgeButton);
    b1.setPosition();
    Button b5 = Button("Create Node", (40, 20), ActionType::SaveGraphButton);
    b1.setPosition();
    Button b6 = Button("Create Node", (40, 20), ActionType::BreadthSearchButton);
    b1.setPosition();
    Button b7 = Button("Create Node", (40, 20), ActionType::DepthSearchButton);
    b1.setPosition();
    Button b8 = Button("Create Node", (40, 20), ActionType::ShortestPathButton);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                for(auto &button: buttons)
                {
                    if(button.isClicked())
                    {
                        button->onClick();
                    }
                }
            }
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        for(auto &button: buttons)
        {
            button.drawTo(window);
        }
        window.display();
    }
    return 0;
}