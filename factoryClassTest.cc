//
//
//
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#ifdef FACTORY_CLASS_TEST_H
#define FACTORY_CLASS_TEST_H

#include "enemy.h"
#include "item.h"

class factoryClassTest: public Cppunit::enemyTest{

	public:
		void enemy();
		void item();
		void enemyTest();



};
#endif
