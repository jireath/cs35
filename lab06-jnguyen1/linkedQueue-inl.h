/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "linkedQueue.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a
// single line of code!

template <typename T> LinkedQueue<T>::LinkedQueue() {
//LinkedQueue Constructor. Inputs nothing and returns nothing. 

  this->list = new STLList<T>();
}

template <typename T> LinkedQueue<T>::~LinkedQueue() {
//LinkedQueue Destructor. Releases the memory created when a new LinkedQueue is created. Inputs nothing and returns nothing. 

  delete this->list;
}

template <typename T> int LinkedQueue<T>::getSize() {
//Method for a LinkedQueue that returns the size of the queue. Inputs nothing.

  return this->list->getSize();
}

template <typename T> bool LinkedQueue<T>::isEmpty() {
//Method to check if the LinkedQueue is empty. Inputs nothing. Returns a boolean.

  if (this->list->getSize() == 0) {
    return true;
  }
  return false;
}

template <typename T> T LinkedQueue<T>::peek() {
//Method to retrieve the first thing in the LinkedQueue. Inputs Nothing. Returns the first thing. 

  return this->list->getFirst();
}

template <typename T> void LinkedQueue<T>::enqueue(T element) {
//Method that inserts something at the end of the LinkedQueue. Inputs that thing. Returns nothing. 

  this->list->insertLast(element);
}

template <typename T> T LinkedQueue<T>::dequeue() {
//Method that removes the first thing in the queue. Inputs nothing. Returns the first thing in the list. 

  T return_val = this->list->getFirst(); 
  this->list->removeFirst();

  return return_val;
}

template <typename T> void LinkedQueue<T>::insert(T element) {
//Method that inserts an object to the end of the queue by calling enqueue(). Inputs the thing you want to insert. Returns nothing. 

  this->enqueue(element);
}

template <typename T> T LinkedQueue<T>::remove() {
//Method that removes the first thing in the queue by calling dequeue(). Inputs nothing. Returns the removed thing. 

  return this->dequeue();
}

