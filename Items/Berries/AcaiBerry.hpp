#ifndef _AcaiBerry_hpp
#define _AcaiBerry_hpp

#include <iostream>
#include <string>
#include "../../Item.hpp"
#include "../Berry.hpp"
#include "../../Fighter.hpp"

class AcaiBerry : public Berry{
	public:

	AcaiBerry(){

	}

	void use(Fighter c){
		c.might += 3;
		cout << "Your might was increased by 3!" << endl << endl;
	}
};

#endif
