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
  return block; // the data from the file is effectively in the buffer.
}


void countGreens(char*  block,int size){
  int count;
  for (size_t i = 15; i < size; i=i+3) {
    unsigned char charval = *(block+i+1); //basic pointer arithmetics
    int value = static_cast<int>(charval);
    if (value > 200) {
      count++;
    }
    // cout<< "counted " << size << " bytes and found " << count<< " 255 value bytes" << endl;
  }
}

std::tuple<int,int> FindGreenCenter(char*  block, int size,int fileWidth, int fileHeight){
  vector<tuple<unsigned,unsigned > >  myvector;
  int sumy=0;
  int sumx=0;
  int yave = 0;
  int xave =0;
  int x = 0;
  int y =0;
  int counter = 0;
  // loop starts at 15 to skip file header. Magic number, file info and end of lines.
  for (int i = 15; i< size; i++){
      unsigned char charval = *(block+i);
      int value = static_cast<int>(charval);
      y = i / fileWidth; // In a contiguos array the current row is contiguous index / column size.
      x = i % fileWidth; // similarily the correct column can be found this way.
      // printf("iterating    [%d][%d]   \n",y,x );

      if(value >100){

        sumy+= y;
        sumx+= x;
        counter++;
        printf("found green   [%d][%d]   \n",y,x );
        //figure out x and y and increment a counter +1 to calculate an average
      }
  }

  for (size_t i = 0; i < 150; i+=3) {
    for (size_t j = 0; j < 150; j+=3) {
      unsigned char charval = *(block+j);
      int value = static_cast<int>(charval);
      unsigned char charval2 = *(block+j+1);
      int value2 = static_cast<int>(charval);
      unsigned char charval3 = *(block+j+2);
      int value3 = static_cast<int>(charval);
      printf("-%d %d %d-",value,value2,value3 );
    }
    printf("\n");
  }
  if(counter >0){
   xave =sumx/counter;
   yave =sumy/counter;
  }
  tuple<int,int> coordinates (xave,yave);
  return coordinates;
}
