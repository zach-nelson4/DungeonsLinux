/*****************************************************************************
/// \author Broderick Molcak
/// \date Oct 25, 2017
///
///
/// The potion class is a class that passes tier and stats of potions found
/// throughout gameplay
******************************************************************************/

#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "player.h"
#include <iostream>
using namespace std;

class potion : public item {
	protected:
		string tier;
		int stat;
	public:	
	        ///constructs a potion object from the given stats
		potion(const string &s, const int &i);

                ///Destroys the object
		virtual ~potion();

		///Returns the name of the item
		string name();

		///Returns the state amount of the item
		int getStat();
		

		void use(player &p);
};

#endif
