#include <iostream>
#include <string>
#include <map>
#include <limits>
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
		string attackName;
		string attackType;
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

			//iterates through and relays player's items if the quantity of item is grater than 0.
			cout << endl << "Your items: " << endl << endl;
			for(int i = 0; i < mc.items.size(); i++){
				if(mc.items[1].second.second.second > 0){
					cout << "\t" << mc.items[i].second.second.second << ": "<< mc.items[i].second.first << ": " << mc.items[i].second.second.first << endl;
				}
			}

			//choose attack type
			while(true){
				cout << endl << "What would you like to do?" << endl;
				map<string, string>::iterator it;
				int count = 1;
				for(it = mc.attacks.begin(); it != mc.attacks.end(); it++){
					cout << count << ". " << it->second << endl;
					count++;
				}

				cout << endl;
				getline(cin, attackName);

				count = 0;
				for(it = mc.attacks.begin(); it != mc.attacks.end(); it++){
					if(it->second == attackName){
						attackType = it->first;
						break;
					}
					else{
						count++;
					}
				}
				//TODO: Fix this fucking thing
				if(count < 6){
					break;
				}
				else{
					cout << "Invalid move. Choose a different move." << endl;
				}
			}

			//determines who attacks first based on the order of the array
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
