/******************************************************************************
/// \Author Darsh Thanki
/// \Date November 7th 2017
/// This class is used to test the battle class by using CPPUNIT
****************************************************************************/

#ifndef BATTLE_TEST_H
#define BATTLE_TEST_H

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "battle.h"
#include "enemy.h"
#include "player.h"

/// Class used to test functionality of the  class

class battleTest:: public CppUnit::TestFixture{

   /// Macros used to create the test suite
   CPPUNIT_TEST_SUITE(battleTest);
   CPPUNIT_TEST(testBattleAction);
   CPPUNIT_TEST(testFight);
   CPPUNIT_TEST(testTurn);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp();
   void testBattleAction();
   void testFight();
   void testTurn();
   void tearDown();

  private:
   enemy* e;
   player* p;

};

#endif
