/********************************************************************
/// \Author Zachary Nelson
/// \Date November 7th 2017
/// This is the implementation file for the entityTest class, which is used by CPPUNIT to test the entity Class.
*******************************************************************/

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "entityTest.h"
#include "entity.h"
#include "screen.h"

///Creating variables to test with
void entityTest::setUp(){
   s = new screen(25, 50);
   e = new entity(10, 10, 10, 10);
}

///Used to delete the testing variables

void entityTest::tearDown(){
   delete s;
   delete e;
}

///This assertion is used to test the UpdateHP function, by updating the HP by
/// a value of 5. Since the entity's original HP is 10, updating it by +5 should
/// mean that the HP is 15.

void entityTest::testUpdateHP(){
   
   e->updateHP(5);
   CPPUNIT_ASSERT(e->HP == 15);

   /// This assertion is used to test in the opposite, using a negative update.
   e->updateHP(-10);
   CPPUNIT_ASSERT(e->HP == 5);

}

///This is used to test the getX function of the entity class by making sure that
/// the returned value is 10, as that should be the x location of the entity.
void entityTest::testGetX(){

   CPPUNIT_ASSERT(e->getX() == 10);

}

/// This is similiar to the above function, but instead of X, it is used to
/// check if the getY function is working properly

void entityTest::testGetY(){

   CPPUNIT_ASSERT(e->getY() == 10);

}

/// This assertion is used to test the Move function of the entity class.
void entityTest::testMove(){

   ///Test to make sure that moving down is okay.
   e->move(e->getX(), e->getY() + 1);
   CPPUNIT_ASSERT(e->getY() == 11);

   ///Test to make sure that moving up is okay
   e->move(e->getX(), e->getY() -1);
   CPPUNIT_ASSERT(e->getY() == 10);

   ///Test to make sure that moving left is okay
   e->move(e->getX()-1, e->getY());
   CPPUNIT_ASSERT(e->getX() == 9);

   ///Test to make sure that moving right is okay
   e->move(e->getX() +1, e->getY());
   CPPUNIT_ASSERT(e->getX() == 10);

}

/// This assertion is used to test the draw function of the entity class.
/// May want to move this to the player class and the enemy class.
void entityTest::testDraw(){

   e->draw(*s);
   CPPUNIT_ASSERT(s->array[10][10] == 'O');

}

///This assertion is used to test to make sure that the clear function works
/// as intended by making sure the location that the entity once was is now blank.

void entityTest::testClear(){
   e->clear(*s);
   CPPUNIT_ASSERT(s->array[10][10] == ' ');
}
