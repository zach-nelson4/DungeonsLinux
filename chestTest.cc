/***********************************************************************
/// \Author Darsh Thanki
/// \Date November 7th 2017
/// This is the implementation file used for the chestTest,
/// which is used by CPPUNIT to test the chest class.
***********************************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "chestTest.h"
#include "chest.h"
#include "item.h"
#include "player.h"

///creating some variables to test with
void chestTest::setUp(){
  c = new chest();
  i = new item();
  p = new player(10, 10, 10, 10)
}

///Removes everything to avoid memory leaks
void chestTest::tearDown(){
   delete i;
   delete c;
   delete p;
}

///This function is used to test the opening of an item chest
void chestTest::testOpen(){
   c->open(i);
   CPPUNIT_ASSERT()
   //not sure how to validate yet

}

/// This assertion is used to test if the item is equipable.
void chestTest::testAllowEquip(){
    p->equip(i);
    CPPUNIT_ASSERT_NOTHROW();
}
