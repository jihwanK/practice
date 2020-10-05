// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
int r = 0;
int c = 0;

void check(int **grid, int x_pos, int y_pos)
{
    if (grid[x_pos][y_pos] == 1)
    {
        grid[x_pos][y_pos] = 0;
        if (x_pos-1 >= 0 && x_pos < r)
            check(grid, x_pos-1, y_pos);
        if (x_pos+1 >= 0 && x_pos < r)
            check(grid, x_pos+1, y_pos);
        if (y_pos-1 >= 0 && y_pos < c)
            check(grid, x_pos, y_pos-1);
        if (y_pos+1 >= 0 && y_pos < c)
            check(grid, x_pos, y_pos+1);
    }
}

int numberAmazonGoStores( int rows, int column, int **grid)
{
    // WRITE YOUR CODE HERE
    
    int numStores = 0;
    
    r = rows;
    c = column;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (grid[i][j] == 1)
            {
                check(grid, i, j);
                numStores++;
            }
        }
    }
    
    return numStores;
}


int main()
{
  int abc[7][7] = {{1,0,0,0,0,0,0}, {0,1,0,0,0,0,0}, {0,0,1,0,0,0,0}, {0,0,0,1,0,0,0}, {0,0,0,0,1,0,0}, {0,0,0,0,0,1,0}, {0,0,0,0,0,0,1}};
  printf("%d \n", numberAmazonGoStores(7,7,abc));
}
// FUNCTION SIGNATURE ENDS