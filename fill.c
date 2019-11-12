#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fill.h"

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols){
                *numRows=0;
                *numCols=0;
                FILE *fptr;
                fptr=fopen(fname,"r");
                if(fptr==NULL)
                {
                        printf("Can't open file\n");
                }
                else
                {
                        char buf[BUFSIZ];
                        while(fgets(buf,sizeof(buf),fptr)){
				*numCols=strlen(buf)-1;
				char *s=(char *)malloc((*numCols)*sizeof(char));
                                strcpy(s,buf);
                                grid[*(numRows)]=s;
                                (*numRows)++;
			}
			
			fclose(fptr);
		}
}

void showWorld(char *grid[], int *numRows, int *numCols){
		for(int i=0;i<(*numRows);i++){
			for(int j=0;j<(*numCols);j++){
				printf("%c",grid[i][j]);
			}
			printf("\n");	
		}
}

bool  onGrid(int row, int col, int *numRows, int *numCols){
                
                if ((((row))>(*numRows-1))||((col)>(*numCols-1))||(((row))<0)||(((col))<0))
                    return false;
                else
                    return true;

}


void floodFill(char *grid[],char uColor,int row, int col, int *numRows, int *numCols,char origColor){
                

              
                    if(onGrid(row,col,numRows,numCols)){ 
                    if(grid[row][col]!=origColor){
                        return;
                    }

                    grid[row][col]=uColor;

                    floodFill(grid,uColor,row+1,col+1,numRows,numCols,origColor);

                    floodFill(grid,uColor,row+1,col,numRows,numCols,origColor);

                    floodFill(grid,uColor,row+1,col-1,numRows,numCols,origColor);

                    floodFill(grid,uColor,row,col+1,numRows,numCols,origColor);

                    floodFill(grid,uColor,row,col-1,numRows,numCols,origColor);

                    floodFill(grid,uColor,row-1,col-1,numRows,numCols,origColor);

                    floodFill(grid,uColor,row-1,col+1,numRows,numCols,origColor);

                    floodFill(grid,uColor,row-1,col,numRows,numCols,origColor);



		    }

}
