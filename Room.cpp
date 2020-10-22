#include <iostream>
#include <string>
#include <unordered_map>
#include "Room.h"
using namespace std;
// cout all the items which are in a given location

// cout all the exits in a given location
void Exits(Room r){
  cout << "These are the exits: ";
    for (auto x : r.neighbors){
        cout << x.first << "  ";
    }
}
void PrintInfo(Room * player){
    cout << player->description << endl;
    Items(player->location);
    Exits(*player);
}
