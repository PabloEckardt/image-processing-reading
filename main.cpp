#include <fstream> // file i/o
#include <array>
#include <stdio.h> // get rid of this
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <tuple>
#include "header.h"
using namespace std;
int main(){

  std::clock_t start; //clock object.
  double duration;
  start = std::clock();//clock objects starts counting.


  int fileWidth = 50;
  int fileHeight = 50;
  int * size = new int;
  string fileName = "tiny_green_dot.ppm";
  char * block = intialize(size,fileName); // side effect of initialize changes the value of size

  std::tuple<int,int> center = FindGreenCenter(block, *size,fileWidth,fileHeight);
  printf("avg x %d  avg y  %d \n",get<0>(center),get<1>(center) );
  delete[]  block; // de allocate the block of memory.
  delete[]  size;



  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;  //clock object time minus start time.
  std::cout<<"duration to process and image: "<< duration <<'\n';
  return 0;
}
