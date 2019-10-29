/****************************************************************
/// \Author Zachary Nelson
/// \Date November 22nd 2017

This is the implementation file for the enemy class.

*****************************************************************/

#include <iostream>
#include "player.h"
#include "screen.h"
#include "screenElement.h"
#include "entity.h"
#include "enemy.h"

///The constructor
enemy::enemy(const int &h, const int &d, const int &x, const int &y){
   HP = h;
   ATK = d;
   locationX = x;
   locationY = y;
}

///The destructor
enemy::~enemy(){
   HP = 0;
   ATK = 0;
   locationX = 0;
   locationY = 0;
}

///getATK function which returns the atk of the enemy
int enemy::getATK(){
   return ATK;
}

///draw function which draws the enemy on the screen
void enemy::draw(screen &s){
   s.set(locationX, locationY, 'X');
}

///enemyDamage function which damages the enemy
void enemy::enemyDamage(const int &i){
   this->updateHP(HP - i);
}

///enemyAttack function which allows the enemy to attack the player
void enemy::enemyAttack(player &p){
   p.updateHP(p.getHP() - ATK);
}

///Kill function which kills the enemy and moves them to a location the player
/// can never get to
void enemy::kill(screen &s){
   this->clear(s);
   HP = 0;
   locationX = 16;
   locationY = 26;
}

///Equality operator. Checks for equality.
bool enemy::operator==(enemy&e){
   if(this->locationX == e.getX() && this->locationY == e.getY())
      return true;
   else
      return false;
}
