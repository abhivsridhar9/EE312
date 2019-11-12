#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack_arg.h"
#include "math.h"
int main(int argc, char *argv[]) {


   	char fName[100];
   	strncpy(fName,argv[1],sizeof(fName));
   	const int MAX_CHAR = 80; 

   	char *world[MAX_CHAR];
	int numRows;
  	int numCols;   	

	Stack312 s;
	makeStack(&s);
	
	populateWorld(fName, world, &numRows, &numCols);	


	recordItems(world,&numRows,&numCols,&s);
		
}
	                               
