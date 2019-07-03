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

    //initialize objects for all items with a quantity of zero
    AcaiBerry acaiBerry = AcaiBerry();
    Banana banana = Banana();
    Blueberry blueberry = Blueberry();
    Cowberry cowberry = Cowberry();

    Sword sword = Sword();

    //default vector of items, including object, name, description, and quantity
    pair<string, int> acaiBerryDesQ = make_pair("High in protein. Increases might by 3.", 0);
    pair<string, int> bananaDesQ = make_pair("Sweet and flavorful. Increases health by 200.", 0);
    pair<string, int> blueberryDesQ = make_pair("Sweet and juicy. Increases health by 200.", 0);
    pair<string, int> cowberryDesQ = make_pair("Moo.", 0);

    pair<string, int> swordDesQ = make_pair("No matter the might of the user, it always attacks with 8 might and speed is increased by 1.", 0);


    pair<string, pair<string, int>> acaiBerryNDesQ = make_pair("Acai Berry", acaiBerryDesQ);
    pair<string, pair<string, int>> bananaNDesQ = make_pair("Banana", bananaDesQ);
    pair<string, pair<string, int>> blueberryNDesQ = make_pair("Blueberry", blueberryDesQ);
    pair<string, pair<string, int>> cowberryNDesQ = make_pair("Cowberry", cowberryDesQ);

    pair<string, pair<string, int>> swordNDesQ = make_pair("Sword", swordDesQ);


    pair<Item, pair<string, pair<string, int>>> acaiBerryONDesQ = make_pair(acaiBerry, acaiBerryNDesQ);
    pair<Item, pair<string, pair<string, int>>> blueberryONDesQ = make_pair(blueberry, blueberryNDesQ);
    pair<Item, pair<string, pair<string, int>>> bananaONDesQ = make_pair(banana, bananaNDesQ);
    pair<Item, pair<string, pair<string, int>>> cowberryONDesQ = make_pair(cowberry, cowberryNDesQ);

    pair<Item, pair<string, pair<string, int>>> swordONDesQ = make_pair(sword, swordNDesQ);


    vector<pair<Item, pair<string, pair<string, int>>>> items = vector<pair<Item, pair<string, pair<string, int>>>>();

    items.push_back(acaiBerryONDesQ);
    items.push_back(blueberryONDesQ);
    items.push_back(bananaONDesQ);
    items.push_back(cowberryONDesQ);

    items.push_back(swordONDesQ);


    //test fighters
    Fighter mc = Fighter(1000, 5, 5, 5, 5, attacks, "mc", "Main", items);
	Fighter op = Fighter(1000, 5, 5, 5, 5, attacks, "op", "Op", items);

    //test fight
    Encounter yeet = Encounter();
    yeet.fight(mc, op);
}
