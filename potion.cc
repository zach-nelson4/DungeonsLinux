/************************************************************
/// \Author Broderick Molcak
/// \Date November 24th 2017
/// This is the potion class, and is used for defining and create potion values
**********************************************************/

#include "player.h"
#include "potion.h"

using namespace std;

///Creating weapon
potion::potion(const string &s,const int &i){
   tier = s;
   stat = i;
}

void potion::use(player &p){
   p.updateHP(p.getHP() + stat);
}

///Returns Potion Name
string potion::name(){
   return tier;
}

///REturns Potion Stat
int potion::getStat(){
   return stat;
}
///Destroys everything
potion::~potion(){   
}
