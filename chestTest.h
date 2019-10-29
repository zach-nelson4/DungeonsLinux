/******************************************************************************
/// \Author Darsh Thanki
/// \Date November 7th 2017
/// This class is used to test the chest class by using CPPUNIT
****************************************************************************/

#ifndef CHEST_TEST_H
#define CHEST_TEST_H

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "chest.h"
#include "enemy.h"
#include "player.h"

/// Class used to test functionality of the  class

class battleTest:: public CppUnit::TestFixture{

   /// Macros used to create the test suite
   CPPUNIT_TEST_SUITE(chestTest);
   CPPUNIT_TEST(testOpen);
   CPPUNIT_TEST(testAllowEquip);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp();
   void testOpen();
   void testAllowEquip();
   void tearDown();

  private:
   player* p;
   item* i;
   chest* c;

};

#endif
