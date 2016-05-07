#ifndef __FUNCTIONS_H_INCLUDED__
#define __FUNCTIONS_H_INCLUDED__
///////////////////////////////
//forward declared dependencies such as classes

///////////////////////////////
//included dependencies

///////////////////////////////
//classes and functions declarations
char * intialize(int * sizeblock,std::string fileName);
void countGreens(char*  block,int size);
std::tuple<int,int> FindGreenCenter(char*  block, int size,int fileWidth, int fileHeight);

#endif
