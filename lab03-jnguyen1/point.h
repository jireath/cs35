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
The point subclass 
*/
class Point : public Shape {
  public:
  /** creates a new point
  @param x the x value of the point
  @param y the y value of the point
  @param symbol the symbol of the point
  */
    Point(int x, int y, char symbol);
  
  /**
    Places the display symbol onto the grid at the appropriate location
    @param Grid * The grid where the point where be drawn at
   */
    void draw (Grid * grid);

  private:
  // The x position of the point to be drawn on the grid.
    int x;
  // The y position of the point to be drawn on the grid.
    int y;
  // The character/symbol that will be used to fill in the point on the grid.
    char symbol;
};
