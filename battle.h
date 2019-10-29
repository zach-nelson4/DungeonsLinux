/*****************************************************************************
/// \battle.h
/// \author Darsh Thanki
/// \date Oct 22, 2017
///
///
/// The Battle class is a class that determines turns of battle, damage dealt to
/// enemies and the player. Additionally, the class allows the menu class to
/// display/execute different options such as fight or run.
******************************************************************************/

#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <vector>
#include "screenElement.h"
#include "entity.h"
#include "enemy.h"
using namespace std;

class battle{
  public:

   /// Constructor

   battle();

   /// Destructor of the battle class
   ~battle();

   /// battleAction function to facilitate the players choice of
   /// fighting or running

   bool battleAction();

   /// fight function is used to facilitate the actual fight.
   /// The function determines which participant goes first and then calling
   /// "attack" and "updateHP" functions of player and enemy.
   /// \param[in] player object
   /// \param[in] enemy object

   void fight(player &p, enemy &e, screen &s);


  private:

   /// a vector of entities that stores a list of  participants in the battle.
   /// while there are only two participants in any given battle, this allows
   /// for scalability and simple management of entities consumed in battle.
   vector<entity*> participants;

   /// Turn function compares player and enemy HP to determine who goes first
   /// \param[in] player object
   /// \param[in] enemy object

   int turn(player &p, enemy &e);

   int currentTurn;

};

#endif
