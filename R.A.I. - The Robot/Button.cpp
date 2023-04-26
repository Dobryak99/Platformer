#include "Button.hpp"

Button::Button()
{
    buttonFont.loadFromFile(FONT);                              //Load font from file
    buttonText.setFont(buttonFont);                             //set Text with the Font
    buttonText.setFillColor(Color::White);                      //set text with white characters
}

void Button::changeColorRed()
{
    buttonText.setFillColor(Color::Red);                        //set color
}

void Button::changeColorWhite()
{
    buttonText.setFillColor(Color::White);                      //set new color
}

void Button::setPosition(Vector2f position)
{
    buttonPosition = position;                                  //safe position
    buttonText.setPosition(buttonPosition);                     //set position
}

void Button::setSize(int size)
{
    buttonText.setCharacterSize(size);                          //set Font size
}

void Button::setText(std::string text)
{
    buttonText.setString(text);                                 //set text
}

FloatRect Button::getPosition()
{
    return buttonText.getGlobalBounds();                        //get global bounds
}

Text Button::getText()
{
    return buttonText;                                          //get text
}
