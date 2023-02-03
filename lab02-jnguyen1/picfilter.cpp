/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>

#include "image.h"
#include "ppmio.h"

using namespace std;

int main(int argc, char** argv) {

    string fileName = argv[1];
    string transformation = argv[2];
    string newFileName = argv[3];

    if (argc != 4)
      cout << "Wrong amount of arguments! Try again please :)" << endl;

    int *pixels = read_ppm(fileName); 
    int width = ppm_width(fileName); 
    int height = ppm_height(fileName);

    if (transformation == "noRed") {
      noRed(width, height, pixels);
    }
    else if (transformation == "noBlue") {
      noBlue(width, height, pixels);
    }
    else if (transformation == "noGreen") {
      noGreen(width, height, pixels);
    }
    else if (transformation == "invert") {
      invert(width, height, pixels);
    }
    else if (transformation == "grayscale") {
      grayscale(width, height, pixels);
    }
    else if (transformation == "flipHorizontally") {
      flipHorizontally(width, height, pixels);
    }
    else if (transformation == "flipVertically") {
      flipVertically(width, height, pixels);
    }
    else {
      cout << "Not a proper transformation. Try again." << endl;
    }

    write_ppm(newFileName, width, height, pixels);

    delete[]pixels;

    return 0;
}
