#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
//define parent class "room"
using namespace std;
class Room {
    public:
    int location;
    string description;
    unordered_map<string, int> neighbors;
};
void PrintInfo(Room * player);
void Items(int location);
void Exits(Room r);
// Also define "item" struct
struct Item {
string description;
int location; // 0 will be inventory
};
