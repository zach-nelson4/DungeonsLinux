///
/// \author Jared Sisco and Zach Nelson
/// \date Oct 26th 2017
/// CPSC 2720
/// Defines the large World Class that keeps track of most objects, manages saving and loading along with menu states

#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include "room.h"
#include "player.h"
#include "enemy.h"
#include "worldClass.h"
#include "factoryClass.h"
#include "armour.h"
#include "weapon.h"
#include "potion.h"
#include "chest.h"

using namespace std;

//constructor
worldClass::worldClass(const screen& s)
{
   factory_ptr = new factoryClass();
   factory_ptr->makeArmour();
   factory_ptr->makeWeapon();
   factory_ptr->makePotion();
}

//Destructor
worldClass::~worldClass()
{
}

//Spawns the player
player* worldClass::spawnPlayer()
{
   player_ptr = player::getInstance();
   return player_ptr;
}

//switches current room the player is in
room* worldClass::switchRoom(const int &r)
{
   return rooms[r];
}

//Displays the general menu
void worldClass::displayMenu(){
   cout << "What would you like to do?" << endl;
   cout << "W = Move North. D = Move East. S = Move South. A = Move West." << endl;
   cout << "X denotes an enemy, and C denotes a chest. Q to quit. "<< endl;
}


//Builds the rooms of the game
void worldClass::buildRooms(screen &s){
   //Building Room 1
   room* R1;
   room* R2;
   room* R3;
   room* R4;
   room* R5;
   room* R6;
   room* R7;
   R1 = new room(true, false, false, false, s);
   R2 = new room(false, true, true, true, s);
   R3 = new room(false, true, false, false, s);
   R4 = new room(true, false, false, true, s);
   R5 = new room(false, true, true, true, s);
   R6 = new room(false, false, false, true, s);
   R7 = new room(false, true, false, true, s);

   rooms[0] = R1;
   rooms[1] = R2;
   rooms[2] = R3;
   rooms[3] = R4;
   rooms[4] = R5;
   rooms[5] = R6;
   rooms[6] = R7;

}

//Builds the enemies in the room
void worldClass::buildEnemies(screen &s){
   enemies = factory_ptr->makeEnemies();
//Spawning Enemies for room 1
   rooms[0]->addEnemy(*enemies[0]);
   
//Spawning Enemies for room 2
   rooms[1]->addEnemy(*enemies[1]);
   rooms[1]->addEnemy(*enemies[2]);

   //Spawning enemies for room 3
   rooms[2]->addEnemy(*enemies[3]);

   //spawning enemies for room 4
   rooms[3]->addEnemy(*enemies[4]);

   //spawning enemies for room 5
   rooms[4]->addEnemy(*enemies[5]);
   rooms[4]->addEnemy(*enemies[6]);

   //spawning enemies for room 7
   rooms[6]->addEnemy(*enemies[7]);

}

//buildChests function, which builds all the chests in the game
void worldClass::buildChests(screen &s){

   chests = factory_ptr->makeChests();
   //Spawning chests for Room 1
   rooms[0]-> addChest(chests[0]);

   //Spawning chests for room 2
   rooms[1]-> addChest(chests[1]);

   //Spawning chest for room 3
   rooms[2]-> addChest(chests[2]);

   //Spawning chest for room 4
   rooms[3]-> addChest(chests[3]);

   //Spawning chest for room 5
   rooms[4]-> addChest(chests[4]);
   rooms[4]-> addChest(chests[5]);

   //spawning chest for room 6
   rooms[5]-> addChest(chests[6]);

   //spawning chest for room 7
   rooms[6]-> addChest(chests[7]);

}

