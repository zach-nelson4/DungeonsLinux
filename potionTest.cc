/************************************************************
/// \Author Broderick Molcak
/// \Date November 7th 2017
/// This program is used to test the potionTest using CPPUNIT
**********************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "potionTest.h"
#include "player.h"
#include "potion.h"

///Creating variables
void potionTest::setUp(){
   HP = 1;
   H = new potion("testPotion", 2);
   H2 = new potion("testPotion2", 3);
   H3 = new potion("testPotion3", 4);
   H4 = new potion("testPotion4", 5);
   H5 = new potion("testPotion5", 6);
   H6 = new potion("testPotion6", 7);
   H7 = new potion("testPotion7", 8);
   H8 = new potion("testPotion", 9);
   p = new player(HP, 10, 10, 10);
}

///Destroys everything
void potionTest::tearDown(){
   delete H;
   delete H2;
   delete H3;
   delete H4;
   delete H5;
   delete H6;
   delete H7;
   delete H8;
   delete p;
}

///Used to test if potion values properly pass
void potionTest::testUse(){
   
   ///Health has a value of 1, so players hp should go to 3
   p->use(H);
   CPPUNIT_ASSERT(p->getHP() == 3);

   ///Health has a value of 3, so players hp should go to 6
   p->use(H2);
   CPPUNIT_ASSERT(p->getHP() == 6);

   ///Health has a value of 6, so players hp should go to 10
   p->use(H3);
   CPPUNIT_ASSERT(p->getHP() == 10);

   ///Health has a value of 10, so players hp should go to 15
   p->use(H4);
   CPPUNIT_ASSERT(p->getHP() == 15);
   
   ///Health has a value of 15, so players hp should go to 21
   p->use(H5);
   CPPUNIT_ASSERT(p->getHP() == 21);
   
   ///Health has a value of 21, so players hp should go to 28
   p->use(H6);
   CPPUNIT_ASSERT(p->getHP() == 28);
   
   ///Health has a value of 28, so players hp should go to 36
   p->use(H7);
   CPPUNIT_ASSERT(p->getHP() == 36);
   
   ///Health has a value of 36 so players hp should go to 45
   p->use(H8);
   CPPUNIT_ASSERT(p->getHP() == 45);
   
   /// These 8 assertions, should prove that potion stats are properly passing
}
