#include "Button.hpp"

Button::Button()
{

};

Button::Button(std::string initialText, sf::Vector2f initialSize, ActionType initialButtonType)
{
    buttonType = initialButtonType;
    buttonText.setString(initialText);
    buttonText.setColor(sf::Color(0, 0, 0, 255));
    buttonText.setCharacterSize(11);
    buttonShape.setSize(initialSize);
    buttonShape.setFillColor(sf::Color(211, 211, 211, 255));
};

ActionType Button::getActionType() const
{
    return buttonType;
}

void Button::setPosition(sf::Vector2f newPosition)
{
    buttonShape.setPosition(newPosition);

    float xPos = (newPosition.x + buttonShape.getGlobalBounds().width / 2) - (buttonText.getGlobalBounds().width / 2);
    float yPos = (newPosition.y + buttonShape.getGlobalBounds().height / 2) - (buttonText.getGlobalBounds().height / 2);

    buttonText.setPosition(xPos, yPos);
};

void Button::setBackColor(sf::Color &color)
{
    buttonShape.setFillColor(color);
};

void Button::setText(std::string message)
{
    buttonText.setString(message);
};

void Button::drawTo(sf::RenderWindow &window)
{
    window.draw(buttonShape);
    window.draw(buttonText);
}

bool Button::isClicked(const sf::Mouse mouse, const float x, const float y) const
{
    if(!mouse.isButtonPressed(sf::Mouse::Left))
    {
        return false;
    }
    else
    {
        if(x)
    }
}
