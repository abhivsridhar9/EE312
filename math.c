#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack_arg.h"
#include "math.h"

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


void recordItems(char *grid[],int *numRows, int *numCols,Stack312 *s){
	int fParan=0;
	int fBrack=0;
	int fAngle=0;	

	int cParan=0;
	int cBrack=0;
	int cAngle=0;
	
	for(int i=0;i<(*numRows);i++){

	for(int j=0;j<(*numCols);j++){
	
		
	if((grid[i][j]=='('))
	{
		push('(',s);
		fParan=1;
		cParan++;
	
	}
	else if((grid[i][j]==')'))
	{
		pop(s);
		fParan=0;
		cParan++;	
	}
	
	if((grid[i][j]=='['))
        {
                push('[',s);
                fBrack=1;
		cBrack++;
        }
        else if((grid[i][j]==']'))
        {
                pop(s);
         	fBrack=0;  
		cBrack++;    
        }	
	
	if((grid[i][j]=='<'))
        {
                push('<',s);
                fAngle=1;
		cAngle++;	
        }
        else if((grid[i][j]=='<'))
        {
                pop(s);
         	fAngle=0;
		cAngle++;	       
        }
	}

	
	if(s->top!=-1){
		if((cParan%2)!=0)
		{
			if(fParan==1){
			printf(grid[i]);
			printf("=== missing )");
			}	
			
			else{
                        printf(grid[i]);
                        printf("=== missing (");
                        }
		}
		
		if((cBrack%2)!=0)
                {
                        if(fBrack==1){
                        printf(grid[i]);
                        printf("=== missing ]");
                        }
        
                        else{
                        printf(grid[i]);
                        printf("=== missing [");
                        }
                }
		
		if((cAngle%2)!=0)
                {
                        if(fAngle==1){
                        printf(grid[i]);
                        printf("=== missing >");
                        }
        
                        else{
                        printf(grid[i]);
                        printf("=== missing <");
                        }
                }
	}	
	else
	{
		printf(grid[i]);
                printf("=== valid expression"); 
	}
	
}	
}

