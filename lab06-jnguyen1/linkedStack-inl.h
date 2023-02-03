/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "linkedStack.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a
// single line of code!

template <typename T> LinkedStack<T>::LinkedStack() {
//LinkedStack Constructor. Inputs nothing and returns nothing. 

  this->list = new STLList<T>();
}

template <typename T> LinkedStack<T>::~LinkedStack() {
//LinkedStack Destructor. Frees the memory allocated when creating the LinkedStack. Inputs nothing and returns nothing. 

  delete this->list;
}

template <typename T> void LinkedStack<T>::push(T element) {
//Method that inserts something into the front of the stack. Inputs the thing to insert. Returns nothing. 

  this->list->insertFirst(element);  
}

template <typename T> T LinkedStack<T>::pop() {
//Method that removes the first thing from the stack (FIFO). Inputs nothing. Returns the thing we removed. 

  T return_val = this->list->getFirst(); 
  this->list->removeFirst();

  return return_val;
}

template <typename T> void LinkedStack<T>::insert(T element) {
//Method to insert something into the stack by calling push(). Inputs the thing to insert. Returns nothing. 

  this->push(element);
}

template <typename T> T LinkedStack<T>::remove() {
//Method to remove something from the stack by calling pop(). Inputs nothing. Returns the thing we removed. 

  return this->pop();
}

template <typename T> int LinkedStack<T>::getSize() {
//Method to retrieve the size of the stack. Inputs nothing. Returns the size of the stack. 

  return this->list->getSize();
}

template <typename T> bool LinkedStack<T>::isEmpty() {
//Method to determine if the stack is empty. Inputs nothing. Returns a boolean. 

  if (this->list->getSize() == 0) {
    return true;
  }
  return false;
}

template <typename T> T LinkedStack<T>::peek() {
//Method to retrieve the first thing in the stack. Inputs nothing. Returns the first thing in the stack. 

  return this->list->getFirst();
}
