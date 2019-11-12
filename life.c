#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "life.h"

	//extracts world from text file to grid array of characters, and determines dimensions
	void populateWorld(char fname[], char *grid[], int *numRows, int *numCols){
                *numRows=0;
                *numCols=0;
                FILE *fptr;
                fptr=fopen(fname,"r");
                if(fptr==NULL)
                {
                        printf("can't open file\n");
                }
                else
                {
                        char buf[BUFSIZ];
                        while(fgets(buf,sizeof(buf),fptr))
                        {
                         	//subtract one from length of buffer to account for the null terminator at end of line
			        *numCols=strlen(buf)-1;
				//allocate space by creating pointers for each row of strings
                                char *s=(char *)malloc((*numCols)*sizeof(char));
                                strcpy(s,buf);
                                grid[*(numRows)]=s;
                                (*numRows)++;
                        }

                        fclose(fptr);
                }
        }
	


	//prints world after converting 1's and 0's to *'s and .'s
	void showWorld(char *grid[], int *numRows, int *numCols){
		for(int i=0;i<(*numRows);i++){
			for(int j=0;j<(*numCols);j++){
				if(grid[i][j]=='1'){
					printf("*");
				}
				else{
					printf(".");
				}
			}
			printf("\n");	
		}
	}



	//determines if the conditions being checked when determining number of neighbors is on the grid or out of bounds
	int onGrid(int row, int col ,int tempRow, int tempCol){
		//variable to determine cell being checked is on screen or not
		int location=0;
		location=((row>=0 && row<(tempRow)) && (col>=0 && col<(tempCol)));
		//0 returned if out of bounds, 1 returned if in bounds
		return location;
	}



	//determines number of alive neighbors a cell has 
	int numNeighbors(char *grid[],int row, int col,int tempRow,int tempCol){
		int neighborCount=0;
		//loop checks each cell to calculate number of neighbors	
		//i and j used as bounds to ensure that the cell being checked is on the array
		//acts as border around the cell being checked		
		for (int i = -1; i <= 1; i++){
 	     		 for (int j = -1; j <= 1; j++){
	 	                if (!(i == 0 && j == 0) && onGrid(row+i,col+j,tempRow,tempCol) && grid[row+i][col+j] == '1')
                                               neighborCount++;
                         }
		}
         	return neighborCount;                                          
	}		
	


	//uses number of neighbors to determine if cell is alive or dead
	int isAlive(char *grid[],int row, int col,int tempRow,int tempCol){
		int neighborCount=0;
		neighborCount=numNeighbors(grid,row,col,tempRow,tempCol);
		if((neighborCount>3)||(neighborCount<2))
			return 0;
		return 1;
	}



	//creates next iteration of the world by creating a temporary grid with new values based on status of cell
	//copies the temporary grid over to the world to finalize iteration
	void  iterateGeneration(char *grid[], int *numRows, int *numCols){
		char **tempGrid=malloc((*numRows)*sizeof(*tempGrid));
		int status=0;
		int tempRow=*numRows;
		int tempCol=*numCols;
		for(int i=0; i<*numRows;i++){
			tempGrid[i]=malloc((*numCols)*sizeof(**tempGrid));
			for(int j=0;j<*numCols;j++){
				status=isAlive(grid,i,j,tempRow,tempCol);
				if(status==1){
					tempGrid[i][j]='1';
				}
				else{
					tempGrid[i][j]='0';
				}
			}
		}
		//copy over tempGrid into the world
		for(int k=0; k<*numRows;k++){
			for(int m=0;m<*numCols;m++){
				grid[k][m]=tempGrid[k][m];	
			}
		}	
		//free space allocated for the tempGrid
		for(int n=0;n<tempRow;n++){
			free(tempGrid[n]);
		}
	}

