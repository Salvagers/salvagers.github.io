//#pragma once
//#include "character.h"
//#include <string>
//#include "weapons.h"
//
//class enemy : public Character {
//public:
//    enemy(std::string charname, int healthpoints, int def, Weapon* bashbash, int level, int spd, sf::Sprite* enemysprite);
//};



#include "enemy.h"
#include <SFML/Graphics.hpp> // Include SFML Graphics

enemy::enemy(std::string charname, int healthpoints, int def, Weapon* bashbash, int level, int spd, sf::Sprite& enemysprite, std::vector<sf::Texture>& animations)
    : Character()
{
    name = charname;
    health = healthpoints;
    defense = def;
    entitybasher = bashbash;
    levels = level;
    speed = spd;
    sprite = enemysprite;
}

void enemy::idleanimation(){
    static int frame = 0;
    enemysprite1.setTexture(textures[0 + frame]);
    frame = (frame + 1) % 9;
}
