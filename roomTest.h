/**********************************************************
/// \Author Zachary Nelson
/// \Date November 8th 2017
/// This class is used to test the room class
**********************************************************/

#ifndef ROOM_TEST_H
#define ROOM_TEST_H

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "room.h"
#include "player.h"
#include "screen.h"
#include "screenElement.h"
#include <vector>

/// Class used to test functionality of the room class

class roomTest: pulic CppUnit::TestFixture{
   CPPUNIT_TEST_SUITE(roomTest);
   CPPUNIT_TEST(testWalls);
   CPPUNIT_TEST(testDraw);
   CPPUNIT_TEST(testClear);

  public:
   void setUp();
   void testWalls();
   void testDraw();
   void testClear();

  private:
   screen* S;
   room* R;
   player* P;

};

#endif
