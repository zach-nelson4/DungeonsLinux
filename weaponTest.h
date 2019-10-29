/***************************************************************
/// \Author Broderick Molcak
/// \Date November 7th 2017
/// This program is used to test the weapon class using CPPUNIT
*********************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#ifndef WEAPON_TEST_H
#define WEAPON_TEST_H

#include "player.h"
#include "weapon.h"

/// Class used to test the weapon class

class weaponTest: public CppUnit::TestFixture{

   /// Macros used to create the test suite
   CPPUNIT_TEST_SUITE(weaponTest);
   CPPUNIT_TEST(testEquip);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp();
   void testEquip();
   void tearDown();

  private:
   int ATK, HP;
   weapon* W, W2, W3, W4, W5, W6, W7, W8;
   player* p;

};

#endif
