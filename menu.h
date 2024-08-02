#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu {
private:
    Sprite buttonSprite;
    Texture buttonTexture;
    Texture buttonPressedTexture;
    Sprite exitButtonSprite;
    Texture exitButtonTexture;
    Texture exitButtonPressedTexture;
    bool isButtonPressed;

public:
    Menu();
    void draw(RenderWindow& window);
    bool isPlayButtonPressed(RenderWindow& window);
    bool isExitButtonPressed(RenderWindow& window);
};
