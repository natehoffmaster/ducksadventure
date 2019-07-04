#ifndef _Blueberry_hpp
#define _Blueberry_hpp

#include <iostream>
#include <string>
#include "../../Item.hpp"
#include "../Berry.hpp"
#include "../../Fighter.hpp"

class Blueberry : public Berry{
	public:

	Blueberry(){

	}

	void use(Fighter c){
		c.health += 200;
		cout << "Your health was increased by 200!" << endl << endl;
	}
};

#endif
