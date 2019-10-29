/*****************************************************************
/// \Author Zachary Nelson
/// \Date November 22nd 2017
/// This is the implementation file for the player class.
********************************************************************/

#include<iostream>
#include "screen.h"
#include "screenElement.h"
#include "player.h"
#include "item.h"
#include <string>

//Constructor with no given parameters
player::player(){
   HP = 0;
   ATK = 0;
   locationX = 0;
   locationY = 0;
}

//Constructor, takes in 4 ints. H = HP, A = ATK, X = row location, Y = collumn location
player::player(const int &h, const int &a, const int &x, const int &y){
   HP = h;
   ATK = a;
   locationX = x;
   locationY = y;
   wearingHelmet = false;
   wearingArmour = false;
   wearingSword = false;
}

//Destructor
player::~player(){
   HP = 0;
   ATK = 0;
   locationX = 0;
   locationY = 0;
   delete instance;
};

//getAtk function, returns the player's attack.
const int player::getATK(){
   return ATK;
}

//updateATK function, which updates the attack with the given value.
void player::updateATK(const int&i){
   ATK = i;
}

//Function to display the player's current inventory
void player::displayInventory(){
   for(unsigned int it; it < items.size(); ++it){
      cout << items[it].name() << endl;     
   }
   for(unsigned int it; it < weapons.size(); ++it){
      cout << weapons[it].name() << endl;
   }
}

//Draw function, which draws the player on the screen
void player::draw(screen &s){
   s.set(locationX, locationY, 'O');

}

//Equip function, which equips the toAdd armour to the player.
  void player::equip(armour toAdd){
   string iName = toAdd.name();
   char decide;
   cin.ignore();
   //Checks the name of the item to see if it is a helmet

   if(iName.find("Helmet") != string::npos){

      if(wearingHelmet == false){
	 items.push_back(toAdd);
	 this->updateHP(this->getHP() + toAdd.getStat());
	 cout << "You have equipped " << toAdd.name() << endl;
	 wearingHelmet = true;
	 return;
      }
      
      
      if(items.size() > 0){
	 //loops through the inventory array to search to see if you are already wearing a helmet
	 for(unsigned int i = 0; i < items.size(); i++){
	 
	    //If an item already has the name "Helmet"
	 
	    if((items[i].name()).find("Helmet") != string::npos){
	       cout << "You are already wearing a helmet (+" << items[i].getStat() << "HP)" << endl;
	       cout << "Would you like to swap it out with " << iName << "(+" << toAdd.getStat() << ")?" << endl;
	       cin >> decide;
	       
	       if(toupper(decide) == 'Y'){
		  this->updateHP(this->getHP() - items[i].getStat());
		  items[i] = toAdd;
		  this->updateHP(this->getHP() + toAdd.getStat());
		  cout << "You have equipped " << toAdd.name() << endl;
	       }
	       if(toupper(decide) == 'N'){
		  cout << "You have decided not to equip " << toAdd.name() << endl;
	       }
	    }
	 }
      }
   }
   /**************************************************************************************************/

   //Checks the name of the item to see if it is armour
   if(iName.find("Armour") != string::npos){

      if(wearingArmour == false){
	 items.push_back(toAdd);
	 this->updateHP(this->getHP() + toAdd.getStat());
	 cout << "You have equipped " << toAdd.name() << endl;
	 wearingArmour = true;
	 return;
      }

      	 if(items.size() > 0){
	    //loops through the inventory array to search to see if you are already wearing armour
	    for(unsigned int i = 0; i < items.size(); i++){
	       
	       //If an item already has the name "Armour"
	       
	       
	       if((items[i].name()).find("Armour") != string::npos){
		  cout << "You are already wearing armour (+" << items[i].getStat() << "HP)" << endl;
		  cout << "Would you like to swap it out with " << iName << "(+" << toAdd.getStat() << ")?" << endl;
		  cin >> decide;
		  
		  if(toupper(decide) == 'Y'){
		     this->updateHP(this->getHP() - items[i].getStat());
		     items[i] = toAdd;
		     this->updateHP(this->getHP() + toAdd.getStat());
 		     cout << "You have equipped " << toAdd.name() << endl;
		  }
		  if(toupper(decide) == 'N'){
		     cout << "You have decided not to equip " << toAdd.name() << endl;
		  }
	       }
	    }
	 }
   }
  }

//overwritten equip function which allows the player to equip a weapon.

void player::equip(weapon toAdd){
   string iName = toAdd.name();
   char decide;
   
   if(iName.find("Sword") != string::npos){

      if(wearingSword == false){
	 weapons.push_back(toAdd);
	 this->updateHP(this->getHP() + toAdd.getStat());
	 cout << "You have equipped " << toAdd.name() << endl;
	 wearingSword= true;
	 return;
      }

      if(weapons.size() > 0){
	 //loops through the inventory array to search to see if you are already wearing armour
	 for(unsigned int i = 0; i < weapons.size(); i++){

	    //If an item already has the name "Sword"


	    if((weapons[i].name()).find("Sword") != string::npos){
	       cout << "You are already using a Sword (+" << weapons[i].getStat() << "ATK)" << endl;
	       cout << "Would you like to swap it out with " << iName << "(+" << toAdd.getStat() << ")?" << endl;
	       cin >> decide;

	       if(toupper(decide) == 'Y'){
		  this->updateATK(this->getATK() - weapons[i].getStat());
		  weapons[i] = toAdd;
		  this->updateATK(this->getATK() + toAdd.getStat());
		  cout << "You have equipped " << toAdd.name() << endl;
	       }
	       if(toupper(decide) == 'N'){
		  cout << "You have decided not to equip " << toAdd.name() << endl;
	       }
	    }
	 }
      }
   }
}


player* player::instance = NULL;


//getInstance function, which allows only a single player to be created.
player* player::getInstance(){

   if(instance == NULL){
      instance = new player(100, 10, 10, 10);
      return instance;
   }

   else
      return instance;

}

