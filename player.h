#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "weapons.h"
#include "items.h"

class player {
public:
    player(const std::string& charname, int healthpoints, int def, Weapon* bashbash, int level, int spd, sf::Sprite& playersprite, std::vector<sf::Texture>& animations);

    void walkleftanimate();
    void walkrightanimate();
    void idleanimate();
    void takeDamage(int damage);
    void attack(player& target);
    void restoreHealth(int amount);
    void extendInventory(int extraSpaces);
    void addDefense(int extraDefense, int duration);
    int getMaxHealth() const;
    int getCurrentHealth() const;

    float getx() const;
    float gety() const;

    sf::Sprite playersprite;
    int maxHealth;
    int health;
    int defense;
    int level;
    int speed;
    Weapon* weapon;

private:
    std::string name;
    int frame;
    std::vector<sf::Texture> textures;
    std::vector<Item*> inventory;
    bool isWalkingLeft;
    bool isWalkingRight;
    sf::Clock animationClock; // For animation timing
};
