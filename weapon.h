/*****************************************************************************
/// \author Broderick Molcak
/// \date Oct 25, 2017
///
///
/// The weapon class is a class that passes tier and stats of weapons found
/// throughout gameplay
******************************************************************************/

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "item.h"
using namespace std;

class weapon : public item{
	protected:
		string tier;
		int stat;
	public:	
	        ///Constructs a weapon object from the given stats
		weapon(const string &s, const int &i);
		
   		///Destroys the object
		virtual ~weapon();
		
		///Returns the name of the item
		string name();

		///Returns the state amount of the item
		int getStat();
};

#endif
