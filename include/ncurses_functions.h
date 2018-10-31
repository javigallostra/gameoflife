
/**
  ******************************************************************************
  * @file    gameoflife/include/ncurses_functions.h 
  * @author  coder 3
  * @date    29-October-2018
  * @brief   Header file for src/expand_functions.c file. Contains the 
  * 	     declaration of the functions related to the ncurses.
  ******************************************************************************
**/
#ifndef NCURSES_FUNCS
#define NCURSES_FUNCS

#include <ncurses.h>

/**
 * \brief Initialises the ncurses stream
 *
 */
WINDOW *init(void);

/**
 * \brief Draws the board using ncurses.
 */
void refreshU(char *, int, int, int);

#endif /* NCURSES_FUNCS */
