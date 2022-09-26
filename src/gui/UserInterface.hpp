#pragma once

#include "gui/ActionType.hpp"
#include "gui/Button.hpp"
#include "graph2D_lib/directed_graph2D/Graph2D.hpp"
#include "gui/UserInterface.hpp"
#include "graph2D_lib/directed_graph2D/Vertex2D.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class UserInterface{
    private:
        GTL::Graph2D<int, int> currentGraph;
        std::vector<Button> buttons;
        std::vector<GTL::Vertex2D<int, int>> selectedNodes;
        int nodeIDCounter = 0;
    public:
        static ActionType currentAction;
        UserInterface() = default;
        void setCurrentAction(ActionType actionType);
        void setUpGUI();
        void drawCanvas(sf::RenderWindow &window);
        void updateMessage();
        void doCurrentAction();
        void displayGUI();
};