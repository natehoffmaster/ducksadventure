#include <iostream>
#include <string>
#include "../../Item.hpp"
#include "../Berry.hpp"
#include "../../Fighter.hpp"

class Cowberry : public Berry{
	public:

	int quantity;
	string name, description;

	Cowberry(){
		name = "Cowberry";
		description = "Moo.";
	}

	void use(Fighter c){
		c.health += 200;
		cout << "Moo." << endl << endl;
	}
};
