#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack_ll.h"
#include "fill.h"
int main(int argc, char *argv[]) {


   	char fName[100];
   	strncpy(fName,argv[1],sizeof(fName));
   	const int MAX_ROWS = 25; 

   	char *world[MAX_ROWS];
   	int numRows;
  	int numCols;

	Stack312 s;
	makeStack(&s);
	
	int row;
	int col;
	char color;
	char origColor;

	populateWorld(fName, world, &numRows, &numCols);	
  	showWorld(world,&numRows,&numCols);

  	int indicator=0;

  	while(indicator==0){

	printf("\nEnter a row: ");
	scanf("%d", &row);
	printf("Enter a column: ");
	scanf("%d",&col);
	printf("Enter a color: ");
	scanf(" %c", &color);  	
	printf("\n");
		
		if((row==-1)||(col==-1))
			indicator=-1;

		else{
			
		StackEntry user;
		user.row=row;
		user.col=col;
		user.color=color;
		origColor=world[row][col];

		StackEntry get;
		
		floodFill(world,user,&numRows,&numCols,&s,origColor);
                get=pop(&s);

		while(!((s.top)==NULL)){
			floodFill(world,get,&numRows,&numCols,&s,origColor);
			get=pop(&s);
		}
	
		printf("%d",numRows);
		printf("%d\n",numCols);
		showWorld(world,&numRows,&numCols);
		}
	}
}
	                               
