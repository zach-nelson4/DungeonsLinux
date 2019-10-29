/******************************************************************************
/// \Author Zachary Nelson
/// \Date November 7th 2017
/// This class is used to test the enemy class by using CPPUNIT
****************************************************************************/

#ifndef ENEMY_TEST_H
#define ENEMY_TEST_H

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "enemy.h"
#include "screen.h"
#include "player.h"

/// Class used to test functionality of the enemy class

class enemyTest:: public CppUnit::TestFixture{

   /// Macros used to create the test suite
   CPPUNIT_TEST_SUITE(enemyTest);
   CPPUNIT_TEST(testEnemyDamage);
   CPPUNIT_TEST(testEnemyAttack);
   CPPUNIT_TEST(testKill);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp();
   void testEnemyDamage();
   void testEnemyAttack();
   void testKill();
   void tearDown();

  private:
   enemy* e;
   player* p;

};

#endif
