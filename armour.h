/*****************************************************************************
/// \author Broderick Molcak
/// \date Oct 25, 2017
///
///
/// The armour class is a class that passes tier and stats of armour found
/// throughout gameplay
******************************************************************************/

#ifndef ARMOUR_H
#define ARMOUR_H

#include <iostream>
#include "item.h"
using namespace std;

class armour: public item{
	protected:
		string tier;
		int stat;
	public:	
	        ///Constructs a armour object from the given stats
		armour(const string &s, const int &i);
		
   		///Destroys the object
		virtual ~armour();

		///Returns the name of the item
		string name();

		///Returns the state amount of the item
		int getStat();
};

#endif
