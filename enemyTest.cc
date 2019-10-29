/***********************************************************************
/// \Author Zachary Nelson
/// \Date November 7th 2017
/// This is the implementation file used for the enemyTest, which is used by
/// CPPUNIT to test the enemy class.
***********************************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "enemyTest.h"
#include "enemy.h"
#include "player.h"

///creating some variables to test with
void enemyTest::setUp(){
   e = new enemy(10, 10, 10, 10);
   p = new player(10, 10, 10, 10);
}

///Removes everything to avoid memory leaks
void enemyTest::tearDown(){
   delete e;
   delete p;
}

///This function is used to test to make sure that by calling the enemyDamage
///function, it successfully damages the enemy. By calling with an attack of 5,
///It should lower the enemy's HP to 5.
void enemyTest::testEnemyDamage(){
   e->enemyDamage(5);
   CPPUNIT_ASSERT(e.getHP() == 5);
  
}

///This assertion is used to test to make sure that the enemy has successfully
///damaged the player. As the player's HP is 10, by damaging it with an attack of 5,
///This should lower the player's HP to 5.
void enemyTest::testEnemyAttack(){
   e->enemyDamage(p);
   CPPUNIT_ASSERT(p.getHP() == 5);

}

///This assertion is designed to check to make sure that the enemy is succesfully
///killed when it's HP is 0.
void enemyTest::testKill(){
   e->kill();
   /// Makes sure that the HP is set to 0
   CPPUNIT_ASSERT(e.getHP() == 0);
   /// Makes sure that the enemy has been relocated to an area unreachable by the player
   CPPUNIT_ASSERT(e.getX() == 0);
   CPPUNIT_ASSERT(e.getY() == 0);
}
