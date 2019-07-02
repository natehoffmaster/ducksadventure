#include <iostream>
#include <string>
#include "../../Item.hpp"
#include "../Weapon.hpp"

class Sword : public Weapon{
	int quantity, durability;
	string description, name;

	Sword(int q){
		quantity = q;
		name = "Sword";
		durability = 5;
		description = "No matter the might of the user, he always attacks with 10 might and speed is increased by 1. However, the sword can only be used five times before it breaks.";
	}

	void use(Fighter mc, Fighter op){
		int roll = c.rolld20();
		int damage = calcDamage(roll, "default") / c.might * 8;
		op.dockHealth(damage);
	}
};
