/*****************************************************************************
/// \author Broderick Molcak
/// \date Oct 20, 2017
///
///
/// The Item class is a class that allows for the obtaining of item stats 
/// which players obtain throughout the game
******************************************************************************/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

/// The Item class provides functions to draw stats for equiptable items

class item{
  protected:

   
public:
	
   virtual string name() = 0;
};


#endif
