#include "menu.h"
#include <iostream>

Menu::Menu() : isButtonPressed(false) {
    if (!buttonTexture.loadFromFile("button.png")) {
        std::cerr << "Failed to load button texture!" << std::endl;
    }
    if (!buttonPressedTexture.loadFromFile("buttonpressed.png")) {
        std::cerr << "Failed to load button pressed texture!" << std::endl;
    }
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(200, 200); // Position the button in the center
}

void Menu::draw(RenderWindow& window) {
    window.draw(buttonSprite);
}

bool Menu::isPlayButtonPressed(RenderWindow& window) {
    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousePos = Mouse::getPosition(window);
        FloatRect buttonBounds = buttonSprite.getGlobalBounds();

        if (buttonBounds.contains(static_cast<Vector2f>(mousePos))) {
            isButtonPressed = true;
            buttonSprite.setTexture(buttonPressedTexture);
        }
    }
    else {
        if (isButtonPressed) {
            isButtonPressed = false;
            buttonSprite.setTexture(buttonTexture);
            return true;
        }
    }
    return false;
}

bool Menu::isExitButtonPressed(RenderWindow& window) {
    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousePos = Mouse::getPosition(window);
        FloatRect buttonBounds = exitButtonSprite.getGlobalBounds();

        if (buttonBounds.contains(static_cast<Vector2f>(mousePos))) {
            isButtonPressed = true;
            exitButtonSprite.setTexture(exitButtonPressedTexture);
            
        }
    }
    else {
        if (isButtonPressed) {
            isButtonPressed = false;
            exitButtonSprite.setTexture(exitButtonTexture);
            return true;
        }
    }
    return false;
}