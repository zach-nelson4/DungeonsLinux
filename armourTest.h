/***************************************************************
/// \Author Broderick Molcak
/// \Date November 7th 2017
/// This program is used to test the armour class using CPPUNIT
*********************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#ifndef ARMOUR_TEST_H
#define ARMOUR_TEST_H

#include "player.h"
#include "armour.h"

/// Class used to test the armour class

class armourTest: public CppUnit::TestFixture{

   /// Macros used to create the test suite
   CPPUNIT_TEST_SUITE(armourTest);
   CPPUNIT_TEST(testEquip);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp();
   void testEquip();
   void tearDown();

  private:
   int ATK, HP;
   armour* A, A2, A3, A4, A5, A6, A7, A8;
   player* p;

};

#endif
