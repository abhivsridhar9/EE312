#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);
void showWorld(char *grid[], int *numRows, int *numCols);
bool  onGrid(int row, int col, int *numRows, int *numCols);
void floodFill(char *grid[],char uColor,int row, int col, int *numRows, int *numCols,char origColor);
