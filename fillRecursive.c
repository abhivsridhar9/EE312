bool  onGrid(Pixel temp,int row, int col, int *numRows, int *numCols){
                
                if ((((row))>(*numRows-1))||((col)>(*numCols-1))||(((row))<0)||(((col))<0))
                    return false;
                else
                    return true;

}


void floodFill(char *grid[],Pixel temp,int row, int col, int *numRows, int *numCols,char origColor){
                

              
                if(onGrid(temp,row,col,*numRows,*numCols)){ 
                    if(grid[row][col]!=origColor){
                        return;
                    }

                    grid[temp.row][temp.col]=temp.color;

                    floodFill(grid,temp,temp.row+1,temp.col+1,*numRows,*numCols,origColor);

                    floodFill(grid,temp,temp.row+1,temp.col,*numRows,*numCols,origColor);

                    floodFill(grid,temp,temp.row+1,temp.col-1,*numRows,*numCols,origColor);

                    floodFill(grid,temp,temp.row,temp.col+1,*numRows,*numCols,origColor);

                    floodFill(grid,temp,temp.row,temp.col-1,*numRows,*numCols,origColor);

                    floodFill(grid,temp,temp.row-1,temp.col-1,*numRows,*numCols,origColor);

                    floodFill(grid,temp,temp.row-1,temp.col+1,*numRows,*numCols,origColor);

                    floodFill(grid,temp,temp.row-1,temp.col,*numRows,*numCols,origColor);



                }

}



