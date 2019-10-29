/*****************************************************************************
/// \chest.h
/// \author Darsh Thanki
/// \date Oct 26, 2017
///
///
/// The chest class is used to create a chest which contains instances of the
/// item class.

******************************************************************************/

#ifndef CHEST_H
#define CHEST_H

#include<iostream>
#include<vector>
#include "item.h"
#include "armour.h"
#include "weapon.h"
#include "potion.h"
#include "player.h"

using namespace std;

class chest{
  public:


   /// Constructor
   chest(const int &x, const int &y,armour* toAdd);
   chest(const int &x, const int &y, weapon* toAdd);
   chest(const int &x, const int &y, potion* toAdd);
   
   ///Destructor of the chest class
   ~chest();

   /// open chest function creates an item object, sets its creation values,
   /// and adds pointer to menu
   /// \param[in] item contained within the chest
   void open(player &p);
   
   /// void function that will draw the chest on the screen.
   /// \param[in] screen instance
   void draw(screen &s);

   /// moves the chest to the given location
   /// \param[in] the location of the X you want to move the chest to
   /// \param[in] the location of the Y you want to move the chest to
   void move(const int &X, const int &Y);

   /// equality operator. Determines if the chests are equal
   /// \param[in] in the chest which to compare to
   bool operator==(chest c);

   /// getX function which returns the X of the function
   /// \return the X of the chest
   int getX();

   /// getY function which returns the Y of the function
   /// \return the Y of the chest
   int getY();
   
  private:


   /// item variable that holds item object stored in the chest
   armour* armObj;
   weapon* swoObj;
   potion* potObj;
   int locationX;
   int locationY;
};

#endif
