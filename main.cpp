#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Fighter.hpp"
#include "Encounter.hpp"
#include "Item.hpp"

#include "Items/Berry.hpp"
#include "Items/Weapon.hpp"

#include "Items/Berries/AcaiBerry.hpp"
#include "Items/Berries/Banana.hpp"
#include "Items/Berries/Blueberry.hpp"
#include "Items/Berries/Cowberry.hpp"

#include "Items/Weapons/Sword.hpp"

using namespace std;

int main(){
    //seed random based on time
    srand(time(0));
    //dictionary of attack types and common names
    map<string, string> attacks = map<string, string>();
    attacks["quick"] = "Slash";
    attacks["pin"] = "Shoot";
    attacks["smash"] = "Kick";
    attacks["final"] = "Hat Throw";
    attacks["heal"] = "Eat Up";
    attacks["item"] = "Use an item";

    //default vector of items
    vector<Item> items;

    //test fighters
    Fighter mc = Fighter(1000, 5, 5, 5, 5, attacks, "mc", "Main", items);
	Fighter op = Fighter(1000, 5, 5, 5, 5, attacks, "op", "Op", items);

    //test fight
    Encounter yeet = Encounter();
    yeet.fight(mc, op);
}
