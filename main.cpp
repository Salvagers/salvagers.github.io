#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "includes.h"
#include "player.h"
#include <fstream>
#include "enemy.h"
#include "menu.h"
#include <random>
#include <chrono>
using namespace sf;
using namespace std;

int main() {



    std::vector<Texture> buttonTextures(2);
    buttonTextures[0].loadFromFile("button.png");
    buttonTextures[1].loadFromFile("buttonpressed.png");

    std::vector<Texture> exitButtonTextures(2);
    exitButtonTextures[0].loadFromFile("exitbutton.png");
    exitButtonTextures[1].loadFromFile("exitbuttonpressed.png");

    sf::Texture backText;
    if (!backText.loadFromFile("backgroundpixelated.png")) {
        cout << "Error loading background texture" << endl;
        return -1;
    }
    sf::Sprite backgroundSprite(backText);
    std::vector<Texture> playerTextures(18);
    playerTextures[0].loadFromFile("0frame.png");
    playerTextures[1].loadFromFile("1frame.png");
    playerTextures[2].loadFromFile("2frame.png");
    playerTextures[3].loadFromFile("3frame.png");
    playerTextures[4].loadFromFile("4frame.png");
    playerTextures[5].loadFromFile("5frame.png");
    playerTextures[6].loadFromFile("6frame.png");
    playerTextures[7].loadFromFile("7frame.png");
    playerTextures[8].loadFromFile("8frame.png");
    for (int i = 0; i < 9; ++i) {
        std::string filename = std::to_string(i) + "frame.png";
        if (!playerTextures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }
    playerTextures[9].loadFromFile("left0.png");
    playerTextures[10].loadFromFile("left1.png");
    playerTextures[11].loadFromFile("left2.png");
    playerTextures[12].loadFromFile("left3.png");
    playerTextures[13].loadFromFile("left4.png");
    playerTextures[14].loadFromFile("left5.png");
    playerTextures[15].loadFromFile("left6.png");
    playerTextures[16].loadFromFile("left7.png");
    playerTextures[17].loadFromFile("left8.png");
    for (int i = 9; i < 18; ++i) {
        std::string filename = "left" + std::to_string(i - 9) + ".png";
        if (!playerTextures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }
    std::vector<Texture> enemy1Textures(8);
    enemy1Textures[0].loadFromFile("trashmonsterF1.png");
    enemy1Textures[1].loadFromFile("trashmonsterF2.png");
    enemy1Textures[2].loadFromFile("trashmonsterF3.png");
    enemy1Textures[3].loadFromFile("trashmonsterF4.png");
    enemy1Textures[4].loadFromFile("trashmonsterF5.png");
    enemy1Textures[5].loadFromFile("trashmonsterF6.png");
    enemy1Textures[6].loadFromFile("trashmonsterF7.png");
    enemy1Textures[7].loadFromFile("trashmonsterF8.png");
    for (int i = 0; i < 8; ++i) {
        std::string filename = "trashmonsterF" + std::to_string(i + 1) + ".png";
        if (!enemy1Textures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }

    std::vector<Texture> enemy2Textures(8);
    enemy2Textures[0].loadFromFile("barrelF1.png");
    enemy2Textures[1].loadFromFile("barrelF2.png");
    enemy2Textures[2].loadFromFile("barrelF3.png");
    enemy2Textures[3].loadFromFile("barrelF4.png");
    enemy2Textures[4].loadFromFile("barrelF5.png");
    enemy2Textures[5].loadFromFile("barrelF6.png");
    enemy2Textures[6].loadFromFile("barrelF7.png");
    enemy2Textures[7].loadFromFile("barrelF8.png");
    for (int i = 0; i < 8; ++i) {
        std::string filename = "barrelF" + std::to_string(i + 1) + ".png";
        if (!enemy2Textures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }

    std::vector<Texture> enemy3Textures(8);
    enemy3Textures[0].loadFromFile("oilF1.png");
    enemy3Textures[1].loadFromFile("oilF2.png");
    enemy3Textures[2].loadFromFile("oilF3.png");
    enemy3Textures[3].loadFromFile("oilF4.png");
    enemy3Textures[4].loadFromFile("oilF5.png");
    enemy3Textures[5].loadFromFile("oilF6.png");
    enemy3Textures[6].loadFromFile("oilF7.png");
    enemy3Textures[7].loadFromFile("oilF8.png");
    for (int i = 0; i < 8; ++i) {
        std::string filename = "oilF" + std::to_string(i + 1) + ".png";
        if (!enemy3Textures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }

    std::vector<Texture> enemy4Textures(8);
    enemy4Textures[0].loadFromFile("bottleF1.png");
    enemy4Textures[1].loadFromFile("bottleF2.png");
    enemy4Textures[2].loadFromFile("bottleF3.png");
    enemy4Textures[3].loadFromFile("bottleF4.png");
    enemy4Textures[4].loadFromFile("bottleF5.png");
    enemy4Textures[5].loadFromFile("bottleF6.png");
    enemy4Textures[6].loadFromFile("bottleF7.png");
    enemy4Textures[7].loadFromFile("bottleF8.png");
    for (int i = 0; i < 8; ++i) {
        std::string filename = "bottleF" + std::to_string(i + 1) + ".png";
        if (!enemy4Textures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }

    Sprite enemysprite1, enemysprite2, enemysprite3, enemysprite4, playButtonSprite, exitButtonSprite, broomsprite;
    enemysprite1.setTexture(enemy1Textures[0]);
    enemysprite1.setPosition(500, 800);
    enemysprite1.setScale(0.25, 0.25f);;
    exitButtonSprite.setTexture(exitButtonTextures[0]);
    exitButtonSprite.setPosition(960, 540);
    exitButtonSprite.setScale(0.25f, 0.25f);
    playButtonSprite.setTexture(buttonTextures[0]);
    playButtonSprite.setPosition(960, 540);
    playButtonSprite.setScale(0.25f, 0.25f);

    Sprite playersprite;
    playersprite.setOrigin(64, 64);
    playersprite.setPosition(0, 800); // Start at the very left edge of the map
    playersprite.setTexture(playerTextures[0]);
    playersprite.setScale(0.25f, 0.25f); // Make the player smaller
    float playerSpeed = 0.25f;
    RenderWindow window(VideoMode(1920, 1080), "Salvagers");
    Event event;
    Font font;
    if (!font.loadFromFile("PixelifySans-Regular.ttf")) {
        cout << "Error loading font" << endl;
        return -1;
    }

    Text dialogueText("", font, 30);
    dialogueText.setFillColor(Color::White);
    dialogueText.setPosition(100, 200);

    Text controlsText("PRESS A TO MOVE LEFT.\nPRESS D TO MOVE RIGHT.", font, 20);
    controlsText.setFillColor(Color::White);
    controlsText.setPosition(120, 510);

    
    RectangleShape dialogueBox2(Vector2f(500, 100));
    dialogueBox2.setFillColor(Color(0, 0, 0, 150));
    dialogueBox2.setPosition(10,500);
    controlsText.setPosition(
        dialogueBox2.getPosition().x + 10,  // 10 pixels padding from the left
        dialogueBox2.getPosition().y + 10   // 10 pixels padding from the top
    );

    RectangleShape dialogueBox(Vector2f(1600, 50));
    dialogueBox.setFillColor(Color(0, 0, 0, 150));
    dialogueBox.setPosition(100, 200);

    string playername;
    Text inputText("WHAT IS YOUR NAME?\n", font, 30);
    inputText.setFillColor(Color::White);
    inputText.setPosition(100, 100);
    bool enteringName = true;
    bool nameEntered = false;
    bool dialogueMode = false;
    vector<string> dialogues = { "Your task is to save the world." };
    size_t currentDialogue = 0;
    float inputFadeDuration = 1.0f;
    float fadeTimer = 0.0f;

    fstream firstsave;

    bool moveup = false;
    bool movedown = false;
    bool moveright = false;
    bool moveleft = false;
    bool canMove = false;
    bool canAnimate = false;

    random_device r;
    Weapon broom("MELEE", r() % 30 + 1);
    Weapon mop("MELEE", r() % 40 + 8);
    Weapon trashclaw("MELEE", r() % 50 + 10);
    Weapon vacuum("RANGED", r() % 60 + 10);
    Weapon cleaningspray("RANGED", r() % 70 + 20);
    Weapon powerwasher("RANGED", r() % 100 + 50);

    enemy trashmonster("Trash Monster", 200, 2, &vacuum, 1, 2, enemysprite1, enemy1Textures);
    enemy hazardouswaste("Hazardous Waste", 700, 7, &trashclaw, 10, 3, enemysprite2, enemy2Textures);
    enemy oilspill("Oil Spill", 1000, 10, &cleaningspray, 30, 2, enemysprite3, enemy3Textures);
    enemy microplastics("Microplastics", 500, 5, &broom, 20, 1, enemysprite4, enemy4Textures);

    InventoryExtendingItem trashbag("Trash Bag", 3);
    HpRestoreItem soap("Soap", 10);
    HpRestoreItem sanitizer("Hand Sanitizer", 20);
    HpRestoreItem bleach("Bleach", 40);

    player PLAYER(playername, 1000, 10, &broom, 1, 1, playersprite, playerTextures);

    Clock walkingtimer;
    Clock inputFadeTimer;
    float fadeOutDuration = 3.0f; // Duration of fade-out in seconds
    float fadeOutStartTime = 0.0f;
    bool startFadeOut = false;
    Clock animationClock;
    Clock buttonAnimationClock;
    float animationDuration = 0.1f; // Duration of each frame in seconds
    int currentFrame = 0;
    bool facingLeft = false;
    float thetimeiswalking = 0;
    float idleAnimationDuration = 0.1f; // Duration of each frame in seconds for idle animation
    int idleFrame = 0;
    sf::Keyboard::Key::Menu;
    Menu menu;
    bool isMenuOpen = true; // Set to true initially to show the play button first
    bool gameStarted = false; // Track if the game has started
    bool exitButtonPressed = false; // Track if the exit button is being pressed

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (isMenuOpen) {
                if (gameStarted) {
                    // Check if the exit button is hovered over or pressed
                    if (menu.isExitButtonPressed(window)) {
                        exitButtonSprite.setScale(0.3f, 0.3f); // Scale up when pressed
                        exitButtonPressed = true;
                    }
                    else {
                        exitButtonSprite.setScale(0.25f, 0.25f); // Default scale
                        exitButtonPressed = false;
                    }

                    // Check if mouse button is released after pressing the exit button
                    if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left && exitButtonPressed) {
                        window.close(); // Exit the game if EXIT is pressed
                    }

                }
                else {
                    if (menu.isPlayButtonPressed(window)) {
                        isMenuOpen = false;
                        gameStarted = true;
                        // Initialize your game here
                    }
                }
            }
            if (enteringName) {
                if (event.type == Event::TextEntered) {
                    if (event.text.unicode == '\b') {  // Handle backspace
                        if (!playername.empty()) {
                            playername.pop_back();
                        }
                    }
                    else if (event.text.unicode == '\r') {  // Handle enter key
                        enteringName = false;
                        nameEntered = true;
                        firstsave.open("firstsavefile", ios::in | ios::out | ios::trunc);
                        firstsave << playername;
                        firstsave.close();
                        std::cout << "DATA HAS BEEN SAVED" << endl;
                        dialogueMode = true;
                        dialogueText.setString(dialogues[0]);
                        inputFadeTimer.restart();
                        inputText.setString("");
                    }
                    else if (event.text.unicode < 128) {  // Handle regular character input
                        playername += static_cast<char>(event.text.unicode);
                    }
                    else if (nameEntered && !startFadeOut) {
                        startFadeOut = true;
                        fadeOutStartTime = inputFadeTimer.getElapsedTime().asSeconds(); // Start the fade timer
                    }
                    else if (startFadeOut) {
                        float elapsedTime = inputFadeTimer.getElapsedTime().asSeconds() - fadeOutStartTime;
                        float alpha = 255 * (1 - (elapsedTime / fadeOutDuration));

                        if (alpha < 0) alpha = 0; // Ensure alpha doesn't go below 0

                        sf::Color fadedColor = inputText.getFillColor();
                        fadedColor.a = static_cast<sf::Uint8>(alpha);
                        inputText.setFillColor(fadedColor);
                    }

                    // Update the inputText with the prompt and the current name
                    inputText.setString("WHAT IS YOUR NAME?\n" + playername);
                }
            }
            else {
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::A) {
                        moveleft = true;
                        facingLeft = true;
                    }
                    if (event.key.code == Keyboard::D) {
                        moveright = true;
                        facingLeft = false;
                    }
                }
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::M) {
                        isMenuOpen = !isMenuOpen; // Toggle menu open state
                    }
                }
                if (event.type == Event::KeyReleased) {
                    if (event.key.code == Keyboard::A) {
                        moveleft = false;
                    }
                    if (event.key.code == Keyboard::D) {
                        moveright = false;
                    }
                }
            }
        }

        // Update the animation frame
        if (animationClock.getElapsedTime().asSeconds() > animationDuration) {
            animationClock.restart();
            if (moveleft || moveright) {
                currentFrame = (currentFrame + 1) % 9; // Assuming 9 frames for walking animation
            }
            else {
                currentFrame = 0; // Idle frame
            }

            if (facingLeft) {
                playersprite.setTexture(playerTextures[9 + currentFrame]); // Left-facing textures
            }
            else {
                playersprite.setTexture(playerTextures[currentFrame]); // Right-facing textures
            }
        }
        if (animationClock.getElapsedTime().asSeconds() > idleAnimationDuration) {
            animationClock.restart();
            idleFrame = (currentFrame + 1 % 8);
            enemysprite1.setTexture(enemy1Textures[currentFrame]);
        }

        // Move player sprite based on flags
        if (moveleft) playersprite.move(-playerSpeed, 0);
        if (moveright) playersprite.move(playerSpeed, 0);

        window.clear();
        if (isMenuOpen) {
            if (gameStarted) {
                window.draw(exitButtonSprite); // Draw EXIT button
            }
            else {
                window.draw(playButtonSprite); // Draw PLAY button
            }
        }
        else {
            window.draw(backgroundSprite);
            window.draw(playersprite);
            window.draw(enemysprite1);
            window.draw(dialogueBox2);
            window.draw(controlsText);
            if (dialogueMode) {
                window.draw(dialogueBox);
                window.draw(dialogueText);
            }
            window.draw(inputText); // Always draw the input text
        }
        window.display();
    }
};