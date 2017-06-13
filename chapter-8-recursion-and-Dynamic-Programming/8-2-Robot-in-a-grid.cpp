/*
 * Cracking the coding interview edition 6
 * Problem 8-2 Robot in grid
 * In this problem we'll use memoization to keep track of number of paths to that point.
 */

#include <iostream>
using namespace std;

int main()
{
    
    /* Input grid of five rows and six columns as below. 'R' is robot and 'D' is destination.
     'X' is a cell which robot can't pass throgh.
        R - - - - -
        - - - x - -
        x - - - x -
        - x - x - -
        - - - - - D
    */

    int rows=5;                     // Number of rows
    int columns=6;                  // Number of columns
    int grid[rows][columns];        // Create grid of five rows and six columns.
    memset(grid, 0, sizeof(grid));  // Fill 0 to all fields

    // Whereever we we have off limit we fill in -1.
    
    grid[1][3]=-1;
    grid[2][0]=-1;
    grid[2][4]=-1;
    grid[3][1]=-1;
    grid[3][3]=-1;
    
    // Mark initial postion of robot to 1. i.e. number of ways to reach this position.
    
    grid[0][0]=1;
    
    // We will iterate through entire grid once from left to right and from top to bottom.
    // Each time we iterate we will add value from current point to next column and row whever allowed.
    // We can't add anything after last column or last row. We won't add anything to cell that is negative (Off limit)
    
    for (int r=0; r<rows; r++) {
        for (int c=0; c<columns; c++) {
            
            // Iterate over only points that are not 'x'. Skipping if value is -1.
            if (grid[r][c]!=-1) {
                
                // Update right column field if exists. Add value from current point to right column.
                if (c<columns-1 && grid[r][c+1]!=-1) {
                    grid[r][c+1]+=grid[r][c];
                }
                // Update next row field if exists. Add value from current point to next row.
                if (r<rows-1 && grid[r+1][c]!=-1) {
                    grid[r+1][c]+=grid[r][c];
                }
            }
        }
    }
    
    // Last point in grid will hve all possible paths' count.
    // Infact each vslue of the grid represents total number of paths that can be formed to reach destination from robot's location.
    
    cout << grid[rows-1][columns-1] << endl;

    return 0;
}
