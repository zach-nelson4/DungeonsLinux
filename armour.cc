
/************************************************************
/// \Author Broderick Molcak
/// \Date November 25th 2017
/// This is the armour class, and is used for defining and create armour values
**********************************************************/

#include "armour.h"
#include "player.h"

using namespace std;

///Creating armour
armour::armour(const string &s, const int &i){
   tier = s;
   stat = i;   
}

//Returns Armour Name
string armour::name(){
   return tier;
}

///REturns Armour Stat
int armour::getStat(){
   return stat;
}
///Destroys everything
armour::~armour(){   
}
