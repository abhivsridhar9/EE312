// life.h
// -- EE 312 Project 2

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
 *///
// Created by priebe on 9/5/2018.
//

#ifndef UNTITLED1_LIFE_H
#define UNTITLED1_LIFE_H

#endif //UNTITLED1_LIFE_H



	void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);
	
	void showWorld(char *grid[], int *numRows, int *numCols);

	int onGrid(int row, int col ,int tempRow, int tempCol);
	
	int numNeighbors(char *grid[],int row, int col,int tempRow,int tempCol);

	int isAlive(char *grid[],int row, int col,int tempRow,int tempCol);

	void  iterateGeneration(char *grid[], int *numRows, int *numCols);
