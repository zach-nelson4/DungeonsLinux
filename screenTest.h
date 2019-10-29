/**********************************************************
/// \Author Jared Sisco
/// \Date November 9th 2017
/// This test class is used to test the screen
**********************************************************/

#ifndef SCREEN_TEST_H
#define SCREEN_TEST_H

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

/// Class used to test functionality of the screen class

class screenTest: public CppUnit::TestFixture{
   CPPUNIT_TEST_SUITE(screenTest);
   CPPUNIT_TEST(testSet);
   CPPUNIT_TEST(testSize);
   CPPUNIT_TEST(testClear);

  public:
   void setUp();
   void testSet();
   void testSize();
   void testClear();

  private:
   screen* S;

};

#endif
