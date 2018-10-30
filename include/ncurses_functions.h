
/**
  ******************************************************************************
  * @file    gameoflife/include/ncurses_functions.h 
  * @author  coder
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
 * \brief Draws the ui using ncurses.
 */
void draw_ui(WINDOW *,int);

/**
 * \brief Draws the board using ncurses.
 */
void refreshU(char *, int, int);

#endif /* NCURSES_FUNCS */
