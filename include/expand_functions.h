
/**
  ******************************************************************************
  * @file    gameoflife/include/expand_functions.h 
  * @author  coder
  * @date    29-October-2018
  * @brief   Header file for src/expand_functions.c file. Contains the 
  * 	     declaration of the functions to dedicated to expand the board.
  ******************************************************************************
**/

#ifndef EXPAND_FUNCS
#define EXPAND_FUNCS

#include "cell_functions.h" // cell functioncs: set, clear, check

/**
 * \brief Sets a cell value to 1
 *
 * This function checks if there is any live cell in the borders 
 * of board "b", which has width "w" and height "h", for allocating
 * more memory if necessary. The function stores if the board has to 
 * grow in any direction in the variables expandUp/Down/Left/Right.
 *
 * \return It returns an int indicating weather the board has to expand or not.
 *	   1 if the board has to grow in any direction and 0 otherwise.
 */
int checkBoardExpansion(char *, int, int , int *, int *, int *, int *);

/**
 * \brief Copies old board information into the expanded board
 *
 * This function takes a board "b" and a board "nb". Board "nb" has 
 * width "w" and height "h", and "b" is smaller than "nb". The function 
 * copies the contents of "b" into "nb" at the right position, taking into 
 * account in which direction(s) "nb" has expanded: up, down, left, right.
 */
void BoardExpansion(char *, char *, int, int, int, int, int, int);

#endif /* EXPAND_FUNCS */
