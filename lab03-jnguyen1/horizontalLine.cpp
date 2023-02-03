/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "horizontalLine.h"

HorizontalLine::HorizontalLine(int x, int y, int length, char symbol) {
  // initiates the variables for a horizontal line
  this -> x = x;
  this -> y = y;
  this -> length = length;
  this -> symbol = symbol;
}

void HorizontalLine::draw(Grid* grid) {
  // draws the horizontal line using place symbol function
  for (int i = 0; i < this->length; i++) {
      grid -> placeSymbol(this->x + i, this->y, this->symbol);
      }
  }

