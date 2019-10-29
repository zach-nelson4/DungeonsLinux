/************************************************************
/// \Author Zachary Nelson
/// \Date November 7th 2017
/// This is the implementation file for the playerTest, which is used by CPPUNIT to test the player class.
**********************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "playerTest.h"
#include "player.h"
#include "screen.h"
#include "armour.h"
#include "weapon.h"

///Creating some variables to test with
void playerTest::setUp(){
   S = new screen(25, 50);
   HP = 10;
   ATK = 10;
   I = new armour("testArmour", 5);
   I2 = new weapon("testWeapon", 5);
   I3 = new armour("testArmour2", 3);
   I4 = new weapon("testWeapon2", 3);
   p = new player(HP, ATK, 10, 10);
}

///tears down the entire thing
void playerTest::tearDown(){
   delete S;
   delete I;
   delete I2;
   delete I3;
   delete I4;
   delete p;
}


///This function is used to test the equip function
void playerTest::testEquip(){
   
   p->equip(I);

   ///Since HP is 10, equiping an armor with a value of 5 should mean that the player's
   ///HP will be equal to 15. This tests that.
   CPPUNIT_ASSERT(p->getHP() == 15);

   ///This assertion is used to test to make sure that a weapon with a value of 5
   ///will increase the player's atk by a value of 5.

   p->equip(I2);
   CPPUNIT_ASSERT(p->getATK() == 15);

   ///This assertion is used to test to make sure that by removing the I and
   ///equiping I3, the player's HP will only be 13, instead of 18 (15 + 3)

   p->equip(I3);
   CPPUNIT_ASSERT(p->getHP() == 13);

   //This assertion is used to do the same thing, except with the weapon class.

   p->equip(I4);
   CPPUNIT_ASSERT(p->getATK() == 13);
   
   /// By passing these 4 assertions, that should prove that the equip function
   /// is working properly.
}


