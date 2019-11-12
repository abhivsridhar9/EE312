//life_driver.c
//
//Life Driver program
//Roger Priebe 9/5/2018
//EE 312


/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Abhishek Sridhar, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Abhishek Sridhar
 * email address: sridhar.abhishek@utexas.edu
 * UTEID: as83788
 * Section 5 digit ID: 16016
 *
 */

//This file is a driver program for the life.c module.
//This program must work with your implementations life.h and life.c
//Do not change the function definitions for populateWorld, showWorld or
//iterateGeneration.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "life.h"


int main(int argc, char *argv[]) {

   //edit these two lines and use the command line arguments
   char fName[100];

   //copies the first parameter into string fName to be used by populateWorld
   strncpy(fName,argv[1],sizeof(fName));

   //number of iterations passed by a user
   const int numGenerations  = atoi(argv[2]); //set to a smaller number for debugging
    
   const int MAX_ROWS = 80; //we want the world to fit on one screen

   //array of strings that will hold the grid
   char *world[MAX_ROWS];
   int numRows;
   int numCols;

   populateWorld("world.txt", world, &numRows, &numCols);	
   showWorld(world,&numRows,&numCols);
   
   //produces number of iteration specified by the user
   for (int iteration = 0; iteration < numGenerations; iteration++) {

     //clears screen for each subsequent iteration	
     system("clear");
     iterateGeneration(world, &numRows, &numCols);
     showWorld(world,&numRows, &numCols);
    
  }	

  //free space allocated in heap for the world
  for(int i=0;i<(numRows);i++){
	free(world[i]);
  } 
  
  return 0;
}



