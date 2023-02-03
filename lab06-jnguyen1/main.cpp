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

#include "maze.h"
#include "mazeUtils.h"

using namespace std;

int main(int argc, char** argv) {

  if (argc != 3) {
    cout << "You must provide two command line arguments." << endl;
  }

  if (argc == 3) {
    string filename = argv[1]; 

    Maze* maze = nullptr;

    try { 
      maze = loadMap(filename);
    } catch (runtime_error e) {
      cout << "Invalid filename :)." << endl;
      return 1; 
    }

    string solve_method_depth = "depth"; 

    string solve_method_breadth = "breadth"; 

    if (argv[2] == solve_method_depth) {

      List<Position*>* solution_path = maze->solveDepthFirst(); 

      if (solution_path == nullptr) {
        cout << "There is no solution to the maze." << endl; 
        return 0; 
      } else {
        cout << renderAnswer(maze, solution_path) << endl;
        delete solution_path;
        delete maze; 
        return 0;
      }

    } else if (argv[2] == solve_method_breadth) {

      List<Position*>* solution_path = maze->solveBreadthFirst(); 

      if (solution_path == nullptr) {
        cout << "There is no solution to the maze." << endl; 
        delete maze; 
        return 0; 
      } else {

        cout << renderAnswer(maze, solution_path) << endl;
        delete solution_path; 
        delete maze; 
        return 0;
      }
    } else {
      cout << "Invalid solve method input. Please choose breadth or depth." << endl;
    }
  }
}