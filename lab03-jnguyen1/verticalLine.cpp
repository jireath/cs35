/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "verticalLine.h"

VerticalLine::VerticalLine(int x, int y, int length, char symbol) {
  // initializes the variables for a vertical line
  this -> x = x;
  this -> y = y;
  this -> length = length;
  this -> symbol = symbol;
}

void VerticalLine::draw(Grid* grid) {
  // draws the vertical line using the place symbol function
  for (int i = 0; i < this->length; i++) {
      grid -> placeSymbol(this->x, this->y + i, this->symbol);
      }
  }
