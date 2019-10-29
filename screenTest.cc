/*********************************************************************
/// \Author Jared Sisco
/// \Date November 9th 2017
/// The implementation file for the screenTest class used by CPPUnit used to test the screen class
********************************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>


///Sets up a screen with non default parameters
void screenTest::setUp()
{
   S = new screen(24, 60);
};

///This function is used to tear down the variables as to avoid memory leaks
void screenTest::tearDown(){
   delete S;
}

///Tests several values after setting them to make sure they set properly

void screenTest::testSet()
{
   S->set(10,10,'a');
   CPPUNIT_ASSERT(S->at(10, 10) == 'a');

   S->set(15,40,'b');
   CPPUNIT_ASSERT(S->at(15, 40) == 'b');

   S->set(15,40,'b');
   CPPUNIT_ASSERT(S->at(15, 40) == 'b');
}

///Tests to make sure the size of the screen is setup properly using the tested size
void screenTest::testSize(){

   CPPUNIT_ASSERT(S->mainHeight == 60);
   CPPUNIT_ASSERT(S->mainWidth == 20);
}
   
///Tests the clearing of the screen

void screenTest::testClear(){
   S->clear();
   CPPUNIT_ASSERT(S->at(0, 0) == ' ');
}
