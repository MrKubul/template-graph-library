#pragma once

#include "src/gui/ActionType.hpp"
#include "src/gui/Button.hpp"

class UserInterface{
    private:
        std::vector<Button> buttons;

    public:
        static ActionType currentAction;
        void setCurrentAction();
        void setUpGUI();
        void displayGUI();
};