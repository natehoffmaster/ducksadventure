#include <iostream>
#include <string>
#include "../../Item.hpp"
#include "../Weapon.hpp"

class Sword : public Weapon{
	public:

	int quantity, durability;
	string description, name;

	Sword(){
		name = "Sword";
		durability = 5;
		description = "No matter the might of the user, it always attacks with 10 might and speed is increased by 1. However, the sword can only be used five times before it breaks.";
	}

	//attacks with 8 might rather than with an attack name
	void use(Fighter mc, Fighter op){
		int roll = mc.rolld20();
		int damage = mc.calcDamage(roll, "default") / mc.might * 8;
		op.dockHealth(damage);

		if(durability - 1 != 0){
			durability--;
		}
		//destroys sword when durability runs lows
		else{
			quantity--;
			cout << "The sword has broken!" << endl << endl;
		}
	}
};
