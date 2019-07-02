#include <iostream>
#include <string>
#include <map>
#include "Fighter.hpp"

using namespace std;

class Encounter{
	public:

	Encounter(){
		
	}

	//all code relevant to a fight between two parties
	void fight(Fighter mc, Fighter op){
		map<string, string>::iterator it;
		Fighter* order = new Fighter[2];
		while(mc.health > 0 && op.health > 0){
			//relays stats to player
			cout << "Your stats: " << endl << endl <<
			"\tHealth: " << mc.health << endl <<
			"\tSpeed: " << mc.speed << endl <<
			"\tStamina: " << mc.stamina << endl <<
			"\tSanity: " << mc.sanity << endl <<
			"\tMight: " << mc.might << endl << endl;

			cout << "Your opponent's health: " << op.health << endl << endl;

			//relays player's moves
			cout << "Your moves: " << endl << endl;
			for(it = mc.attacks.begin(); it != mc.attacks.end(); it++){
				cout << "\t" << it->second << endl;
			}

			//determines who attacks first
			if(mc.speed > op.speed){
				order[0] = mc;
				order[1] = op;
			}
			else if(mc.speed < op.speed){
				order[0] = op;
				order[1] = mc;
			}
			else{
				int r = rand() % 2;
				if(!r){
					order[0] = mc;
					order[1] = op;
				}
				else{
					order[0] = op;
					order[1] = mc;
				}
			}
		}
	}
};
