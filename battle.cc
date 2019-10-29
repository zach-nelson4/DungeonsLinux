/*****************************************************************************
/// \battle.cc
/// \author Darsh Thanki
/// \date Nov 22, 2017
///
///
/// The Battle class is a class that determines turns of battle, damage dealt to
/// enemies and the player. Additionally, the class allows the menu class to
/// display/execute different options such as fight or run.
******************************************************************************/

#include "battle.h"
#include "entity.h"
#include "room.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>//used for random attack point calculation.
using namespace std;

battle::battle(){
//battle* thisBattle = new battle();
    currentTurn = 0;
}

battle::~battle(){

}

bool battle::battleAction(){
    char action;

askagain:
    cout << "Will you fight Fight (F) or Run (R)?" << endl << "action: ";
    cin >> action;

    if(toupper(action) == 'F')
      return true;
    else if(toupper(action) == 'R')
      return false;
    else
    {
       cout << "Invalid input, please enter either F to fight or R to run." << endl;
      goto askagain;
    }
}

void battle::fight(player &p, enemy &e, screen &s){

    srand(time(0));
//int pAttackAmt = rand()%(p.getATK()-1 + 1) + 1;
//  int eAttackAmt = e.getATK();
    int entityTurn;

    if(currentTurn == 0){
        entityTurn = this->turn(p, e);
        currentTurn++; //increment the turn.
    }

//attack and update stats for each entity

do{

int pAttackAmt = rand()%(p.getATK()-1 + 1) + 1;
int eAttackAmt = rand()%(e.getATK()-1 + 1) + 1;
      if(entityTurn == 1){

          e.updateHP(e.getHP() - pAttackAmt);
          entityTurn = 2;
          cout << "You attacked the enemy. You dealt " << pAttackAmt << " damage." << endl;
          cout << "Enemy HP is now: " << e.getHP() << endl;
          currentTurn++;
      }
      else{
          p.updateHP(p.getHP() - eAttackAmt);
          entityTurn = 1;
          cout << "The enemy attacked you. They dealt " << pAttackAmt << " damage." << endl;
          cout << "Your HP is now: " << p.getHP() << endl;
          currentTurn++;
}
}
    while ((p.getHP() > 0) && (e.getHP() > 0)); //Continue loop till someone dies.

    if(p.getHP() <= 0){
cout << "Game over." << endl;
// -> !! Game over function goes here. !!
exit(EXIT_FAILURE);
	}
if(e.getHP() <= 0){
cout << "You have defeated the enemy!" << endl;
        e.kill(s);
    }
}


// Decide who gets to go first. The entity with the lowest HP goes first.
int battle::turn(player &p, enemy &e){
    if (p.getHP() < e.getHP())
      return 1;
    else
      return 2;
}
