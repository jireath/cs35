/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

List<pair<int, string>>* loadMovie(string filename) {
    
  ifstream myFile; 
  myFile.open(filename);
  if(!myFile.is_open()) {
    throw runtime_error("file " + filename + "failed to open ");
  }
  
  LinkedList<pair<int, string>>* pairList = new LinkedList<pair<int, string>>();

  string data;
  getline(myFile, data);
  int count = 0;
  int frameCount = stoi(data);
  string pic = "";
  
  while (!myFile.eof()) {
    if (count == 1) {  
       pair<int, string> pair(frameCount, pic);
       pairList->insertLast(pair);
       frameCount = stoi(data);
       pic = "";
       count = 0;
    }
    else {
      for (int i=0; i<13; i++) {
        getline(myFile, data);
        pic += data + "\n";
      }
      count = 1;
    getline(myFile, data);
    }
  }
  pair<int,string> pair(frameCount, pic);
  pairList->insertLast(pair);
  return pairList;
}

void playMovie(List<pair<int, string>>* list) {
    
    for (int i=0; i<list->getSize(); i++) {
        system("clear");
        cout << list->get(i).second << endl;
        usleep((1000000*list->get(i).first)/15);
    }
}



