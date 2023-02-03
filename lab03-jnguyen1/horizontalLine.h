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
The horizontal line subclass 
*/ 
class HorizontalLine : public Shape {
  public:
  /** creates a new horizontal line
  @param x the x value of the length
  @param y the y value of the length
  @param length the length of the line
  @param symbol the symbol of the line
  */
    HorizontalLine(int x, int y, int length, char symbol);
  
  /**
    Places the display symbol onto the grid at the appropriate location
    @param Grid * The grid where the point where be drawn at
   */
    void draw (Grid * grid);

  private:
  // The x position of the line to be drawn on the grid.
    int x;
  // The y position of the line to be drawn on the grid.
    int y;
  // the length of the line to be drawn
    int length; 
  // The character/symbol that will be used to fill in the line on the grid.
    char symbol;
};
