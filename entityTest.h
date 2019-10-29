/**********************************************************************
/// \Author Zachary Nelson
/// \Date November 7th 2017
/// This class is used to test the entity class using CPPUNIT
**********************************************************************/

#ifndef ENTITY_TEST_H
#define ENTITY_TEST_H

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "entity.h"
#include "screen.h"

/// Class used to test the functionality of the entity class

class entityTest: public CppUnit::TestFixture{

   ///macros to create the test suite
   CPPUNIT_TEST_SUITE(entityTest);
   CPPUNIT_TEST(testUpdateHP);
   CPPUNIT_TEST(testGetX);
   CPPUNIT_TEST(testGetY);
   CPPUNIT_TEST(testMove);
   CPPUNIT_TEST(testClear);
   CPPUNIT_TEST(testDraw);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp();
   void testUpdateHP;
   void testGetX;
   void testGetY;
   void testMove;
   void testClear;
   void testDraw;

  private:
   screen* s;
   entity* e;

};

#endif
   
   
