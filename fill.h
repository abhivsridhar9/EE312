#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);
void showWorld(char *grid[], int *numRows, int *numCols);
bool  onGrid(Pixel temp,int tempRow, int tempCol);
void floodFill(char *grid[],Pixel temp,int *numRows, int *numCols,Stack312 * s,char origColor);

