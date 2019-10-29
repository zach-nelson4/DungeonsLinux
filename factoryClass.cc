///
/// \author Nathan Yarbrough and Jared Sisco
/// \date Oct 26th 2017
/// CPSC 2720
/// The factory class that is responsable for creating items, enemies, and chests.

#ifndef factoryClass_C
#define factoryClass_C

#include <iostream>
#include <vector>
#include "factoryClass.h"
#include "chest.h"
#include "enemy.h"
#include "potion.h"
#include "item.h"


using namespace std;

factoryClass::factoryClass(){
};



//New Factory class
//
//3 functions
//
//vector of enemy

vector<enemy*> factoryClass:: makeEnemies(){
   
   enemy* E1;
   enemy* E2;
   enemy* E3;
   enemy* E4;
   enemy* E5;
   enemy* E6;
   enemy* E7;
   enemy* E8;
   

//Spawning Enemies for room 1
   E1 = new enemy(10, 10, 1, 13);
   enemies.push_back(E1);

//Spawning Enemies for room 2
   E2 = new enemy(15, 15, 7, 1);
   enemies.push_back(E2);

   E3 =  new enemy(15, 15, 7, 24);
   enemies.push_back(E3);

//Spawning Enemies for room 3
   
   E4 = new enemy(10, 30, 7, 15);
   enemies.push_back(E4);

//Spawning Enemies for room 4
   E5 =  new enemy(25, 20, 1, 13);
   enemies.push_back(E5);

//Spawning Enemies for room 5
   E6 = new enemy(25, 10, 7,24);
   enemies.push_back(E6);
   
   E7 = new enemy(15, 15, 7,1);
   enemies.push_back(E7);
 //No Enemies for room 6
 //Spawning Enemies for room 7 (Boss)
   E8 = new enemy(20, 50, 7,1);
   enemies.push_back(E8);

   return enemies;
}

//vector of item


void factoryClass:: makeWeapon(){

//Spawning Items for room 1
   W1 = new weapon("Nice Sword",5);

//Spawning Items for room 6
   W2 = new weapon("Best Sword",10);
}

void factoryClass:: makePotion(){
//Spawning Items for room 4
   P1 = new potion("Small Potion",100);

//Spawning Items for room 7
   P2 = new potion("Small Potion",100);
}


void factoryClass:: makeArmour(){


//Spawning Items for room 2
   A1 = new armour("Nice Armour",5);

//Spawning Items for room 3
   H1 = new armour("Nice Helmet",5);
   
//Spawning Items for room 5
   A2 = new armour("Best Armour",10);
   H2 = new armour("Best Helmet",10);
   
}

//vector of chest
vector<chest*> factoryClass::makeChests(){

   chest* C1;
   chest* C2;
   chest* C3;
   chest* C4;
   chest* C5;
   chest* C6;
   chest* C7;
   chest* C8;

//Spawning Chests for room 1
   C1 = new chest(13,13,W1);
   chests.push_back(C1);

//Spawning Chests for room 2
   C2 = new chest(1,13,A1);
   chests.push_back(C2);

//Spawning Chests for room 3
   C3 = new chest(7,13,H1);
   chests.push_back(C3);
   
//Spawning Chests for room 4
   C4 = new chest(13,22,P1);
   chests.push_back(C4);

//Spawning Chests for room 5
   C5 = new chest(1,7,A2);
   C6 = new chest(1,13,H2);
   chests.push_back(C5);
   chests.push_back(C6);

//Spawning Chests for room 6
   C7 = new chest(2,20,W2);
   chests.push_back(C7);

//Spawning Chests for room 7
   C8 = new chest(7,20,P2);
   chests.push_back(C8);

   return chests;
}

//Destructor

factoryClass::~factoryClass(){

delete E1;
delete E2;
delete E3;
delete E4;
delete E5;
delete E6;
delete E7;
delete E8;
}






#endif
