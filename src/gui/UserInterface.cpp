#include "src/gui/UserInterface.hpp"
#include "src/gui/Button.hpp"
#include "src/gui/ActionType.hpp"
#include "src/graph2D_lib/directed_graph2D/Vertex2D.hpp"
#include <SFML/Graphics.hpp>

void UserInterface::setCurrentAction(ActionType actionType)
{
    currentAction = actionType;
}

void UserInterface::setUpGUI()
{
    //ADD BETTER NAMING FOR BUTTONS AND POSITIONS

    sf::Vector2f vec(40, 20);
    sf::Vector2f positionAddNode(1900, 20);
    sf::Vector2f positionDeleteNode(1900, 60);
    sf::Vector2f positionAddEdge(1900, 100);
    sf::Vector2f positionDeleteEdge(1900, 140);
    sf::Vector2f positionSaveGraph(1900, 180);
    sf::Vector2f positionBFS(1900, 220);
    sf::Vector2f positionDFS(1900, 260);
    sf::Vector2f positionDijsktra(1900, 300);
    sf::Vector2f positionMessages(1900, 340);


    Button b1 = Button("Create Node", vec, ActionType::AddNode);
    b1.setPosition(positionAddNode);
    Button b2 = Button("Delete Node", vec, ActionType::DeleteNode);
    b1.setPosition(positionDeleteNode);
    Button b3 = Button("Create Edge", vec, ActionType::AddEdge);
    b1.setPosition(positionAddEdge);
    Button b4 = Button("Delete Edge", vec, ActionType::DeleteEdge);
    b1.setPosition(positionDeleteEdge);
    Button b5 = Button("Save Graph", vec, ActionType::SaveGraph);
    b1.setPosition(positionSaveGraph);
    Button b6 = Button("Run BFS", vec, ActionType::BreadthSearch);
    b1.setPosition(positionBFS);
    Button b7 = Button("Run DFS", vec, ActionType::DepthSearch);
    b1.setPosition(positionDFS);
    Button b8 = Button("Run Dijkstra", vec, ActionType::ShortestPath);
    b1.setPosition(positionDijsktra);
    Button b9 = Button("User messages will be here", vec, ActionType::None);
    b1.setPosition(positionMessages);

    buttons.push_back(b1);
    buttons.push_back(b2);
    buttons.push_back(b3);
    buttons.push_back(b4);
    buttons.push_back(b5);
    buttons.push_back(b6);
    buttons.push_back(b7);
    buttons.push_back(b8);
    buttons.push_back(b9);
}

void UserInterface::drawCanvas(sf::RenderWindow &window)
{
    std::vector<GTL::Vertex2D<int, int>*> verticesWithDrawnEdges;
    for(auto vertex: (this->currentGraph).getVertices())
    {
        float nodeX = (vertex.getCoordinates())->x;
        float nodeY = (vertex.getCoordinates())->y;

        sf::CircleShape nodeShape(30, 30);
        nodeShape.setFillColor(sf::Color(255, 0, 0, 255));
        nodeShape.setPosition(nodeX, nodeY);
        sf::Text nodeVal(vertex.getValue());
        nodeVal.setColor(sf::Color(0, 125, 0, 255));
        nodeVal.setPosition(nodeX, nodeY);

        window.draw(nodeShape);
        window.draw(nodeVal);

        for(auto &edge: vertex.getEdgeList())
        {
            if (std::find(verticesWithDrawnEdges.begin(), verticesWithDrawnEdges.end(), edge) != verticesWithDrawnEdges.end()) 
            {
                continue;
            }
            else 
            {
                auto toVertex = currentGraph.getVertexByID(edge.getDestinationID);
                sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(*vertex.getCooinates())),
                    sf::Vertex(sf::Vector2f(*toVertex.getCoordinates()))
                };

                window.draw(line, 2, sf::Lines);
            }
        }
        verticesWithDrawnEdges.push_back(vertex);
    }
}

void UserInterface::updateMessage()
{
    switch(currentAction)
    {
        case ActionType::AddNode:
            buttons[8].setText("Click where to Add Node and type it's value");
            break;
        case ActionType::DeleteNode:
            buttons[8].setText("Click which Node to delete.");
            break;
        case ActionType::AddEdge:
            buttons[8].setText("Click two Nodes to connect them and type edge weight");
            break;
        case ActionType::DeleteEdge:
            buttons[8].setText("Click Nodes at the ends of Edge to delete it");
            break;
        case ActionType::SaveGraph:
            buttons[8].setText("Trying to save current Graph");
            break;
        case ActionType::DepthSearch:
            buttons[8].setText("Click starting Node and Taget Node");
            break;
        case ActionType::BreadthSearch:
            buttons[8].setText("Click starting Node and Taget Node");
            break;
        case ActionType::ShortestPath:
            buttons[8].setText("Click starting Node and Taget Node");
            break;
        case ActionType::None:
            buttons[8].setText("Choose one of the actions");
            break;        
    }
}

void UserInterface::displayGUI()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "GraphsGUI");
    window.clear(sf::Color(255, 255, 255, 255));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                for(auto &button: buttons)
                {
                    if(button.isClicked(window))
                    {
                        currentAction = button.getActionType();
                    }
                }

                for(auto &vertex: currentGraph.getVertices())
                {
                    switch(currentAction)
                    {
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
        updateMessage();
        drawCanvas(window);
        window.display();
    }
}
