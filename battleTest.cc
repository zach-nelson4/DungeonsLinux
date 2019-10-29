/***********************************************************************
/// \Author Darsh Thanki
/// \Date November 7th 2017
/// This is the implementation file used for the battleTest,
/// which is used by CPPUNIT to test the battle class.
***********************************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "battleTest.h"
#include "battle.h"
#include "player.h"

///creating some variables to test with
void battleTest::setUp(){
   e = new enemy(7, 2, 10, 10);
   p = new player(10, 10, 10, 10);

   vector<entity*> battleParticipants;

   battleParticipants.push_back(e);
   battleParticipants.push_back(p);

   b = new battle(battleParticipants);

}

///Removes everything to avoid memory leaks
void battleTest::tearDown(){
   delete e;
   delete p;
   delete b;
}

///This function is used to test to make sure that by calling the battleAction
void battleTest::testBattleAction(){
   b->battleAction(true);
   //not sure how to validate

}

/// This assertion is used to test the outcome of the fight.
/// Given that enemy has 7HP, it should die since player has an
/// attack of 10.
void battleTest::testFight(){
    b->fight(p, e);
    test_cin("a") //user enters a to attack. Should kill enemy
    CPPUNIT_ASSERT(e.getHP() == 0);
}

/// This assertion is used to test to make sure that the enemy goes first
/// in the battle because they have lower health.
void battleTest::testTurn(){
   CPPUNIT_ASSERT(b->turn(p,e) == e);
}
