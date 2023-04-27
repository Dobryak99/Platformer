#pragma once

#include <SFML/Graphics.hpp>
#include "RESOURCES.h"

using namespace sf;

class Button
{
private:
    Font buttonFont;                        // Text font
    Text buttonText;                        // Text
    Vector2f buttonPosition;                // Position on the screen
    int buttonSize;                         // Size of text
public:
    Button();                               // Constructor
    void setPosition(Vector2f position);    // Set position on the screen
    void setSize(int size);                 // Set size of text
    void setText(std::string text);         // Set Text
    void changeColorRed();                  // if mouse point at the button, change color
    void changeColorWhite();                // if mouse doesn't point at the button, change color
    Text getText();                         // get string of Text to draw
    FloatRect getPosition();                // get FloatRect of button to detect pointing
};
