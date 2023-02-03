/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <stdexcept>

#include "picture.h"

using namespace std;

Picture::Picture() {
    // initializing the variables
    this -> numberOfShapes = 0;
    this -> shapes = new Shape*[50];

}

Picture::~Picture() {
    // deletes the array to save memory
    for(int i=0; i < this->numberOfShapes; i++) {
        delete this -> shapes[i];
    }
    delete[] this -> shapes;
}

string Picture::toString() {
    // converts the shapes array into a string
    Grid* newGrid = new Grid();
    for(int i=0; i < this->numberOfShapes; i++) {
         this -> shapes[i] -> draw(newGrid); 

    }
    string str = newGrid->toString();

    //deletes the array
    delete newGrid;

    return str;

}

void Picture::print() {
    cout << this->toString() << endl;
}

void Picture::addShape(Shape* shape) {
    // adds a shape to the grid
    this -> shapes[numberOfShapes] = shape;
    this -> numberOfShapes = this -> numberOfShapes + 1;
}
