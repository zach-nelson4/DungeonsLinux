/***************************************************
\Author: Zachary Nelson
\Date: October 24th 2017

This is the room class for the "Dungeon Linux" game.
This class contains all of the information contained in each room for the game.

*****************************************************/

#include <iostream>
#include "player.h"
#include "screen.h"
#include "enemy.h"
#include "screenElement.h"
#include <vector>
#include "chest.h"
#include "battle.h"

using namespace std;

#ifndef room_H
#define room_H

/// The room describes an object which is bound by 4 walls and contains enemies
/// and players

class room{
  public:

   ///This is the constructor, to create a room, provide four bool values.
   ///When each bool is set to true, it means there will be a door in that location.
   ///Also provide a reference to the screen which you will draw the room on.
   /// \param[in] Bool for the north side
   /// \param[in] Bool for the east side
   /// \param[in] Bool for the south side
   /// \param[in] Bool for the west side
   /// \param[in] the Screen which the room exists on
   room(const bool &north, const bool &east,const bool &south, const bool &west, screen &s);

   ///A destructor for the room
   ~room();


   ///Clears out all of the items drawn on screen which were contained in the room.
   /// \param[in] the screen for which to clear from
   void clear(screen &s);

   ///Adds an enemy to the room
   ///\param[in] in the enemy which you wish to add to the room
   void addEnemy(const enemy &e);

   ///Adds a chest to the room
   /// \param[in] in the chest which you want to add to the room
   void addChest(chest* c);

   ///redraws the room on the screen
   /// \param[in] in the screen for which to draw on
   void redraw(screen &s);

   ///kills an enemy
   /// \param[in] in the enemy which you want to remove from the room
   /// \param[in] the screen for which to remove from
   void kill(enemy e, screen &s);

   ///kills a chest
   /// \param[in] in the chest you want to remove from the room
   /// \param[in] the screen you want to remove the chest from
   void kill(chest c, screen &s);

   ///Checks for a collision between the player and anything in the room
   ///\param[in] in the player and the screen
   void checkForCollision(player &p, screen &s);

   
  private:
   vector<enemy> things;
   vector<chest> chests;
   void displayEnemy();
   void displayChest();
   bool North, East, South, West;
};

#endif
