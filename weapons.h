#pragma once
#include "includes.h"
using namespace sf;
#include <SFML/Graphics.hpp>
#include <vector>
class Weapon {
public:
	string type;
	int damage;
	int thedamage();
	string findtype();
	Weapon(const std::string& type, int damage);
	void animating();
	std::vector<sf::Texture> textures;
	sf::Sprite broomsprite;
};