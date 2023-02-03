/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "quickSort.h"

// TODO: you will need to write an appropriate "partition" function here
// It does not need to be in your header file because no one else will call it.

void quickSort(int *array, int startIndex, int endIndex) {
  if (endIndex <= startIndex) {
    return;
  }
  int pivot = partition(array, startIndex, endIndex);
  quickSort(array, startIndex, pivot-1);
  quickSort(array, pivot+1, endIndex);
}

int partition(int* array, int left, int right) {
  int pivot = right; //TODO make this a random int number between left and right inclusive!!!
  //swap(array, right, pivot);
  right--;
  do {
    if (array[left] <= array[pivot]) {
      left++;
    }
    else if (array[right] >= array[pivot]) {
      right--;
    }
    else {
      swap(array, left, right);
    }
  }
  while (left <= right);
  swap(array, left, pivot);
  
  return left;
}

void swap(int *array, int a, int b) {
  int temp = array[a];
  array[a] = array[b];
  array[b] = temp;
}

// You should not need to modify this function.
// qSort is a wrapper around the main quickSort function.
void qSort(int *array, int size) {
  quickSort(array, 0, size - 1);
}
