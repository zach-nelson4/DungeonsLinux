
/****************************************************************
\ entity.h
\ Author: Zachary Nelson
\ Date: October 26 2017
This is the .h file for the entity class, which both the player and the enemy classes derive from.

*****************************************************************/
#include <iostream>
#include "screen.h"
#include "screenElement.h"

#ifndef entity_h
#define entity_h

///The entity class is a base class which describes any sort of "living" being in the game.
///Both the player and the enemy classes derive from this class.

class entity: public screenElement{
  public:

   ///Default Constructor
   entity();
   
   ///Constructor
   /// \param[in] the h which is the HP of the entity
   /// \param[in] the a which is the attack/damage of the entity
   /// \param[in] the x of the location X
   /// \param[in] the y of the location y
   entity(const int &h, const int &a, const int &x, const int &y);

   ///Virtual destructor
   virtual ~entity();
   
   ///Updates the HP of the entity with the giving int Up (pos or neg)
   /// \param[in] the amount you wish to change the HP of the entity by
   void updateHP(const int &up);
   
  
   ///These two functions are used to get the current location of the entity's X and Y coordinates.
   ///For example, if you wish to call move and move the entity down one space, you would call
   ///(entity.getY())+1;
   /// \param[out] the current X of the entity
   const int getX();
   /// \param[out] the current Y of the entity
   const int getY();
   
   ///Allows you to move the entity by providing values of where to move it to.
   /// \param[in] the x and y which you want to move the entity to
   void move(const int &x, const int &y, screen &s);

   ///Clears the entity off of the screen
   /// \param[in] the screen for which to clear from
   void clear(screen &s);

   ///the getHP function, which returns the HP of the entity
   /// \return the int HP 
   const int getHP();
   
  protected:
   ///Ints for the Hp, the attack, and the location of the x and y of the entity.
   int HP, ATK, locationX, locationY;


};

#endif
