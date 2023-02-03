/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/
#include <iostream>
#include <fstream>
using namespace std;

/* This function goes through the array given to it and finds the largest\
   number there.
   param firstNum: The number of numbers in the given array
   param *array: The array that is passed into the function
   returns bigNum: The largest number in the array
  */
int largeNum(int firstNum, int *array) {
  int bigNum = array[0];
  for (int i=1; i < firstNum; i++) {
    if (array[i] > bigNum)
      bigNum = array[i] ;
  }
  return bigNum;
}

/* This function goes through the array given to it and then finds all
  the values within the function that are less than 10 then accumulates it.
   param firstNum: The number of numbers in the given array
   param *array: The array that is passed into the function
   returns count: The count of numbers less than 10
  */
int lessThanTen(int firstNum, int *array) {
  int count = 0;
  for (int i=0; i < firstNum; i++) {
    if (array[i] < 10)
      count = count + 1;
  }
  return count;
}

/* This function goes through the array given to it and adds up all of the
  values within the array. It then divides that by the amount of numbers in
  the array in order to find the average.
   param firstNum: The number of numbers in the given array
   param *array: The array that is passed into the function
   returns mean: The mean of all the given numbers in the array
  */
float average(int firstNum, int *array) {
  float count = 0;
  for (int i=0; i < firstNum; i++) {
    count = count + array[i];
  }
  float mean = count/firstNum;
  return mean;
}

int main() {
  // Asks the user for a file then saves that file as a string
  cout << "Please enter the name of your file: ";
  string filename;
  cin >> filename;
  
  // Opens input file stream so the the data from the user's file can be
  // onto it.
  ifstream myfile;

  // Initializes the firstNum variable
  int firstNum;

  // Opens the file with the given filename and inputs the
  // data from it onto myfile
  myfile.open(filename);
  myfile >> firstNum;

  // Creates a dynamically allocated array and inputs numbers from the file
  // onto the array
  int *numbers = new int[firstNum];
  for (int i=0; i < firstNum; i++) {
    myfile >> numbers[i];
} 
  // Gets the last number from the array by going to the last value
  // in the array
  cout << "The last number is " << numbers[firstNum - 1] << "." << endl;

  // Initialize the bigNum variable and runs the function then prints it
  int bigNum; 
  bigNum = largeNum(firstNum, numbers);
  cout << "The largest number is " << bigNum << "." << endl;

  // Initialize the count variable and runs the function then prints it
  int count;
  count = lessThanTen(firstNum, numbers);
  cout << "There are " << count << 
  " numbers less than 10 in this sequence." << endl;

  // Initialize the mean variable and runs the function then prints it
  float mean;
  mean = average(firstNum, numbers);
  cout << "The average is " << mean << "." << endl;

    return 0;
}

