#include <iostream>
#include <string>
#include "../../Item.hpp"
#include "../Berry.hpp"
#include "../../Fighter.hpp";

class Cowberry : public Berry{
	int quantity;
	string name, description;

	AcaiBerry(int q){
		quantity = q;
		name = "Cowberry";
		description = "Moo.";
	}

	void use(Fighter c){
		c.health += 200;
		cout << "Moo." << endl << endl;
	}
};
