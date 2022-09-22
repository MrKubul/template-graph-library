#include "Button.hpp"

Button::Button()
{

};

Button::Button(std::string initialText, sf::Vector2f initialSize, ActionType initialButtonType)
{
    buttonType = initialButtonType;
    buttonText.setString(initialText);
    buttonText.setColor(sf::Color(0, 0, 0, 255));
    buttonText.setCharacterSize(9);
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

    float xPos = (newPosition.x + buttonShape.getLocalBounds().width / 2) - (buttonText.getLocalBounds().width / 2);
    float yPos = (newPosition.y + buttonShape.getLocalBounds().height / 2) - (buttonText.getLocalBounds().height / 2);

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

bool Button::isClicked(sf::RenderWindow &window) const
{
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return false;
    }
    else
    {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float buttonX = buttonShape.getPosition().x;
        float buttonY = buttonShape.getPosition().y;
        float buttonXBound = buttonX + buttonShape.getLocalBounds().width;
        float buttonYBound = buttonY + buttonShape.getLocalBounds().height;

        if(mouseX > buttonX && mouseX < buttonXBound && mouseY > buttonY && mouseY < buttonYBound)
        {
            return true;
        }
        return false;
    }
}
