#include <iostream>
#include <string>
#include "../../Item.hpp"
#include "../Berry.hpp"
#include "../../Fighter.hpp"

class Cowberry : public Berry{
	public:

	Cowberry(){

	}

	void use(Fighter c){
		c.health += 200;
		cout << "Moo." << endl << endl;
	}
};
