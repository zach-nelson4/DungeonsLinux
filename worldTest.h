/**********************************************************
/// \Author Jared Sisco
/// \Date November 9th 2017
/// This test class is used to test the world
**********************************************************/

#ifndef WORLD_TEST_H
#define WORLD_TEST_H

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "room.h"
#include "screen.h"
#include "worldClass.h"

/// Class used to test functionality of the world class

class worldTest: public CppUnit::TestFixture{
   CPPUNIT_TEST_SUITE(worldTest);
   CPPUNIT_TEST(testChest);
   CPPUNIT_TEST(testEnemy);
   CPPUNIT_TEST(testPlayer);
   CPPUNIT_TEST(testRoomSwitch);
   CPPUNIT_TEST(testSave);
   CPPUNIT_TEST(testLoad);

  public:
   void setUp();
   void testChest();
   void testEnemy();
   void testPlayer();
   void testRoomSwitch();
   void testSave();
   void testLoad();


  private:
   screen* S; world* W; room* R; room* R2;


};

#endif
