
/**
  ******************************************************************************
  * @file    gameoflife/src/ncurses_functions.c
  * @author  coder
  * @date    29-October-2018
  * @brief   This file contains the functions related with the ncurses library.
  ******************************************************************************
**/
#include <ncurses.h>
#include <cell_functions.h>

// This function initialises the ncurses stream.
WINDOW *init(void)
{
	int bg = COLOR_BLACK;

	/* Init ncurses */
	initscr();
	noecho();
	raw();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
	start_color();
	clear();

	if(use_default_colors() == OK)
	bg = -1;

	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, bg, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_GREEN, bg);
	init_pair(5, COLOR_RED, bg);

	WINDOW *wui = newwin(1, COLS, LINES - 1, 0);
	wmove(wui, 0, 0);
	wrefresh(wui);

	refresh();

	return wui;
}

// This function draws the board using ncurses.
void refreshU(char *b, int w, int h, int it)
{
	for(int j = 0; j < h; j++)
	{
		for(int i = 0; i < w; i++)
		{
			// draw full byte
			for (int k = 7; k>=0; k--)
			{
				attron(checkCell(b,i,j,w,h) ? COLOR_PAIR(2) : COLOR_PAIR(3));
				mvprintw(j,i, " ");
				attroff(checkCell(b,i,j,w,h) ? COLOR_PAIR(2) : COLOR_PAIR(3));
			}
		}
	}

	attron(COLOR_PAIR(0));
	mvprintw(h+1, 0, "Iteration: %d\n", it);
	attroff(COLOR_PAIR(0));

	refresh();
}
