/***************************************************************
/// \Author Zachary Nelson
/// \Date November 7th 2017
/// This program is used to test the player class using CPPUNIT
*********************************************************/

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "player.h"
#include "screen.h"
#include "weapon.h"
#include "armour.h"
#include "battle.h"

/// Class used to test functionality of the Player class

class playerTest: public CppUnit::TestFixture{

   /// Macros used to create the test suite
   CPPUNIT_TEST_SUITE(playerTest);
   CPPUNIT_TEST(testEquip);
   CPPUNIT_TEST(testStartBattle);
   CPPUNIT_TEST(testGetInstance);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp();
   void testEquip();
   void testStartBattle();
   void testGetInstance();
   void tearDown();

  private:
   screen* S;
   int ATK, HP;
   armour* I, I3;
   weapon* I2, I4;
   player* p;

};

#endif
   
