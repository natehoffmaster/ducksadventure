#ifndef _Banana_hpp
#define _Banana_hpp

#include <iostream>
#include <string>
#include "../../Item.hpp"
#include "../Berry.hpp"
#include "../../Fighter.hpp"

class Banana : public Berry{
	public:

	Banana(){

	}

	void use(Fighter c){
		c.health += 200;
		cout << "Your health was increased by 200!" << endl << endl;
	}
};

#endif
