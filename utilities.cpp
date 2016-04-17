#include <fstream> // file i/o
#include <array>
#include <stdio.h> // get rid of this
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <tuple>


using namespace std;
char * intialize(int * sizeblock,string fileName){
  streampos size; //the size in bytes of the file to be opened
  ifstream myfile (fileName, ios::in|ios::binary|ios::ate); // open the file in binary mode (trust me do it)
  size = myfile.tellg();  //save syze of byte in bytes
  // cout << "file size is " << size << endl;
  char * block = new char[size]; // pay attention. this line says make a char pointer, allocate a new array of chars of with the given size
  //the size has to be defined at compile time, the information will now be on the heap
  myfile.seekg (0, ios::beg); // look for the beginning of file
  myfile.read (block,size); //read the block
  myfile.close(); //file is no longer needed
  *sizeblock = size;
  return block;
}
void countGreens(char*  block,int size){
  int count;
  for (size_t i = 15; i < size; i=i+3) {
  unsigned char charval = *(block+i+1); //basic pointer arithmetics
  int value = static_cast<int>(charval);
  if (value > 200) {
    count++;
  }
  cout<< "counted " << size << " bytes and found " << count<< " 255 value bytes" << endl;
}
}

std::tuple<int,int> FindGreenCenter(char*  block, int size){
  vector<tuple<unsigned,unsigned > >  myvector;

  int sumy=0;
  int sumx=0;
  int yave = 0;
  int xave =0;
  int x = 0;
  int y =0;
  int counter = 0;
  // printf("verify:  sumy %d  sumx %d  yave  %d xave %d  x %d  y  %d  counter  %d \n ",sumy, sumx,yave,xave,x,y,counter); //this line will help you debug at specific points.

    for (int i = 15; i< size; i=i+3){
      // printf("verify:  sumy %d  sumx %d  yave  %d xave %d  x %d  y  %d  counter  %d \n",sumy, sumx,yave,xave,x,y,counter); //this line will help you debug at specific points.

    if(x!=0 && x%800 ==0 ){ // change this to the actual width
      x =0;y++;
      unsigned char charval = *(block+i+1); //basic pointer arithmetics
      int value = static_cast<int>(charval);
      if(value >200){
        sumy += y;
        sumx += x;
        counter ++;
      }
    }
    else{
      x++;
      unsigned char charval = *(block+i+1); //basic pointer arithmetics
      int value = static_cast<int>(charval);
      if(value>200){
        sumy += y;
        sumx += x;
        counter ++;
      }
    }
  }
  // printf("verify:  sumy %d  sumx %d  yave  %d xave %d  x %d  y  %d  counter  %d \n",sumy, sumx,yave,xave,x,y,counter); //this line will help you debug at specific points.

  if(counter >0){
   xave =sumx/counter;
   yave = sumy/counter;
 }
    // cout<<"counter " << counter << " sum y "<< sumy << " sumx " << sumx << endl;

  tuple<int,int> coordinates (xave,yave);
  return coordinates;
}
