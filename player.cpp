#include "player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include "character.h"
using namespace std;
using namespace sf;

player::player(const std::string& charname, int healthpoints, int def, Weapon* bashbash, int level, int spd, sf::Sprite& playersprite, std::vector<sf::Texture>& animations)
    : name(charname), maxHealth(healthpoints), defense(def), weapon(bashbash), level(level), speed(spd), playersprite(playersprite), textures(animations), frame(0), isWalkingLeft(false), isWalkingRight(false) {

}

void player::walkleftanimate() {
    static int frame = 0;
    playersprite.setTexture(textures[9 + frame]);
    frame = (frame + 1) % 9; // Cycle through left walking textures
}

void player::walkrightanimate() {
    static int frame = 0;
    playersprite.setTexture(textures[0 + frame]);
    frame = (frame + 1) % 9; // Cycle through right walking textures
}

void player::idleanimate() {
    playersprite.setTexture(textures[0]); // Assuming 0 is idle
}

float player::getx() const {
    return playersprite.getPosition().x;
}

float player::gety() const {
    return playersprite.getPosition().y;
}
void player::takeDamage(int damage) {
    int actualDamage = damage - defense;
    if (actualDamage < 0) actualDamage = 0;
    health -= actualDamage;
    if (health < 0) health = 0;
}

void player::attack(player& target) {
    target.takeDamage(weapon->damage);
}

void player::restoreHealth(int amount) {
    health += amount;
    if (health > maxHealth) {
        health = maxHealth;
    }
}

void player::extendInventory(int extraSpaces) {
    inventory.reserve(inventory.size() + extraSpaces);
}

void player::addDefense(int extraDefense, int duration) {
    defense += extraDefense;
    // You will need to handle reducing defense after the duration
    // This might involve a turn-based system or a timed callback
}

int player::getMaxHealth() const {
    return maxHealth;
}

int player::getCurrentHealth() const {
    return health;
}

/*player::player(const std::string& charname, int healthpoints, int def, Weapon* bashbash, int level, int spd, sf::Sprite& playersprite, std::vector<sf::Texture>& animations)
    : name(charname), health(healthpoints), defense(def), weapon(bashbash), level(level), speed(spd), playersprite(playersprite), textures(animations), frame(0) {

}
    
void player::walkingleft() {
    playersprite.move(Vector2f(-0.25, 0));
}

void player::walkingright() {
    playersprite.move(Vector2f(0.25, 0));
}

void player::idleanimate() {
    playersprite.setTexture(textures[0]);
}

void player::walkanimate() {
    frame++;
    if (frame >= textures.size()) {
        frame = 0;
    }
    playersprite.setTexture(textures[frame]);
}

float player::getx() const {
    return playersprite.getPosition().x;
}

float player::gety() const {
    return playersprite.getPosition().y;
}*/
