/*************************************************************
/// \Author Zachary Nelson
/// \Date November 22nd 2017
/// This is the implementation file for the entity class.
*************************************************************/

#include<iostream>
#include "entity.h"
#include "screen.h"
#include "screenElement.h"
#include <stdexcept>

//Defualt constructor
entity::entity(){
   HP = 0;
   ATK = 0;
   locationX = 0;
   locationY = 0;
}

//Constructor with given paramters. H = HP, A = Atk, X = Row, Y = collumn
entity::entity(const int &h, const int&a, const int &x, const int &y){
   HP = h;
   ATK = a;
   locationX = x;
   locationY = y;
}

entity::~entity(){
}

//Update HP function, which updates the HP to be the int up
void entity::updateHP(const int&up){
   HP = up;
}

//clear function, which clears the entity off of the screen
void entity::clear(screen &s){
   s.set(locationX, locationY, ' ');
}

//getX function, which returns the curretn row that the entity is in
const int entity::getX(){
   return locationX;
}

//getY function, which returns the current collumn the entity is in
const int entity::getY(){
   return locationY;
}

//move function, which moves the entity to the given location on the given screen
void entity::move(const int &x, const int &y, screen &s){
   
   
   if(s.at(x, y) == '-' || s.at(x, y) == '|')
	 cout << "You can't move that way." << endl;
   else{
      locationX = x;
      locationY = y;
   }
}

//getHP function, which returns the current HP of the entity
const int entity::getHP(){
   return HP;
}
