/**
  ******************************************************************************
  * @file    gameoflife/include/board_functions.h 
  * @author  coder
  * @date    27-October-2018
  * @brief   This file is the header file for src/board_functions.c file.
	     Contains the declaration of the functions concerning game of life rules.
  ******************************************************************************
**/

#ifndef BOARD_FUNCS
#define BOARD_FUNCS

#include "cell_functions.h" // cell functions: set, clear, check

/**
 * \brief Counts the number of live neighbor of a cell.
 *
 * This functions counts the live neighbors of a
 * cell in board "b", which has width "w" and height "h".
 * The area checked is the 8-connected bits around
 * the cell located at position (i,j) in the board.
 * 
 * \return It returns an int with the # of alive neighbours.
 *
 */

int countNeighbors(char *, int, int, int, int);

/**
 * \brief Decides if a cell lives, dies or revives.
 *
 * This function iterates over the cells in board "b", 
 * which has width "w" and height "h", counting the alive 
 * neighbors of each cell. It then decides if the cell should 
 * revive, keep living or die, storing the result in the
 * new board "nb", which is the same size as "b".
 * "nb" needs to be a board of zeroes.
 */
void boardIteration(char *, char *, int, int);

#endif /* BOARD_FUNCS */
