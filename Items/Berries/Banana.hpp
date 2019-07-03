#include <iostream>
#include <string>
#include "../../Item.hpp"
#include "../Berry.hpp"
#include "../../Fighter.hpp"

class Banana : public Berry{
	public:

	int quantity;
	string name, description;

	Banana(){
		name = "Banana";
		description = "Sweet and flavorful. Increases health by 200.";
	}

	void use(Fighter c){
		c.health += 200;
		cout << "Your health was increased by 200!" << endl << endl;
	}
};
