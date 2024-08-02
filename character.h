//#pragma once
//#include "includes.h"
//#include "weapons.h"
//#include <SFML/Graphics.hpp>
//#include <vector>
//#include <string>
//
//class Character {
//protected:
//	std::string name;
//	int health;
//	int defense;
//	Weapon* entitybasher;
//	int levels;
//	int speed;
//	sf::Sprite sprite;
//	std::vector<sf::Texture> animations;
//	int frame;
//
//public:
//	Character();
//	void takedamage(int chardmg);
//	void attack(Character* target);
//	bool aliveornot();
//	void levelup();
//	void walkingright();
//	void walkingleft();
//	float getx();
//	float gety();
//	void idleanimate();
//	void walkanimate();
//	void initializeTextures();
//};



#pragma once
#include "includes.h"
#include "weapons.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Character {
protected:
    std::string name;
    int maxHealth;
    int health;
    int defense;
    Weapon* entitybasher;
    int levels;
    int speed;
    sf::Sprite sprite;
    std::vector<sf::Texture> animations;
    int frame;

public:
    Character();
    void takedamage(int chardmg);
    void attack(Character* target);
    bool aliveornot();
    void levelup();
    void walkingright();
    void walkingleft();
    float getx();
    float gety();
    void idleanimate();
    void walkanimate();
    void initializeTextures();
};
