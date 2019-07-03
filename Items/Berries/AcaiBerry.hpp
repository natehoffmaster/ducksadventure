#include <iostream>
#include <string>
#include "../../Item.hpp"
#include "../Berry.hpp"
#include "../../Fighter.hpp"

class AcaiBerry : public Berry{
	public:

	int quantity;
	string name, description;

	AcaiBerry(){
		name = "Acai Berry";
		description = "High in protein. Increases might by 3.";
	}

	void use(Fighter c){
		c.might += 3;
		cout << "Your might was increased by 3!" << endl << endl;
		quantity--;
	}
};
