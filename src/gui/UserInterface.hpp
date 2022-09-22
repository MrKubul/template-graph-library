#pragma once

#include "src/gui/ActionType.hpp"
#include "src/gui/Button.hpp"
#include "src/graph2D_lib/directed_graph2D/Graph2D.hpp"

class UserInterface{
    private:
        GTL::Graph2D<int, int> currentGraph;
        std::vector<Button> buttons;
        std::vector<GTL::Graph<int, int>> selectedNodes;
    public:
        static ActionType currentAction;
        void setCurrentAction(ActionType actionType);
        void setUpGUI();
        void drawCanvas(sf::RenderWindow &window);
        void updateMessage();
        void displayGUI();
};