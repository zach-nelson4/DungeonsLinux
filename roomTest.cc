/*********************************************************************
/// \Author Zachary Nelson
/// \Date November 8th 2017
/// This is the implementation file for the roomTest, which is used by CPPUNIT
/// to test the room class
********************************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "room.h"
#include "roomTest.h"
#include "screen.h"
#include "screenElement.h"

///This function is used to create some variables from which to test with.
void roomTest::setUp(){
   R = new room(true, true, true, true);
   P = new player(10, 10, 10, 10);
   S = new screen(25, 25);
};

///This function is used to tear down the variables as to avoid memory leaks
void roomTest::tearDown(){
   delete R;
   delete P;
}

///This function is designed to test to make sure that the draw function works
/// properly.

void roomTest::testDraw(){
   R->draw(*S);
   CPPUNIT_ASSERT(S->at(0, 0) == '+');
}

///This function is designed to test to make sure that the walls are functioning properly
void roomTest::testWalls(){

   CPPUNIT_ASSERT(S->at(13, 0) == ' ');
   CPPUNIT_ASSERT(S->at(0, 13) == ' ');
   CPPUNIT_ASSERT(S->at(25, 13) == ' ');
   CPPUNIT_ASSERT(S->(13, 25) == ' ');
}
   
///This function is designed to test to make sure that the clear function works
///proplery

void roomTest::testClear(){
   R->clear(*S);
   CPPUNIT_ASSERT(S->at(0, 0) == ' ');
}
