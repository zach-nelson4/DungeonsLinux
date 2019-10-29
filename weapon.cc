/************************************************************
/// \Author Broderick Molcak
/// \Date November 24th 2017
/// This is the weapon class, and is used for defining and create weapon values
**********************************************************/

#include "player.h"
#include "weapon.h"

using namespace std;

///Creating weapon
weapon::weapon(const string &s, const int &i){
   tier = s;
   stat = i;
}

///Returns Weapons Name
string weapon::name(){
   return tier;
}

///Returns Wespons Stats
int weapon::getStat(){
   return stat;
}
///Destroys everything
weapon::~weapon(){   
}
