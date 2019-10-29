/********************************************
Author: Zachary Nelson
Date: October 21st 2017

This is the screenElement, it is an abstract base class which describes an element on the screen.

********************************************/

#include<iostream>
#include "screen.h"

#ifndef ScreenElement_H
#define ScreenElement_H

class screenElement{

  public:
   //A virtual void draw function
   virtual void draw(screen &s) = 0;

   //A virtual void updateHP function
   virtual void updateHP(const int &i) = 0;
   //A virtual destructor
   //virtual ~screenElement();

};

#endif
