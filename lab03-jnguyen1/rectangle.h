#pragma once

/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "shape.h"

/*
The rectangle subclass 
*/ 
class Rectangle : public Shape {
  public:
  /** creates a new rectangle
  @param x the x value of the rectangle
  @param y the y value of the rectangle
  @param width the width of the rectangle
  @param height the height of the rectangle
  @param symbol the symbol of the rectangle
  */
    Rectangle(int x, int y, int width, int height, char symbol);
  
  /**
    Places the display symbol onto the grid at the appropriate location
    @param Grid * The grid where the point where be drawn at
   */
    void draw (Grid * grid);

  private:
  // The x position of the rectangle to be drawn on the grid.
    int x;
  // The y position of the rectangle to be drawn on the grid.
    int y;
  // the width of the rectangle to be drawn
    int width; 
  // the height of the rectangle to be drawn
    int height;
  // The character/symbol that will be used to fill in the rectangle on the grid.
    char symbol;
};
