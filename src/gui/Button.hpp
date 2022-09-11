#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ActionType.hpp"


class Button {
    private:
        sf::RectangleShape buttonShape;
        sf::Text buttonText;
        ActionType buttonType;
    public:
        Button();
        Button(std::string initialText, sf::Vector2f initialSize, ActionType initialButtonType);
        ActionType getActionType() const;
        void setPosition(sf::Vector2f newPosition);
        void setBackColor(sf::Color &color);
        void setText(std::string message);
        void drawTo(sf::RenderWindow &window);
        bool isClicked(const sf::Mouse mouse, const float x, const float y) const;
};