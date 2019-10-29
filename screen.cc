//Zachary Nelson
//CPSC 2720

#include <iostream>
#include "screen.h"

/// The constructor, which takes the height and the width. Both have a default
   /// of 24 x 80.
/// \param[in] in the height and the width for which you want the screen to be.

screen::screen(const int &h,const int &w): mainHeight(h), mainWidth(w+1){

   Array = new char*[h];
   for(int i = 0; i < mainHeight+1; ++i)
      Array[i] = new char[w];

}

/// The Destructor

screen::~screen(){
   for(int i = 0; i < mainHeight; i++){
      delete[] Array[i];
   }
   delete[] Array;
}

/// getRows function, which returns the number of rows.
/// \param[out] out the number of rows.
int screen::getRows(){
   return mainHeight;
}

/// getColumns function which returns the number of columns.
/// \param[out] out the number of columns.
int screen::getColumns(){
   return mainWidth;
}

/// clear function, which clears the entire array.

void screen::clear(){

   for(int i = 0; i < mainHeight; ++i){
      for(int j = 0; j < mainWidth; ++j)
	 Array[i][j] = ' ';
   }
}

  /// set function, which sets the array at the row and col given to the given character.
   /// \param[in] in the row and col for which you want the given character to be placed.
void screen::set(const int &row,const int &col,const char &ch){
   if(row < mainHeight || col < mainWidth)
      Array[row][col] = ch;
};

/// The << operator.
/// \param[in, out] in the os stream and the screen, out the ostream.

ostream& operator<<(ostream& os, const screen &s){
   for(int i = 0; i < s.mainHeight; ++i){
      for(int j = 0; j < s.mainWidth; ++j)
	 os << s.Array[i][j];
      cout << endl;
   }
   return os;
}

/// The at function

const char screen::at(const int &row, const int &col){
   return Array[row][col];
}
