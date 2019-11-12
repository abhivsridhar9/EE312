#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fill.h"
int main(int argc, char *argv[]) {


   	char fName[100];
   	strncpy(fName,argv[1],sizeof(fName));
   	const int MAX_ROWS = 40; 

   	char *world[MAX_ROWS];
   	int numRows;
  	int numCols;

	
	int uRow;
	int uCol;
	char uColor;
	char origColor;

	populateWorld(fName, world, &numRows, &numCols);	
  	showWorld(world,&numRows,&numCols);

  	int indicator=0;

  	while(indicator==0){

	printf("\nEnter a row: ");
	scanf("%d", &uRow);
	printf("Enter a column: ");
	scanf("%d",&uCol);
	printf("Enter a color: ");
	scanf(" %c", &uColor);  	
	printf("\n");

	origColor=world[uRow][uCol];	
		floodFill(world,uColor,uRow,uCol,&numRows,&numCols,origColor);	
		showWorld(world,&numRows,&numCols);
		}
	
}
	                               
