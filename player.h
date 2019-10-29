/*****************************************************
\Author: Zachary Nelson
\Date: October 21st 2017
This is the player class for the game "Dungeons Linux".
This class contains room area data and a vector of items for the inventory.
It can create the battle class, and it contains all of the player information.

*******************************************************/

#include<iostream>
#include<vector>
#include "screen.h"
#include "screenElement.h"
#include "entity.h"

#include "armour.h"
#include "weapon.h"

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class player: public entity{
  public:

   
   ///Destructor
   virtual ~player();

   ///This function is to be called when you wish to equip an armour
   /// \param[in] the armour which you want to equip
   void equip(armour toAdd);

   ///This function is called when you wish to equip a weapon. It is overwritten
   /// \param[in] in the weapon to equip
   void equip(weapon toAdd);
   
   ///This function is designed to return the current ATK of the player
   /// \return the attack of the player
   const int getATK();

   ///This function is designed to update the current ATK of the player
   /// \param[in] in the i for which you want to change the players atk to
   void updateATK(const int &i);
   
   ///This function is used to get an instance of the player class, as it is used in the singleton pattern.
   static player* getInstance();

   ///displays the player's inventory
   void displayInventory();

   ///draws the player on the screen
   ///\param[in] in the screen for which to draw on 
   void draw(screen &s);
   
  protected:
   ///The vector of items
   vector<armour> items;
   //Vector of weapons
   vector<weapon> weapons;
   ///The rest are inherited from the entity class

   player();

    ///Constructor for the player. Pass in the h (hp), the a (atk), the x(location x), and the y (location y)
   /// \param[in] the HP of the player
   /// \param[in] the attack power of the enemy
   /// \param[in] the x you want the player to be located at.
   /// \param[in] the y you want the player to be located at.
   player(const int &h, const int &a, const int &x, const int&y);
   
   static player* instance;

   bool instanceFlag;
   bool wearingArmour, wearingHelmet, wearingSword;
};

#endif
