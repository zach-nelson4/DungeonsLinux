/**********************************************************
/// \Author Jared Sisco
/// \Date November 9th 2017
/// This test class is used to test the world and everything spawned inside it
**********************************************************/

#ifndef WORLD_TEST_CC
#define WORLD_TEST_CC

#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>

#include "room.h"
#include "screen.h"
#include "worldClass.h"

/// Creates a world, a screen and a room, adds a room into the world sets it to current room, spawns a chest, enemy and player though world.
void worldTest::setUp()
{
   W = new worldClass();
   S = new screen(24, 60);
   R = new room(false,false,false,false,S);
   
   W->rooms.push_back(R);
   W->current_room=R;
   W.SpawnChest(R, 15, 20);
   W.SpawnEnemy(10,2, 5,6, W->current_room);
   W.SpawnPlayer(1, 1, W->current_room);
};

/// This function is used to tear down the variables as to avoid memory leaks
void worldTest::tearDown()
{
   delete W;
   delete S;
   delete R;
}

///Tests if a chest exists in the world at the specified position after spawning it

void worldTest::testChest()
{
   CPPUNIT_ASSERT(W->chests[0]->locationx == 15);
   CPPUNIT_ASSERT(W->chests[0]->locationy == 20);
}

/// Tests if an enemy exists in the world at the specified location after spawning it
void worldTest::testEnemy()
{
   CPPUNIT_ASSERT(W->enemies[0]->x == 5);
   CPPUNIT_ASSERT(W->enemies[0]->y == 6);
}
   
/// Tests if a player is found in the world at a specified x and y

void worldTest::testPlayer()
{
   CPPUNIT_ASSERT(W->player_ptr->x == 1);
   CPPUNIT_ASSERT(W->player_ptr->y == 1);
}

/// Tests if a room exists after adding a new room to world and switching to it

void worldTest::testRoomSwitch()
{
   R2 = new room(false,false,false,false,S);
   W->rooms.push_back(R2);

   W.SwitchRoom(R2);
   CPPUNIT_ASSERT(W->current_room == R2);
}


void worldTest::testSave()
{
// Unsure of exact save format
}


void worldTest::testLoad()
{
// Unsure of exact file formatting
}

#endif
