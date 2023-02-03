/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "image.h"

#include <iostream>
using namespace std;

int pixelToIndex(int width, int x, int y) {
    int index = int (y*width*3)+(3*x);
  return  index;
}

void noRed(int width, int height, int* ppm) {
    for (int i=0; i <= width; i++) {
        for (int j=0; j <= height; j++) {
           ppm[pixelToIndex(width,i,j)] = 0;
      }
    }
}

void noGreen(int width, int height, int* ppm) {
    for (int i=0; i <= width; i++) {
        for (int j=0; j <= height; j++) {
           ppm[pixelToIndex(width,i,j)+1] = 0;
      }
    }
}


void noBlue(int width, int height, int* ppm) {
    for (int i=0; i <= width; i++) {
        for (int j=0; j <= height; j++) {
           ppm[pixelToIndex(width,i,j)+2] = 0;
      }
    }
}


void invert(int width, int height, int* ppm) {
    for (int i=0; i <= width*height*3; i++) {
      ppm[i] = 255 - ppm[i];
    }
}

void grayscale(int width, int height, int* ppm) {
    for (int i=0; i <= width*height*3; i = i + 3) {
      int sum = ppm[i] + ppm[i+1] + ppm[i+2];
      int average = sum/3;
      ppm[i] = average;
      ppm[i+1] = average;
      ppm[i+2] = average;
    }
}

void flipHorizontally(int width, int height, int* ppm) {
    for(int i=0; i<height; i++) {
      for(int j=0; j <= (width/2) - 1; j++) {
        int x;
        x = ppm[pixelToIndex(width,j,i)];
        ppm[pixelToIndex(width,j,i)] = ppm[pixelToIndex(width,(width-1-j),i)];
        ppm[pixelToIndex(width, (width-1-j), i)] = x;

        x = ppm[pixelToIndex(width,j,i)+1];
        ppm[pixelToIndex(width,j,i)+1] =
            ppm[pixelToIndex(width,(width-1-j),i)+1];
        ppm[pixelToIndex(width, (width-1-j), i)+1] = x;

        x = ppm[pixelToIndex(width,j,i)+2];
        ppm[pixelToIndex(width,j,i)+2] =
            ppm[pixelToIndex(width,(width-1-j),i)+2];
        ppm[pixelToIndex(width, (width-1-j), i)+2] = x;
      
      }
    } 
}

void flipVertically(int width, int height, int* ppm) {
    for(int i=0; i<width; i++) {
      for(int j=0; j <= (height/2) - 1; j++) {
        int x;
        x = ppm[pixelToIndex(width,i,j)];
        ppm[pixelToIndex(width,i,j)] = ppm[pixelToIndex(width,i,(height-1-j))];
        ppm[pixelToIndex(width,i,(height-1-j))] = x;

        x = ppm[pixelToIndex(width,i,j)+1];
        ppm[pixelToIndex(width,i,j)+1] =
            ppm[pixelToIndex(width,i,(height-1-j))+1];
        ppm[pixelToIndex(width, i, (height-1-j))+1] = x;

        x = ppm[pixelToIndex(width,i,j)+2];
        ppm[pixelToIndex(width,i,j)+2] =
            ppm[pixelToIndex(width,i,(height-1-j))+2];
        ppm[pixelToIndex(width, i, (height-1-j))+2] = x;
      
      }
    } 
}
