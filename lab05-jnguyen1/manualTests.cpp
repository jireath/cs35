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
#include <UnitTest++/UnitTest++.h>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

int main() {
    // TODO: write any tests you want here; this is your sandbox

    /*LinkedList<int>* newList = new LinkedList<int>();
    cout << newList->isEmpty() << endl;

    newList->checkInvariants();
    int size = newList->getSize();
    cout << size << endl;
    for (int i = 1; i < 10; i++) {
      newList->insertLast(i);
    }
    newList->isEmpty();
    newList->checkInvariants();
    size = newList->getSize();
    cout << size << endl;
    int first = newList->getFirst();
    int last = newList->getLast();

    cout << first << last << endl;
*/

    LinkedList<int>* list = new LinkedList<int>();
    list->insertLast(27);
    list->insertLast(81);
    list->insertLast(56);
    cout << list->removeFirst() << endl;
    cout << list->removeFirst() << endl;
    
    cout << list->getSize() << endl << endl;
    list->checkInvariants();
    delete list;
        

    List<pair<int, string>>* movieLst = loadMovie("test_data/scene3.asciimation");
    playMovie(movieLst);
    cout << (1 % 14 == 0) << endl;
    cout << (14 % 14 == 0) << endl;

    //cout << movieLst->get(0).second;
    //cout << movieLst->get(1).second;
    //cout << movieLst->get(2).second;

    delete movieLst;




    return 0;
}
