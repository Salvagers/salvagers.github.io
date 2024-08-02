//#pragma once
//#include "character.h"
//
//class enemy : public Character {
//public:
//    enemy(std::string charname, int healthpoints, int def, Weapon* bashbash, int level, int spd, sf::Sprite* enemysprite);
//};



#pragma once
#include "character.h"
#include <SFML/Graphics.hpp> // Include SFML Graphics

class enemy : public Character {
public:
    enemy(std::string charname, int healthpoints, int def, Weapon* bashbash, int level, int spd, sf::Sprite& enemysprite, std::vector<sf::Texture>& animations);
    sf::Sprite enemysprite1;
    sf::Sprite enemysprite2;
    sf::Sprite enemysprite3;
    sf::Sprite enemysprite4;
    void idleanimation();

    std::vector<sf::Texture> textures;

};
