/****************************************************************************
/// \author Jared Sisco
/// \date Oct 26th 2017
/// CPSC 2720
/// Defines the large World Class which is essentially a builder class.
*****************************************************************************/

#ifndef worldClass_H
#define worldClass_H

#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

#include "chest.h"
#include "room.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "screen.h"
#include "factoryClass.h"
#include "armour.h"
#include "weapon.h"
#include "potion.h"

using namespace std;

class worldClass{
public:


worldClass(const screen &s);

/// The destructor
~worldClass();

/// Holds a vector of all rooms in the world
room* rooms[7];
vector<chest*> chests;
vector<enemy*> enemies;
player* player_ptr;
screen screen_ptr;
factoryClass* factory_ptr;


/// SpawnPlayer function, creates the player at the default location
player* spawnPlayer();

/// SwitchRoom function, switches currently used room
/// \param[in] Reference room to switch to
room* switchRoom(const int &r);

/// buildRooms function which builds the rooms of the game
/// \param[in] in the screen which to build the rooms on
void buildRooms(screen &s);

/// buildEnemies functino which builds the enemies of the game
/// \param[in] in the screen to build the enemies on 
void buildEnemies(screen &s);

/// buildChests function which builds the chests of the game
/// \param[in] in the screen to build the enemies on
void buildChests(screen &s);

/// displayMenu, which displays the menu
void displayMenu();

};


#endif
