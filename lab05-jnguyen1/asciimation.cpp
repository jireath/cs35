/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/
/*
 * This is a program that allows the user to play an asciimation video forward or reversed
 * by inputting command line arguments. To play forward, there should be 1 command line 
 * argument, which should be the name of the file. To play in reverse, the first 
 * command line argument should be "--reverse" and the second should be the file name.
 */
#include <iostream>
#include <string>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

int main(int argc, char** argv) {
    
    string arg1 = argv[1];    

    if (argc == 2) {
        string name = arg1;
        List<pair<int, string>>* movieList = \
            loadMovie(name);
        playMovie(movieList);
        delete movieList;
    }
        
    else if (argc == 3) {
        if (arg1 != "--reverse") {
            throw runtime_error(arg1 + " is not a valid input");
        }
        string name = argv[2];
        List<pair<int, string>>* movieList = \
            loadMovie(name);
        LinkedList<pair<int, string>>* R_movieList = new \
            LinkedList<pair<int, string>>();
        
        while (!movieList->isEmpty()) {
            R_movieList->insertLast(movieList->removeLast());
        }
        playMovie(R_movieList);
        delete movieList;
        delete R_movieList;
    }
    else {
        throw runtime_error("Incorrect number of command line inputs.");
    }
    return 0;
}
