/************************************************************
/// \Author Broderick Molcak
/// \Date November 7th 2017
/// This program is used to test the armourTest using CPPUNIT
**********************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "armourTest.h"
#include "player.h"
#include "armour.h"

///Creating variables
void armourTest::setUp(){
   HP = 10;
   ATK = 10;
   A = new armour("testArmour", 5);
   A2 = new armour("testArmour2", 10);
   A3 = new armour("testArmour3", 15);
   A4 = new armour("testArmour4", 20);
   A5 = new armour("testArmour5", 25);
   A6 = new armour("testArmour6", 30);
   A7 = new armour("testArmour7", 35);
   A8 = new armour("testArmour8", 40);
   p = new player(HP, ATK, 10, 10);
}

///Destroys everything
void armourTest::tearDown(){
   delete A;
   delete A2;
   delete A3;
   delete A4;
   delete A5;
   delete A6;
   delete A7;
   delete A8;
   delete p;
}

///Used to test if armour values properly pass
void armourTest::testEquip(){
   
   ///Armour has a value of 5, so players hp should go to 15
   p->equip(A);
   CPPUNIT_ASSERT(p->getHP() == 15);

   ///Armour has a value of 10, so players hp should go to 20
   p->equip(A2);
   CPPUNIT_ASSERT(p->getHP() == 20);

   ///Armour has a value of 15, so players hp should go to 25
   p->equip(A3);
   CPPUNIT_ASSERT(p->getHP() == 25);

   ///Armour has a value of 20, so players hp should go to 30
   p->equip(A4);
   CPPUNIT_ASSERT(p->getHP() == 30);
   
   ///Armour has a value of 25, so players hp should go to 35
   p->equip(A5);
   CPPUNIT_ASSERT(p->getHP() == 35);
   
   ///Armour has a value of 30, so players hp should go to 40
   p->equip(A6);
   CPPUNIT_ASSERT(p->getHP() == 40);
   
   ///Armour has a value of 35, so players hp should go to 45
   p->equip(A7);
   CPPUNIT_ASSERT(p->getHP() == 45);
   
   ///Armour has a value of 40, so players hp should go to 50
   p->equip(A8);
   CPPUNIT_ASSERT(p->getHP() == 50);
   
   /// These 8 assertions, should prove that armour stats are properly passing
}
