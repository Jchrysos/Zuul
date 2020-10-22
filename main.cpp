#include <iostream>
#include <string>
#include "Room.h"
using namespace std;
// player will be a pointer to a room (the room the player is in) so it can easily be pointed to something else, and it's easy to go between the room and pointer
Item MOP = {
    "Just a standard mop, the kind that someone would use to clean something.",
    1,
};
Item BEAN = {
    "A bean you found on the ground, it looks good enough to eat! (but please don't).",
    6,
};
Item POINTER = {
    "I'm guessing it's supposed to point at something? Mr. Galbraith loves these things.",
    9,
};
Item MEDALLION = {
    "This can be exchanged for goods and services at the student store. But I don't want to program that in so don't try it.",
    14,
};
Item SWORD = {
    "Put that thing down, hooligan!",
    12,
};
// define Items() function
void Items(int location){
if(location == 0) cout << "You have the following items:" << endl;
else cout << "This room contains the following items:" << endl;
if(MOP.location == location) cout << "MOP" << endl; 
if(BEAN.location == location) cout << "BEAN" << endl; 
if(POINTER.location == location) cout << "POINTER" << endl; 
if(MEDALLION.location == location) cout << "MEDALLION" << endl; 
if(SWORD.location == location) cout << "SWORD" << endl; 
if(MOP.location != location 
&& BEAN.location != location 
&& POINTER.location != location 
&& MEDALLION.location != location 
&& SWORD.location != location) cout << "Nothing!" << endl;
}
// define all rooms with description and exits
Room r1 = {
  1,
  "1-20: This is the SHS computer lab. All the cool people are here, also Mr. Galbraith is here.",
  {{"WEST",2}}
};
Room r2 = {
    2,
    "1 Hall: They say that in the old days this hall used to be so full of people that you could barely walk! To the east is 1-20... better get back to class before he notices you're missing!",
    {{"EAST",1},{"NORTH",3},{"SOUTH",13}}
};
Room r3 = {
    3,
    "Big intersection: Mr. Huelscamp is here, doing some sort of karate demonstration. Several admins are stacked unconscious next to the vending machines.",
    {{"WEST",6},{"EAST",11},{"NORTH",4},{"SOUTH",2}}
};
Room r4 = {
    4,
    "A-wing: There is a group of students working on a project. It seems to be a poster titled 'What If Frederick Douglas Met Shakespeare?'",
    {{"WEST",5},{"SOUTH", 3}}
};
Room r5 = {
    5,
    "NW Exit: Don't even think about leaving out those doors! Unless you want to be hunted down by a bald man in a golf cart, that is.",
    {{"EAST",4},{"SOUTH",6}}
};
Room r6 = {
    6,
    "Cafeteria: There is a massive beanstalk stretching into the sky! Seems kind of obvious what's supposed to happen here right?",
    {{"NORTH",5},{"EAST",3},{"UP",7}}
};
Room r7 = {
    7,
    "Cloud Courtyard: This area is a fluffy courtyard in the sky. There is a massive castle towering up ahead.",
    {{"NORTH",8},{"DOWN",6}}
};
Room r8 = {
    8,
    "Cloud Castle: There is a chandelier hanging above you. A banner above the eastern room reads 'stack' and the corresponding banner to the west says 'heap.'",
    {{"WEST",10},{"EAST",9},{"SOUTH",7}}
};
Room r9 = {
    9,
    "Stack: This poorly furnished room is full of brackets, classes, operators, and other things that don't make sense to me.",
    {{"WEST",8}}
};
Room r10 = {
    10,
    "Heap: You're standing in the middle of a HEAP of gold and jewels (ha ha!). You go to pick up a particularly enchanting ruby but the programmer apparently didn't bother making it an Item.",
    {{"EAST",8}}
};
Room r11 = {
    11,
    "Office: There are a bunch of national geographic books on a table in the seating area. Yes, books, not just magazines. I didn't even know national geographic made books. They're encyclopedias or something. They're very big!! So heavy that you could not possibly pick them up, or even check them.",
    {{"WEST",3},{"NORTH",12}}
};
Room r12 = {
    12,
    "Hueslcamp's Office: The walls are covered with assorted Norse and Japanese weaponry, as well several smallish skulls, each of which has a little plaque. You read one of them: 'This wise guy thought he didn't have to check in for advisory.'",
    {{"SOUTH",11}}
};
Room r13 = {
    13,
    "South Exit: You would leave but you're just too excited to get back to c++ class!",
    {{"EAST",14},{"NORTH",2}}
};
Room r14 = {
    14,
    "MacNamee's AT: This is where Pranav has AT... although as usual he's not here.",
    {{"WEST",13},{"NORTH",15}}
};
Room r15 = {
    15,
    "East Exit: Everyone's pressed against the window, looking out at something... from back here you can't tell what it is.",
    {{"WEST", 13},{"SOUTH", 14}}
};
Room * player = & r1;
int main(){
  cout << "Welcome to Zuul! You can always EXIT to leave the game, but there is a way to win. Good luck!\n\n\n\n";
    bool exit = false;
    while(exit == false){
      if (POINTER.location == 1){
        cout << "Mr. Galbraith approaches you!\n\n 'Hey did you bring this POINTER for me? You should be using this in your code!! Try resubmitting.\n\n\n ... YOU WIN!";
        exit = true;
        break;
      }
      cout << endl;
        PrintInfo(player);
        cout << endl;
        string response;
        cout << "What do you want to do? MOVE or ITEM: ";
        cin >> response;
        if (response == "MOVE"){
            string directionresponse;
            cout << "Where do you want to go?" << endl;
            cin >> directionresponse;
            bool moved = false;
            // this way of moving is really stupid but it's what I came up with. I check if your direction input actually goes to a neighbor, then check the location, then specify exactly what room corresponds with each.
            for (auto x : player->neighbors){
                if(x.first == directionresponse){
                    if (x.second == 1) player = &r1;
                    else if (x.second == 2) player = &r2;
                    else if (x.second == 3) player = &r3;
                    else if (x.second == 4) player = &r4;
                    else if (x.second == 5) player = &r5;
                    else if (x.second == 6) player = &r6;
                    else if (x.second == 7) player = &r7;
                    else if (x.second == 8) player = &r8;
                    else if (x.second == 9) player = &r9;
                    else if (x.second == 10) player = &r10;
                    else if (x.second == 11) player = &r11;
                    else if (x.second == 12) player = &r12;
                    else if (x.second == 13) player = &r13;
                    else if (x.second == 14) player = &r14;
                    else if (x.second == 15) player = &r15;
                    moved = true;
                };
            }
            if (moved == false) cout << "Nice try, but you can't go that way!" << endl;
        }
        else if (response == "ITEM"){
            string itemresponse;
            cout << "TAKE, DROP, or CHECK? ";
            cin >> itemresponse;
            if (itemresponse == "TAKE"){
                string takeresponse;
                // LIST ITEMS WITH CURRENT LOCATION
                Items(player->location);
                cin >> takeresponse;
                // Go through items, check if they're actually in the location, then change their location to 0: inventory
                if (takeresponse == "MOP" && MOP.location == player->location) MOP.location = 0;
                else if (takeresponse == "BEAN" && BEAN.location == player->location) BEAN.location = 0;
                else if (takeresponse == "POINTER" && POINTER.location == player->location) POINTER.location = 0;
                else if (takeresponse == "MEDALLION" && MEDALLION.location == player->location) MEDALLION.location = 0;
                else if (takeresponse == "SWORD" && SWORD.location == player->location) SWORD.location = 0;
                else cout << "Sorry, there's nothing like that here." << endl;
            }
            else if (itemresponse == "DROP"){
                string dropresponse;
                // LIST ITEMS WITH LOCATION == 0
                Items(0);
                cin >> dropresponse;
                // Go through items, check if they're in inventory, and if they are set them to current location
                if (dropresponse == "MOP" && MOP.location == 0) MOP.location = player->location;
                else if (dropresponse == "BEAN" && BEAN.location == 0) BEAN.location = player->location;
                else if (dropresponse == "POINTER" && POINTER.location == 0) POINTER.location = player->location;
                else if (dropresponse == "MEDALLION" && MEDALLION.location == 0) MEDALLION.location = player->location;
                else if (dropresponse == "SWORD" && SWORD.location == 0) SWORD.location = player->location;
                else cout << "Sorry, you don't have anything like that." << endl;
            }
            else if (itemresponse == "CHECK"){
                string checkresponse;
                // LIST ITEMS WITH current location
                Items(player->location);
                // List items in inventory, location 0
                Items(0);
                cin >> checkresponse;
                // Check if the item is either in inventory or in the current location, then cout the description
                if (checkresponse == "MOP" && (MOP.location == 0 || MOP.location == player->location)) cout << MOP.description;
                else if (checkresponse == "BEAN" && (BEAN.location == 0 || BEAN.location == player->location)) cout << BEAN.description;
                else if (checkresponse == "POINTER" && (POINTER.location == 0 || POINTER.location == player->location)) cout << POINTER.description;
                else if (checkresponse == "MEDALLION" && (MEDALLION.location == 0 || MEDALLION.location == player->location)) cout << POINTER.description;
                else if (checkresponse == "SWORD" && (SWORD.location == 0 || SWORD.location == player->location)) cout << SWORD.description;
                else cout << "Sorry, there's nothing like that around." << endl;
            }
        }
        else if (response == "EXIT"){
          exit = true;
        }
        else{ cout << "Having difficulty reading? The options are MOVE or ITEM!" << endl;}
    }
    return 0;
}