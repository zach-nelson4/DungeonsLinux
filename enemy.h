/******************************************************************
\ Author: Zachary Nelson
\ Date: October 21st 2017

This is the enemy class for the game "Dungeons Linux". It contains data for
the enemies.

***************************************************************/


#include <iostream>
#include "player.h"
#include "screen.h"
#include "screenElement.h"
#include "entity.h"

#ifndef ENEMY_H
#define ENEMY_H

/// The enemy class describes any enemy in the game and is derived from the entity class.
class enemy: public entity{
  public:

   ///This is the constructor for the enemy class. Pass in the h (HP and the d (DMG)
   /// \param[in] the HP
   /// \param[in] the damage/attack power of the enemy
   /// \param[in] the X which you want the enemy to be located at
   /// \param[in] the Y which you want the enemy to be located at
   enemy(const int &h, const int& d, const int&x, const int&y);

   ///This is the destructor for the enemy class.
   ~enemy();

   ///This function is designed to allow the enemy to take damage from the player.
   /// \param[in] the amount of damage you wish to be done
   void enemyDamage(const int &i);
   
   ///This function is used by the Battle class to cause the enemy to attack the player.
   /// \param[in] the player which you want to attack
   void enemyAttack(player &p);

   ///This function is used to kill the enemy.
   ///\param[in] the screen for which to remove the enemy from
   void kill(screen &s);

   ///The draw function draws the player on the screen
   ///\param[in] in the screen for which to draw on
   void draw(screen &s);

   ///The equality operator
   ///\param[in] in the enemy which you want to compare to
   bool operator==(enemy &e);

   ///The getATK function
   /// \return the ATK of the enemy
   int getATK();
      
  private:
   ///All of the private members are inherited from entity

};

#endif
