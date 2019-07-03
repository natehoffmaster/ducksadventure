#ifndef _Fighter_hpp
#define _Fighter_hpp

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Item.hpp"

using namespace std;

//any fighting character, whether that is an opponent or the main character

class Fighter{
    public:

    int health, speed, stamina, sanity, might;
    map<string, string> attacks;
	string id, name;
    vector<pair<Item, pair<string, pair<string, int>>>> items;

    Fighter(int h, int sp, int st, int sa, int m, map<string, string> a, string identification, string n, vector<pair<Item, pair<string, pair<string, int>>>> i){
        health = h;
    	speed = sp;
    	stamina = st;
    	sanity = sa;
    	might = m;
    	attacks = a;
    	id = identification;
    	name = n;
        items = i;
    }

    Fighter(){

    }

    //rolls a d20 to check damage
    int rolld20(){
        int r = (rand() % 20) + 1;
        return r;
    }

    //calculates damage based on a roll of a d20 and the attack type. also lowers and raises stats based on attack type.
    int calcDamage(int roll, string attackType){
        int curvedRoll = roll * sanity;
        curvedRoll *= might;
        int damage = curvedRoll;
        if(attackType == "pin"){
            //misses if stats are too low
            if(might <= 1) {
                cout << "Your might is too low! The attack missed";
                return 0;
            }
            else {
                speed++;
                might--;
                sanity++;
                damage *= speed / 3;
            }
        }
        else if(attackType == "quick"){
            stamina++;
        }
        else if(attackType == "smash"){
            //misses if stats are too low
            if(stamina == 0) {
                if(id == "mc") {
                    cout << "Your stamina is too low! The attack missed!";
                }
                else {
                    cout << "The opponent's attack missed!";
                }
                return 0;
            }
            else {
                might++;
                stamina--;
            }
        }
        else if(attackType == "final"){
            //misses if stats are too low
            if(stamina <= 3 || sanity <= 3 || speed <= 2) {
                if(id == "mc") {
                    cout << "Your stats are too low! The attack missed!";
                }
                else {
                    cout << "The opponent's attack missed!";
                }
                return 0;
            }
            else {
                damage *= 3;
                stamina -= 3;
                health -= 25;
                sanity -= 2;
                speed--;
            }
        }
        else if(attackType == "heal"){
            health += roll * sanity * 5;
            return 0;
        }
        else{

        }
        return damage;
    }

    //lowers health
    void dockHealth(int damage){
        health -= damage;
    }

    //combines 3 previously declared methods to attack an opponent but returns false if the attack name doesn't exist
    bool attack(Fighter op, string attackName){
        //search attacks for one matching the input
        map<string, string>::iterator it;

        for (it = attacks.begin(); it != attacks.end(); it++){
            if(it->second == attackName){
                int roll = rolld20();
                cout << "The roll was " << roll << "!" << endl;
                string attackType = it->second;
                int damage = calcDamage(roll, attackType);
                op.dockHealth(damage);
                return true;
            }
        }
        //returns false only if the user's input is not one of the character's attack names
        return false;
    }
};

#endif
