#include "src/gui/UserInterface.hpp"

void UserInterface::setCurrentAction()
{

}

void UserInterface::setUpGUI()
{

}

void UserInterface::displayGUI()
{
    for(auto &btn: buttons)
    {
        if(btn.isClicked())
        {
            currentAction = btn.getActionType();
        }
    }

    switch(currentAction)
    {
        //display proper message an await action
        case ActionType::AddNode:
            break;
        case ActionType::DeleteNode:
            break;
        case ActionType::AddEdge:
            break;
        case ActionType::DeleteEdge:
            break;
        case ActionType::SaveGraph:
            break;
        case ActionType::DepthSearch:
            break;
        case ActionType::BreadthSearch:
            break;
        case ActionType::ShortestPath:
            break;
        case ActionType::None:
            break;           
    }
}
