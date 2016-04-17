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



  int * size = new int;
  string fileName = "first.ppm";
  char * block = intialize(size,fileName); // side effect of initialize changes the value of size
  std::tuple<int,int> center = FindGreenCenter(block, *size);
  printf("avg  %d  avg  %d \n",get<0>(center),get<1>(center) );
  delete[]  block; // de allocate the block of memory.
  delete[]  size;

  int * size2 = new int;
  string fileName2 = "second.ppm";
  char * block2 = intialize(size2,fileName2); // side effect of initialize changes the value of size
  std::tuple<int,int> center2 = FindGreenCenter(block2, *size2);
  printf("avg  %d  avg  %d \n",get<0>(center2),get<1>(center2) );
  delete[]  block2; // de allocate the block of memory.
  delete[]  size2;

  int * size3 = new int;
  string fileName3 = "third.ppm";
  char * block3 = intialize(size3,fileName3); // side effect of initialize changes the value of size
  std::tuple<int,int> center3 = FindGreenCenter(block3, *size3);
  printf("avg  %d  avg  %d \n",get<0>(center3),get<1>(center3) );
  delete[]  block3; // de allocate the block of memory.
  delete[]  size3;




  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;  //clock object time minus start time.
  std::cout<<"duration to process and image: "<< duration <<'\n';
  return 0;
}
