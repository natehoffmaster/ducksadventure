#include <iostream>
#include <string>
#include "../../Item.hpp"
#include "../Weapon.hpp"

class Sword : public Weapon{
	public:

	Sword(){

	}

	//attacks with 8 might rather than with an attack name
	void use(Fighter mc, Fighter op){
		int roll = mc.rolld20();
		int damage = mc.calcDamage(roll, "default") / mc.might * 8;
		op.dockHealth(damage);
		mc.speed++;
	}
};
