/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height, char symbol) {
  // initializes the variables for rectangle
  this -> x = x;
  this -> y = y;
  this -> width = width;
  this -> height = height;
  this -> symbol = symbol;
}

void Rectangle::draw(Grid* grid) {
  // draws the rectangle using the place symbol function within a nested loop
  for (int i = 0; i < this->width; i++) {
    for (int j = 0; j < this->height; j++) {
      grid -> placeSymbol(this->x + i, this->y + j, this->symbol);
    }
  }
}
