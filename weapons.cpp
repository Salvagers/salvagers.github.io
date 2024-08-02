#include "weapons.h"
#include "includes.h"

Weapon::Weapon(const std::string& type, int damage)
	: type(type), damage(damage) {}
string Weapon::findtype() {
	return type;
}
int Weapon::thedamage() {
	return damage;
}

void Weapon::animating() {
	static int frame = 0;
	broomsprite.setTexture(textures[0 + frame]);
	frame = (frame + 1) % 9;
}