/*****************************************************************************
/// \chest.cc
/// \author Darsh Thanki
/// \date Nov 22, 2017
///
///
/// The chest class is used to create a chest which contains instances of the
/// item class.
******************************************************************************/

#include "chest.h"
#include "weapon.h"
#include "armour.h"
#include "potion.h"
using namespace std;

chest::chest(const int &x, const int &y,armour* toAdd){

   locationX = x;
   locationY = y;
   armObj = toAdd;
   swoObj = NULL;
   potObj = NULL;
}

chest::chest(const int&x, const int &y,weapon* toAdd){
   locationX = x;
   locationY = y;
   swoObj = toAdd;
   armObj = NULL;
   potObj = NULL;
}

chest::chest(const int&x, const int &y,potion* toAdd){
   locationX = x;
   locationY = y;
   swoObj = NULL;
   armObj = NULL;
   potObj = toAdd;
}

chest::~chest(){

}


void chest::open(player &p){
   cin.ignore(); 
   if(potObj != NULL){
      potObj->use(p);
      cout << "You have used the potion! Your HP: " << p.getHP() << endl; 
   }
   
   if(armObj != NULL){
      cout << "Item in the chest: " << armObj->name() << "." << endl;
      cout << "Would you like to equip? Please enter Y or N ";
      
      char decision;
      
      cin >> decision;
      
      if (toupper(decision) == 'Y')
      {
	 p.equip(*armObj);
      }
      else{
	 
	 //do not equip. Display message.
	 cout << armObj->name() << " not equipped." <<endl;
      }
      
   }
   if(swoObj != NULL){
      cout << "Item in the chest: " << swoObj->name() << "." << endl;
      cout << "Would you like to equip? Please enter Y or N " << endl;
      
      char decision;
      
      cin >> decision;
      
      if (toupper(decision) == 'Y')
      {
	 p.equip(*swoObj);
      }
      else{

	 //do not equip. Display message.
	 cout << swoObj->name() << " not equipped." <<endl;
      }}
      
}

void chest::draw(screen &s){
    //draw the chest in the location.
    s.set(locationX, locationY, 'C');
}

void chest::move(const int &x, const int &y){
   locationX = x;
   locationY = y;
}

bool chest::operator==(chest c){
   if(locationX == c.getX() && locationY == c.getY())
      return true;
   else
      return false;
}

int chest::getX(){
   return locationX;
}

int chest::getY(){
   return locationY;
}
