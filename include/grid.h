#ifndef GRID_H
#define GRID_H

/**
* @brief Calculates the index by using 
* @parm get row from row index
* @parm get col from column index
* @param get cols from numbers of columns in the grid
* @return Flat 1D indec (row * cols + col).
*/

int grid_index(int row, int col, int cols);

/**
* @brief Check if the given row and column is within grid boundaries
* @param row Row index to check.
* @param col Column index to check.
* @param rows from total number of rows in the grid
* @param cols from total number of columns in the grid
* @return True if 0 <= row < rows and 0 <= col < cols, 
  otherwise return false
*/

bool in_bounds(int row, int col, int rows, int cols);


#endif // GRID_H
