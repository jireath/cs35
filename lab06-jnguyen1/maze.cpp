/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <iostream>

/* ADTs */
#include "adts/list.h"
#include "adts/orderedCollection.h"
#include "adts/queue.h"
#include "adts/stack.h"

/* Implementations of above ADTs */
#include "adts/stlList.h"
#include "linkedQueue.h"
#include "linkedStack.h"

#include "maze.h"

using namespace std;

Maze::Maze(int width, int height) {
  //Constructor: Initializes a maze. 
  //Inputs the width and height of the maze as ints. Returns nothing. 

  this->width = width;
  this->height = height;

  this->positions = new Position**[this->width]; 

  int x = 0; 
  int y = 0; 

  for (int i = 0; i < width; i++) {
    Position** length_array = new Position*[this->height]; 
    this->positions[i] = length_array; 
  }

  for (int j = 0; j < width; j++) {
    for (int k = 0; k < height; k++) {
      Position* new_position = new Position(j,k);
      this->positions[j][k] = new_position;
    }
  }
}

Maze::~Maze() {
  //Destructor: Deletes the allocated memory. 
  //Inputs nothing. Returns nothing. 

  for (int j = 0; j < width; j++) {
    for (int k = 0; k < height; k++) {
      delete this->positions[j][k]; 
    }
  }

  for (int i = 0; i < width ; i++) {
    delete[] this->positions[i];
  }

  delete[] this->positions; 

}

int Maze::getWidth() {
  //Method that returns the width of the maze. 
  //Inputs nothing. Returns the width as an int. 

  return this->width;
}

int Maze::getHeight() {
  //Method that returns the height of the maze. 
  //Inputs nothing. Returns the height as an int. 

  return this->height;
}

bool Maze::isWall(int x, int y) {
  //Method that tells us if there is a wall adjacent to the position of interest. 
  //Inputs an x and y position as ints. Returns a boolean. 

  return this->positions[x][y]->isWall();
}

void Maze::setWall(int x, int y) {
  //Method that sets the desired position as a wall. 
  //Inputs an x and y position as ints. Returns nothing.

  return this->positions[x][y]->setWall();
}

List<Position*>* Maze::getNeighbors(Position* position) {
  //Method that identifies the viable adjacent neighbor positions and puts them in a list. 
  //Inputs a pointer to a position. Returns a list of positions. 

  List<Position*>* neighbors = new STLList<Position*>();

  int x = position->getX();
  int y = position->getY(); 

  if (!((y-1) < 0) && !(positions[x][y-1]->isWall())) {
    neighbors->insertFirst(this->positions[x][y-1]);
  } if (!((x-1) < 0) && !(positions[x-1][y]->isWall())) {
    neighbors->insertLast(this->positions[x-1][y]);
  } if (!((x+1) > (width-1)) && !(positions[x+1][y]->isWall())) {
    neighbors->insertLast(this->positions[x+1][y]);
  } if (!((y+1) > (height-1)) && !(positions[x][y+1]->isWall())) {
    neighbors->insertLast(this->positions[x][y+1]);
  }
  return neighbors;
}

List<Position*>* Maze::solveBreadthFirst() {
  //Method that uses a search with a queue to find the solution to the maze. 
  //Inputs nothing. Returns a list of positions. 
  
  LinkedQueue<Position*>* queue = new LinkedQueue<Position*>;

  List<Position*>* solved_queue = this->solve(queue);

  delete queue; 

  return solved_queue;

}

List<Position*>* Maze::solveDepthFirst() {
  //Method that uses a search with a stack to find the solution to the maze. 
  //Inputs nothing. Returns a list of positions. 
  
  LinkedStack<Position*>* stack = new LinkedStack<Position*>;

  List<Position*>* solved_stack = this->solve(stack);

  delete stack;

  return solved_stack;

}

List<Position*>* Maze::solve(OrderedCollection<Position*>* exploration) {
  //Method that implements the search and solves the maze. 
  //Inputs an ordered collection data structure with positions that have not been explored. Returns a list of positions for the solution.

  Position* start = positions[0][0]; 

  List<Position*>* solution = new STLList<Position*>(); 

  start->setVisited();

  exploration->insert(start); 

  while (!(exploration->isEmpty())) {

    Position* current = exploration->remove();

    if (current->getX() == width-1 && current->getY() == height-1) {
      break;
    }

    List<Position*>* neighbors = this->getNeighbors(current);

    int num_neighbors = neighbors->getSize();

    for (int i = 0; i < num_neighbors; i++) {
      if (!(neighbors->get(i)->isVisited())) {
        neighbors->get(i)->setVisited();
        neighbors->get(i)->setPrevious(current); 
        exploration->insert(neighbors->get(i));
      }
    }
    delete neighbors;
  }

  if (this->positions[width-1][height-1]->isVisited()){
    Position* current = this->positions[width-1][height-1];
    solution->insertFirst(current); 
    while (current != positions[0][0]) {
      Position* previous = current->getPrevious();
      solution->insertFirst(previous);
      current = previous;
    }
    return solution; 

  } else {
    delete solution;
    return nullptr; 
  }
}

