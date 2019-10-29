/************************************************************
/// \Author Broderick Molcak
/// \Date November 7th 2017
/// This program is used to test the weaponTest using CPPUNIT
**********************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "weaponTest.h"
#include "player.h"
#include "weapon.h"

///Creating variables
void weaponTest::setUp(){
   HP = 10;
   ATK = 10;
   W = new weapon("testWeapon", 5);
   W2 = new weapon("testWeapon2", 10);
   W3 = new weapon("testWeapon3", 15);
   W4 = new weapon("testWeapon4", 20);
   W5 = new weapon("testWeapon5", 25);
   W6 = new weapon("testWeapon6", 30);
   W7 = new weapon("testWeapon7", 35);
   W8 = new weapon("testWeapon8", 40);
   p = new player(HP, ATK, 10, 10);
}

///Destroys everything
void weaponTest::tearDown(){
   delete W;
   delete W2;
   delete W3;
   delete W4;
   delete W5;
   delete W6;
   delete W7;
   delete W8;
   delete p;
}

///Used to test if weapon values properly pass
void weaponTest::testEquip(){
   
   ///Weapon has a value of 5, so players hp should go to 15
   p->equip(W);
   CPPUNIT_ASSERT(p->getATK() == 15);

   ///Weapon has a value of 10, so players hp should go to 20
   p->equip(W2);
   CPPUNIT_ASSERT(p->getATK() == 20);

   ///Weapon has a value of 15, so players hp should go to 25
   p->equip(W3);
   CPPUNIT_ASSERT(p->getATK() == 25);

   ///Weapon has a value of 20, so players hp should go to 30
   p->equip(W4);
   CPPUNIT_ASSERT(p->getATK() == 30);
   
   ///Weapon has a value of 25, so players hp should go to 35
   p->equip(W5);
   CPPUNIT_ASSERT(p->getATK() == 35);
   
   ///Weapon has a value of 30, so players hp should go to 40
   p->equip(W6);
   CPPUNIT_ASSERT(p->getATK() == 40);
   
   ///Weapon has a value of 35, so players hp should go to 45
   p->equip(W7);
   CPPUNIT_ASSERT(p->getATK() == 45);
   
   ///Weapon has a value of 40, so players hp should go to 50
   p->equip(W8);
   CPPUNIT_ASSERT(p->getATK() == 50);
   
   /// These 8 assertions, should prove that weapon stats are properly passing
}
