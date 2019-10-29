/***************************************************************
/// \Author Broderick Molcak
/// \Date November 7th 2017
/// This program is used to test the potion class using CPPUNIT
*********************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#ifndef POTION_TEST_H
#define POTION_TEST_H

#include "player.h"
#include "potion.h"

/// Class used to test the potion class

class potionTest: public CppUnit::TestFixture{

   /// Macros used to create the test suite
   CPPUNIT_TEST_SUITE(potionTest);
   CPPUNIT_TEST(testUse);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp();
   void testUse();
   void tearDown();

  private:
   int ATK, HP;
   potion* H, H2, H3, H4, H5, H6, H7, H8;
   player* p;

};

#endif
