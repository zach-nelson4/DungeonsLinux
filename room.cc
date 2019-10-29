/****************************************************************************
/// \Author Zachary Nelson
/// \Date November 22nd 2017
/// This is the implementation file for the room class
*****************************************************************************/

#include "room.h"
#include <iostream>
#include "screen.h"
#include "enemy.h"
#include "player.h"
#include "chest.h"
#include "battle.h"

room::room(const bool &north, const bool &east, const bool &south, const bool &west, screen &s){

   North = north;
   East = east;
   South = south;
   West = west;
   
   //Creating the walls of the room
   
   for(int i = 0; i < s.getColumns(); i++){
      s.set(0, i, '-');
      s.set(s.getRows()-1, i, '-');
   }
   for(int i = 0; i < s.getRows(); i++){
      s.set(i, 0, '|');
      s.set(i, s.getColumns()-1, '|');
   }

   //Setting the corners to '+' 
   s.set(0, 0, '+');
   s.set(0, s.getColumns()-1, '+');
   s.set(s.getRows()-1, 0, '+');
   s.set(s.getRows()-1, s.getColumns()-1, '+');

   //Setting a door on the north side
   if(north == true){
	 s.set(0, s.getColumns()/2, ' ');
	 s.set(0, s.getColumns()/2+1, '|');
	 s.set(0, s.getColumns()/2-1, '|');
   }

   //Setting a door on the east side
   if(east == true){
      s.set(s.getRows()/2, s.getColumns()-1, ' ');
      s.set(s.getRows()/2+1, s.getColumns()-1, '-');
      s.set(s.getRows()/2-1, s.getColumns()-1, '-');
   }

   //Setting a door on the south side
   if(south == true){
      s.set(s.getRows()-1, s.getColumns()/2, ' ');
      s.set(s.getRows()-1, s.getColumns()/2+1, '|');
      s.set(s.getRows()-1, s.getColumns()/2-1, '|');
   }

   //Setting a door on the west side
   if(west == true){
      s.set(s.getRows()/2, 0, ' ');
      s.set(s.getRows()/2+1, 0, '-');
      s.set(s.getRows()/2-1, 0, '-');
   }

   for(unsigned i = 0; i < things.size(); i++){
      things[i].draw(s);
   }
}

room::~room(){
}

///Clears everything from the room
void room::clear(screen &s){
      for(int i = 0; i < s.getColumns(); i++){
      s.set(0, i, ' ');
      s.set(s.getRows()-1, i, ' ');
   }
   for(int i = 0; i < s.getRows(); i++){
      s.set(i, 0, ' ');
      s.set(i, s.getColumns()-1, ' ');
   }
}

void room::addEnemy(const enemy &e){
   things.push_back(e);
}

void room::addChest(chest* c){
   chests.push_back(*c);
}

void room::redraw(screen &s){

   //Creating the walls of the room
   
   for(int i = 0; i < s.getColumns(); i++){
      s.set(0, i, '-');
      s.set(s.getRows()-1, i, '-');
   }
   for(int i = 0; i < s.getRows(); i++){
      s.set(i, 0, '|');
      s.set(i, s.getColumns()-1, '|');
   }

   //Setting the corners to '+' 
   s.set(0, 0, '+');
   s.set(0, s.getColumns()-1, '+');
   s.set(s.getRows()-1, 0, '+');
   s.set(s.getRows()-1, s.getColumns()-1, '+');

   //Setting a door on the north side
   if(North == true){
	 s.set(0, s.getColumns()/2, ' ');
	 s.set(0, s.getColumns()/2+1, '|');
	 s.set(0, s.getColumns()/2-1, '|');
   }

   //Setting a door on the east side
   if(East == true){
      s.set(s.getRows()/2, s.getColumns()-1, ' ');
      s.set(s.getRows()/2+1, s.getColumns()-1, '-');
      s.set(s.getRows()/2-1, s.getColumns()-1, '-');
   }

   //Setting a door on the south side
   if(South == true){
      s.set(s.getRows()-1, s.getColumns()/2, ' ');
      s.set(s.getRows()-1, s.getColumns()/2+1, '|');
      s.set(s.getRows()-1, s.getColumns()/2-1, '|');
   }

   //Setting a door on the west side
   if(West == true){
      s.set(s.getRows()/2, 0, ' ');
      s.set(s.getRows()/2+1, 0, '-');
      s.set(s.getRows()/2-1, 0, '-');
   }

   
   for(unsigned i = 0; i < things.size(); i++){
      things[i].draw(s);
   }
   for(unsigned int i = 0; i < chests.size(); i++){
      chests[i].draw(s);
   }
}


///Kills an enemy in the room
void room::kill(enemy e, screen &s){

   for(unsigned i = 0; i < things.size(); i++){
      if(things[i] == e)
	 things[i].move(e.getX(), 16, s );
   }
}

///Kills a chest in the room
void room::kill(chest c, screen &s){

   for(unsigned i = 0; i < chests.size(); i++){
      if(chests[i] == c)
	 chests[i].move(0, 26);
   }
}

///Checks for a collision between a player and anything in the room
void room::checkForCollision(player &p, screen &s){
   for(unsigned int i = 0; i < things.size(); ++i){
      if(p.getX() == things[i].getX() && p.getY() == things[i].getY()){
	 battle b;
	 this->displayEnemy();
	 if(b.battleAction() == true){
	    b.fight(p, things[i], s);
	 }
	 else{
	    p.move(p.getX()+1, p.getY(), s);
	    p.draw(s);
	    this->redraw(s);
	    cout << s;
	 }
      }
   }
   for(unsigned int i = 0; i < chests.size(); ++i){
      if(p.getX() == chests[i].getX() && p.getY() == chests[i].getY()){
	 this->displayChest();
	 chests[i].open(p);
	 this->kill(chests[i], s);
      }
   }
}

///displays an enemy with ascii
void room::displayEnemy(){

    

   
   cout << "   ^   ^ " << endl;
   cout << "  (o|_|o)" << endl;
   cout << "   (. .) " << endl;			\
   cout << "  =(_T_)=   __ " << endl;
   cout << "   (   )   (   " << endl;
   cout << "  ((   ))   )  " << endl;
   cout << "  ()) (()  /   " << endl;
   cout << "  (  Y  )-'    " << endl;
   cout << "   nn^nn       " << endl;
}

///displays a chest with ascii characters
void room::displayChest(){
   
   cout<<"                         _.--. " << endl;
   cout<<"                     _.-'_:-'|| " << endl;
   cout<<"                 _.-'_.-::::'|| " << endl;
   cout<<"            _.-:'_.-::::::'  || " << endl;
   cout<<"          .'`-.-:::::::'     || " << endl;
   cout<<"         /.'`;|:::::::'      ||_" << endl;
   cout<<"        || ||::::::'     _.;._'-._" << endl;
   cout<<"        ||   ||:::::'  _.-!oo @.!-._'-." << endl;
   cout<<"         \'.  ||:::::.-!()oo @!()@.-'_.|" << endl;
   cout<<"          '.'-;|:.-'.&$@.& ()$%-'o.'|U||" << endl;
   cout<<"            `>'-.!@%()@'@_%-'_.-o _.|'||" << endl;
   cout<<"             ||-._'-.@.-'_.-' _.-o  |'||" << endl;
   cout<<"             ||=[ '-._.-|U/.-'    o |'||" << endl;
   cout<<"             || '-.]=|| |'|      o  |'||" << endl;
   cout<<"             ||      || |'|        _| ';" << endl;
   cout<<"             ||      || |'|    _.-'_.-'" << endl;
   cout<<"             |'-._   || |'|_.-'_.-'" << endl;
   cout<<"             '-._'- .|| |' `_.-'" << endl;
   cout<<"                 '-. ||_/.-'" << endl;

}
