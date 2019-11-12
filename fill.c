#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack_ll.h"
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

bool  onGrid(Pixel temp,int tempRow, int tempCol,int rCount, int cCount){
                
                if ((((temp.row+rCount))>(tempRow-1))||(((temp.col)+cCount)>(tempCol-1))||(((temp.row)+rCount)<0)||(((temp.col)+cCount)<0))
                    return false;
                else
                    return true;

}
void floodFill(char *grid[],Pixel temp,int *numRows, int *numCols,Stack312 *s,char origColor){
		
	        grid[temp.row][temp.col]=temp.color;
		Pixel local;
		int count=0;////GET RID OF THIS
                local.row=0;
                local.col=0;
                
                for (int i = -1; i <= 1; i++){
                         for (int j = -1; j <= 1; j++){
                              	if((((temp.row)+i)>(*numRows-1))||(((temp.col)+j)>(*numCols-1))||(((temp.row)+i)<0)||(((temp.col)+j)<0))
				{
				//stack not updated
				}
				else if((grid[temp.row+i][temp.col+j]==origColor))
                                {    
                                        local.row=(temp.row)+i;
					local.col=(temp.col)+j;
					local.color=temp.color;
					push(local,s);							  	                                             
                                }		
                         }
                }
}

