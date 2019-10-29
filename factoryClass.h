///
/// \author Jared Sisco
/// \date Oct 26th 2017
/// CPSC 2720
/// The factory class that is responsable for creating item and monsters from an ID/SubID

#ifndef factoryClass_H
#define factoryClass_H

#include <iostream>
#include <cassert>

#include "item.h"
#include "enemy.h"
#include "chest.h"
#include "potion.h"
#include <vector>

using namespace std;

class factoryClass {

public:


factoryClass();
~factoryClass();

vector<chest*> makeChests();
void makeArmour();
void makeWeapon();
void makePotion();
vector<enemy*> makeEnemies();

/// CreateEnemy function, creates an enemy object and returns a pointer to it. Uses a int switch to define enemy stats
/// \param[in] Int to switch on, determine enemy that spawns

/// CreateItem function, creates an item object and returns a pointer to it. Uses a int switch to define item type, and another int to set quality of item
/// \param[in] Int to switch on, determine item that is returned and what quality that item is.

/// CreateRoom function, creates an room object and returns a pointer to it. Uses a int switch to define room style
/// \param[in] Int to switch on, determine room that is returned

private:

vector<enemy*> enemies;
vector<chest*> chests;

   enemy* E1;
   enemy* E2;
   enemy* E3;
   enemy* E4;
   enemy* E5;
   enemy* E6;
   enemy* E7;
   enemy* E8; 



   weapon* W1;
   weapon* W2;
   armour* A1;
   armour* A2;
   armour* H1;
   armour* H2;
   potion* P1;
   potion* P2;

};

#endif
