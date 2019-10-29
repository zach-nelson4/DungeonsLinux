///
/// \authorZachary Nelson
/// \date Sep 20th 2017
/// Cpsc 2720
/// This is the Screen Class. It is an abstraction of a 2D dynamic array
/// composed of characters. 

#ifndef screen_H
#define screen_H

#include <iostream>
#include <cassert>

using namespace std;

class screen {

  public:

   /// The constructor, which takes the height and the width. Both have a default
   /// of 24 x 80.
   /// \param[in] in the height and the width for which you want the screen to be.
   screen(const int &height = 24,const int &width = 80);

   /// The destructor
   ~screen();

   /// getRows function, which returns the number of rows.
   /// \param[out] out the number of rows.
   int getRows();

   /// getColumns function, which returns the number of columns
   /// \param[out] out the number of columns
   int getColumns();

   /// clear function, which clears the entire array.
   void clear();

   /// set function, which sets the array at the row and col given to the given character.
   /// \param[in] in the row and col for which you want the given character to be placed.
   void set(const int &row,const int &col,const char &ch);

   const char at(const int &row, const int &col);
   
  private:

   /// The character array 
   char** Array;

   /// The Height and width of the array
   int mainHeight;
   int mainWidth;

   /// Friend function to enable the use of the << operator
   /// \param[in, out] in the os stream and the screen, out the ostream.
   friend ostream& operator<<(ostream& os, const screen &s);
   

};

#endif
