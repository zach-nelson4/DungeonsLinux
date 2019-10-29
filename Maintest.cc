//Testing main

#include <iostream>
#include "screen.h"
#include "room.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "item.h"
#include "armour.h"
#include "chest.h"
#include "battle.h"
#include "worldClass.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void startScreen(worldClass* W);
void youWin();
void playRoom1(worldClass* W, screen &s, room* currentRoom, player* P);
void playRoom2(worldClass* W, screen &s, room* currentRoom, player* P);
void playRoom3(worldClass* W, screen &s, room* currentRoom, player* P);
void playRoom4(worldClass* W, screen &s, room* currentRoom, player* P);
void playRoom5(worldClass* W, screen &s, room* currentRoom, player* P);
void playRoom6(worldClass* W, screen &s, room* currentRoom, player* P);
void playRoom7(worldClass* W, screen &s, room* currentRoom, player* P);

int main(){

   screen* S;
   S = new screen(15, 25);
   S->clear();

   worldClass* W;
   W = new worldClass(*S);

   room* currentRoom;
   currentRoom = new room(true, true, true, true, *S);

   player* P = W->spawnPlayer();
   W->buildRooms(*S);
   W->buildEnemies(*S);
   W->buildChests(*S);
   startScreen(W);
     
   P->draw(*S);
   playRoom1(W, *S, currentRoom, P);


   return 0;
}

void startScreen(worldClass* W){
   char decide;
   
   cout << " _____" << endl;
   cout << "|     |_ _ ___ ___ ___ ___ _______ " << endl;
   cout << "|  |  | | |   | . | -_| . |   |_ -|" << endl;
   cout << "|____/|___|_|_|_  |___|___|_|_|___|" << endl;
   cout << "              |___|                " << endl;
   cout << "               __    _             " << endl;
   cout << "              |  |  |_|___ _ _ _ _ " << endl;
   cout << "              |  |__| |   | | |_'_|" << endl;
   cout << "              |_____|_|_|_|___|_,_|" << endl;
   cout << "  _________________________________" << endl;
   cout << " /________________________________/" << endl;

   cout << "Dungeons Linux, by Zach Nelson, Darsh Thanki, Jared Sisco," << endl;
   cout << "Broderick Molcax, and Nathan _____." << endl;
   cout << endl;
   cout << "You, a lone adventurer, find yourself trapped deep within a dungeon." << endl;
   cout << "Your only escape is to find your way through the maze, and battle the many monsters inside" << endl;
   cout << "You can find Helmets, Armours, and Swords to help you along the way." << endl;
   cout << endl;
   cout << "N for new game" << endl;
   do{
      cin >> decide;

      if(decide == 'N')
	 cout << "You have selected to start a new game. " << endl;

   }while(decide != 'N');

return;
}

void playRoom1(worldClass* W, screen &s, room* currentRoom, player* P){
   currentRoom = W->switchRoom(0);
   currentRoom->redraw(s);
   char moveAround;
   P->draw(s);
   W->displayMenu();
   do{

      cout << s << endl;
      cin >> moveAround;

      if(moveAround == 'Q'){
	 exit(EXIT_FAILURE);
      }
      
      P->clear(s);

      if(moveAround == 'W')
	 P->move(P->getX()-1, P->getY(), s);

      if(moveAround == 'A')
	 P->move(P->getX(), P->getY()-1, s);

      if(moveAround == 'S')
	 P->move(P->getX()+1, P->getY(), s);

      if(moveAround == 'D')
	 P->move(P->getX(), P->getY()+1, s);

      currentRoom->redraw(s);
      
      currentRoom->checkForCollision(*P, s);

      P->draw(s);
      
      if(P->getX() == 0 && P->getY() == 13){
	 s.clear();
	 P->move(13, 13, s);
	 playRoom2(W, s, currentRoom, P);
      }
      cin.ignore();
   }while(moveAround != 'Q');
}

void playRoom2(worldClass* W, screen &s, room* currentRoom, player* P){
   
   currentRoom = W->switchRoom(1);
   currentRoom->redraw(s);
   P->draw(s);
   char moveAround;
   W->displayMenu();
   do{

      cout << s << endl;
      cin >> moveAround;

      if(moveAround == 'Q'){
	 exit(EXIT_FAILURE);
      }
      

      P->clear(s);
      if(moveAround == 'W')
	 P->move(P->getX()-1, P->getY(), s);

      if(moveAround == 'A')
	 P->move(P->getX(), P->getY()-1, s);

      if(moveAround == 'S')
	 P->move(P->getX()+1, P->getY(), s);

      if(moveAround == 'D')
	 P->move(P->getX(), P->getY()+1, s);

      currentRoom->redraw(s);
      P->draw(s);
      
      currentRoom->checkForCollision(*P, s);

      P->draw(s);

      //Moves player to room 1
      if(P->getX() == 14 && P->getY() == 13){
	 P->move(1, 13, s);
	 playRoom1(W, s, currentRoom, P);
	 
      }
      //Moves player to room 3
      if(P->getX() == 7 && P->getY() == 0){
	 s.clear();
	 P->move(7, 24, s);
	 playRoom3(W, s, currentRoom, P);
      }

      //Moves player to room 4
      if(P->getX() == 7 && P->getY() == 25){
	 s.clear();
	 P->move(7, 1, s);
	 playRoom4(W, s, currentRoom, P);
      }
      cin.ignore();
   }while(moveAround != 'Q');
}

///Player is in room 3

void playRoom3(worldClass* W, screen &s, room* currentRoom, player* P){
   
   currentRoom = W->switchRoom(2);
   s.clear();
   currentRoom->redraw(s);
   P->draw(s);
   char moveAround;
   W->displayMenu();
   do{
      
      cout << s << endl;
      cin >> moveAround;

      if(moveAround == 'Q'){
	 exit(EXIT_FAILURE);
      }
      
      
      P->clear(s);
      if(moveAround == 'W')
	 P->move(P->getX()-1, P->getY(), s);

      if(moveAround == 'A')
	 P->move(P->getX(), P->getY()-1, s);

      if(moveAround == 'S')
	 P->move(P->getX()+1, P->getY(), s);

      if(moveAround == 'D')
	 P->move(P->getX(), P->getY()+1, s);

      currentRoom->redraw(s);
      P->draw(s);
      
      currentRoom->checkForCollision(*P, s);

      P->draw(s);

      //Move to room 2
      if(P->getX() == 7 && P->getY() == 25){
	 P->move(7, 1, s);
	 playRoom2(W, s, currentRoom, P);
	 
      }
      cin.ignore();
   }while(moveAround != 'Q');
}

//Player is in room 4

void playRoom4(worldClass* W, screen &s, room* currentRoom, player* P){
   
   currentRoom = W->switchRoom(3);
   s.clear();
   currentRoom->redraw(s);
   P->draw(s);
   char moveAround;
   W->displayMenu();
   
   do{
      
      cout << s << endl;
      cin >> moveAround;

      if(moveAround == 'Q'){
	 exit(EXIT_FAILURE);
      }
      
      
      P->clear(s);
      if(moveAround == 'W')
	 P->move(P->getX()-1, P->getY(), s);

      if(moveAround == 'A')
	 P->move(P->getX(), P->getY()-1, s);

      if(moveAround == 'S')
	 P->move(P->getX()+1, P->getY(), s);

      if(moveAround == 'D')
	 P->move(P->getX(), P->getY()+1, s);

      currentRoom->redraw(s);
      P->draw(s);
      
      currentRoom->checkForCollision(*P, s);

      P->draw(s);

      //Move to room 2
      if(P->getX() == 7 && P->getY() == 0){
	 P->move(7, 24, s);
	 playRoom2(W, s, currentRoom, P);
	 
      }
      //Move to room 5
      if(P->getX() == 0 && P->getY() == 13){
	 P->move(13, 13, s);
	 playRoom5(W, s, currentRoom, P);
      }
      cin.ignore();
   }while(moveAround != 'Q');
}

//Player is in room 5

void playRoom5(worldClass* W, screen &s, room* currentRoom, player* P){
   
   currentRoom = W->switchRoom(4);
   s.clear();
   currentRoom->redraw(s);
   P->draw(s);
   char moveAround;
   W->displayMenu();
   do{
      
      cout << s << endl;
      cin >> moveAround;

      if(moveAround == 'Q'){
	 exit(EXIT_FAILURE);
      }
      
      
      P->clear(s);
      if(moveAround == 'W')
	 P->move(P->getX()-1, P->getY(), s);

      if(moveAround == 'A')
	 P->move(P->getX(), P->getY()-1, s);

      if(moveAround == 'S')
	 P->move(P->getX()+1, P->getY(), s);

      if(moveAround == 'D')
	 P->move(P->getX(), P->getY()+1, s);

      currentRoom->redraw(s);
      P->draw(s);
      
      currentRoom->checkForCollision(*P, s);

      P->draw(s);

      //Move to room 4
      if(P->getX() == 14 && P->getY() == 13){
	 P->move(1, 13, s);
	 playRoom4(W, s, currentRoom, P);
      }
      //Move to room 6
      if(P->getX() == 7 && P->getY() == 25){
	 P->move(7, 1, s);
	 playRoom6(W, s, currentRoom, P);
      }
      //Move to room 7
      if(P->getX() == 7 && P->getY() == 0){
	 P->move(7, 24, s);
	 playRoom7(W, s, currentRoom, P);
      }
      cin.ignore();
   }while(moveAround != 'Q');
}

//Player is in room 6

void playRoom6(worldClass* W, screen &s, room* currentRoom, player* P){
   
   currentRoom = W->switchRoom(5);
   s.clear();
   currentRoom->redraw(s);
   P->draw(s);
   char moveAround;
   W->displayMenu();
   do{
      
      cout << s << endl;
      cin >> moveAround;

      if(moveAround == 'Q'){
	 exit(EXIT_FAILURE);
      }
      
      
      P->clear(s);
      if(moveAround == 'W')
	 P->move(P->getX()-1, P->getY(), s);

      if(moveAround == 'A')
	 P->move(P->getX(), P->getY()-1, s);

      if(moveAround == 'S')
	 P->move(P->getX()+1, P->getY(), s);

      if(moveAround == 'D')
	 P->move(P->getX(), P->getY()+1, s);

      currentRoom->redraw(s);
      P->draw(s);
      
      currentRoom->checkForCollision(*P, s);

      P->draw(s);

      //Move to room 5
      if(P->getX() == 7 && P->getY() == 0){
	 P->move(7, 24, s);
	 playRoom5(W, s, currentRoom, P);
	 
      }
      cin.ignore();
   }while(moveAround != 'Q');
}

//Player is in room 7

void playRoom7(worldClass* W, screen &s, room* currentRoom, player* P){
   
   currentRoom = W->switchRoom(6);
   s.clear();
   currentRoom->redraw(s);
   P->draw(s);
   char moveAround;
   W->displayMenu();
   do{
      cout << s << endl;
      cin >> moveAround;

      if(moveAround == 'Q'){
	 exit(EXIT_FAILURE);
      }
      
      
      P->clear(s);
      if(moveAround == 'W')
	 P->move(P->getX()-1, P->getY(), s);

      if(moveAround == 'A')
	 P->move(P->getX(), P->getY()-1, s);

      if(moveAround == 'S')
	 P->move(P->getX()+1, P->getY(), s);

      if(moveAround == 'D')
	 P->move(P->getX(), P->getY()+1, s);

      currentRoom->redraw(s);
      P->draw(s);
      
      currentRoom->checkForCollision(*P, s);

      cout << endl;
      cout << endl;

      P->draw(s);

      //Move to room 5
      if(P->getX() == 7 && P->getY() == 25){
	 P->move(7, 1, s);
	 playRoom5(W, s, currentRoom, P);
	 
      }
      //Finish game
      if(P->getX() == 7 && P->getY() == 0){
	 youWin();
	 exit(EXIT_FAILURE);
      }
      cin.ignore();
   }while(moveAround != 'Q');
}

void youWin(){

   cout << "    __   __  _______  __   __    _     _  ___   __    _  __ " << endl; 
   cout << "   |  | |  ||       ||  | |  |  | | _ | ||   | |  |  | ||  |" << endl; 
   cout << "   |  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| ||  |" << endl; 
   cout << "   |       ||  | |  ||  |_|  |  |       ||   | |       ||  |" << endl; 
   cout << "   |_     _||  |_|  ||       |  |       ||   | |  _    ||__|" << endl; 
   cout << "     |   |  |       ||       |  |   _   ||   | | | |   | __ " << endl; 
   cout << "     |___|  |_______||_______|  |__| |__||___| |_|  |__||__|" << endl;


}
