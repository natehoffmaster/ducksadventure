#include <iostream>
#include <string>
#include <map>
#include "Fighter.hpp"
#include "Item.hpp"

#include "Items/Berry.hpp"
#include "Items/Weapon.hpp"

#include "Items/Berries/AcaiBerry.hpp"
#include "Items/Berries/Banana.hpp"
#include "Items/Berries/Blueberry.hpp"
#include "Items/Berries/Cowberry.hpp"

#include "Items/Weapons/Sword.hpp"

using namespace std;

class Encounter{
	public:

	Encounter(){

	}

	//all code relevant to a fight between two parties
	void fight(Fighter mc, Fighter op){
		map<string, string>::iterator it;
		Fighter* order = new Fighter[2];
		string attackName, attackType, first, second, opAttackName, opAttackType, itemUse;
		int i, randSelect, count;

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
			for(i = 0; i < mc.items.size(); i++){
				if(mc.items[i].second.second.second > 0){
					cout << "\t" << mc.items[i].second.second.second << ": "<< mc.items[i].second.first << ": " << mc.items[i].second.second.first << endl;
				}
			}

			//choose attack type
			while(true){
				cout << endl << "What would you like to do?" << endl;
				map<string, string>::iterator it;
				count = 1;
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

				//try again if invalid move
				if(count < 6){
					break;
				}
				else{
					cout << "Invalid move. Choose a different move." << endl;
				}
			}

			//randomly selects an attack for the opponent
			randSelect = rand() % op.attacks.size();
			i = 0;
			for(it = op.attacks.begin(); it != op.attacks.end(); it++){
				if(randSelect == i){
					opAttackName = it->second;
					opAttackType = it->first;
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
				randSelect = rand() % 2;
				if(!randSelect){
					order[0] = mc;
					order[1] = op;
				}
				else{
					order[0] = op;
					order[1] = mc;
				}
			}

			//rolls d20 and attacks based on fighters' stats
			if(order[0].id == "mc"){
				//only execute attack if an item was not used
				if(attackType != "item"){
					int firstRoll = mc.rolld20();
					cout << endl << "You rolled a " << firstRoll << "!" << endl << endl;
					mc.attack(op, attackName, firstRoll);
				}
				//if an item is used, the item will decreases its quantity by one and use itself
				else{
					cout << endl << "Your items: " << endl << endl;
					for(int i = 0; i < mc.items.size(); i++){
						if(mc.items[i].second.second.second > 0){
							cout << "\t" << mc.items[i].second.second.second << ": "<< mc.items[i].second.first << ": " << mc.items[i].second.second.first << endl;
						}
					}
					cout << endl << "Which item would you like to use?";
					getline(cin, itemUse);
					count = 0;
					for(i = 0; i < mc.items.size(); i++){
						if(mc.items[i].second.first == itemUse){
							Item item;

							if(itemUse == "Acai Berry"){
								AcaiBerry* useItem = (AcaiBerry*) &item;
								useItem->use(mc);
							}
							if(itemUse == "Banana"){
								Banana* useItem = (Banana*) &item;
								useItem->use(mc);
							}
							if(itemUse == "Blueberry"){
								Blueberry* useItem = (Blueberry*) &item;
								useItem->use(mc);
							}
							if(itemUse == "Cowberry"){
								Cowberry* useItem = (Cowberry*) &item;
								useItem->use(mc);
							}

							if(itemUse == "Sword"){
								Sword* useItem = (Sword*) &item;
								useItem->use(mc, op);
							}

							break;
						}

						//TODO: Add usage capability
					}
				}
			}
		}
	}
};
