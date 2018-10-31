
/**
  ******************************************************************************
  * @file    gameoflife/include/cell_functions.h 
  * @author  coder
  * @date    29-October-2018
  * @brief   Header file for src/cells_functions.c file. Contains the 
  * 	     declaration of the functions to set or check values of cells.
  ******************************************************************************
**/

#ifndef CELL_FUNCS
#define CELL_FUNCS

/**
 * \brief Sets a cell value to 1
 *
 * This function sets the value of a cell (bit) to 1
 * in the board "b", which has width "w" and height "h".
 * The bit set is at position (i,j) in the board.
 */
void setCell(char *, int, int, int, int);

/**
 * \brief Sets a cell value to 0
 *
 * This function sets the value of a cell (bit) to 0
 * in the board "b", which has width "w" and height "h".
 * The bit set is at position (i,j) in the board.
 **/
void clearCell(char *, int, int, int, int);

/**
 * \brief Returns the value of a cell
 *
 * This function returns the value of a cell (bit)
 * in the board "b", which has width "w" and height "h".
 * The bit checked is at position (i,j) in the board.
 *
 * \return returns the cell value.
 **/
int checkCell(char *, int, int, int, int);

#endif /* CELL_FUNCS */
