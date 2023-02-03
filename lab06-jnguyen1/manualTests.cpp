/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <utility>

#include "linkedQueue.h"
#include "linkedStack.h"
#include "maze.h"
#include "mazeUtils.h"

using namespace std;

int main() {
  Maze* new_maze = loadMap("test_data/easy.map"); 

  List<Position*>* solution_path = new_maze->solveDepthFirst();

  cout << (solution_path == nullptr) << endl;
}
