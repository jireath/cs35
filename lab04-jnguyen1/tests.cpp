/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <UnitTest++/UnitTest++.h>
#include <iostream>

#include "quickSort.h"

using namespace std;

TEST(threeElements) {
  // Create a static array containing the numbers 4, 8, 6.
  int array[3] = {4, 8, 6};
  quickSort(array, 0, 2);
  CHECK_EQUAL(4, array[0]);
  CHECK_EQUAL(6, array[1]);
  CHECK_EQUAL(8, array[2]);
}

TEST(reverseSorted) {
  int size = 20;
  // Create a dynamically-allocated array
  int *array = new int[size];
  for (int i = 0; i < size; i++) {
    array[i] = size - 1 - i;
  }
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size; i++) {
    CHECK_EQUAL(i, array[i]);
  } 
  //de-allocating our array
  delete[] array;
  array = nullptr;
}

TEST(singleElement) {
  // Creates a static single-element array
  int array[1] = {73};
  quickSort(array, 0, 0);
  CHECK_EQUAL(73, array[0]);
}

TEST(preSorted) {
  // creates an already sorted dynamic array
  int size = 73;
  int *array = new int[size];
  for(int i=0; i < size; i++) {
    array[i] = i + 1;
  }
  quickSort(array, 0, size-1);
  for(int i=0; i < size; i++) {
    CHECK_EQUAL(i + 1, array[i]);
  }
  //de-allocating our array
  delete[] array;
  array = nullptr;
}

TEST(Dupes) {
  // creates a static array with several duplicates
  int array[10] = {4, 8, 12, 4, 8, 6, 12, 1, 1, 3};
  quickSort(array, 0, 9);
  CHECK_EQUAL(1, array[0]);
  CHECK_EQUAL(1, array[1]);
  CHECK_EQUAL(3, array[2]);
  CHECK_EQUAL(4, array[3]);
  CHECK_EQUAL(4, array[4]);
  CHECK_EQUAL(6, array[5]);
  CHECK_EQUAL(8, array[6]);
  CHECK_EQUAL(8, array[7]);
  CHECK_EQUAL(12, array[8]);
  CHECK_EQUAL(12, array[9]);
}

TEST(flipFlop) {
  // creates a dynamic array with a large amount of numbers that approach
  // the midpoint from opposite directions
  int size = 1000;
  int *array = new int[size];
  int j = 0;
  for(int i=0; i < size; i+=2) {
    array[i] = j;
    array[i+1] = size - j - 1;
    j+=1;
  }
  quickSort(array, 0, 999);
  for(int i=0; i < size; i++) {
    CHECK_EQUAL(i, array[i]);
  }
  //de-allocating our array
  delete[] array;
  array = nullptr;
}

/* no need to modify main */
int main() {
  return UnitTest::RunAllTests();
}
