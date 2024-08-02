#include "character.h"
#include <iostream>

Character::Character() {
	frame = 0;
	health = 100;
	defense = 0;
	levels = 0;
	speed = 0;
	entitybasher = nullptr;
}

void Character::takedamage(int chardmg) {
	health -= chardmg * (100 - defense) / 100;
}

void Character::attack(Character* target) {
	if (entitybasher) {
		target->takedamage(entitybasher->thedamage() + levels * 30);
		std::cout << name << " attacked " << target->name << "!" << std::endl;
	}
	else {
		std::cout << name << " has no weapon to attack with!" << std::endl;
	}
}

bool Character::aliveornot() {
	return health > 0;
}

void Character::levelup() {
	levels++;
	if (levels < 10) {
		maxHealth += 20;
		defense += 10;
		speed += 1;
	}
	else if (levels < 20) {
		maxHealth += 30;
		defense += 20;
		speed += 1;
	}
	else if (levels < 30) {
		maxHealth += 40;
		defense += 30;
		speed += 1;
	}
	else if (levels < 40) {
		maxHealth += 50;
		defense += 40;
		speed += 1;
	}
	else if (levels < 50) {
		maxHealth += 60;
		defense += 50;
		speed += 1;
	}
	else if (levels < 60) {
		maxHealth += 70;
		defense += 60;
		speed += 1;
	}
	else {
		std::cout << "MAX LEVEL REACHED. ALL EXP WILL BE VOIDED." << std::endl;
	}
}

float Character::getx() {
	return sprite.getPosition().x;
}

float Character::gety() {
	return sprite.getPosition().y;
}
