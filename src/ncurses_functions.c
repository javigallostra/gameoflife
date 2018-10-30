
#include <ncurses.h>
#include <cell_functions.h>

WINDOW *init(void)
{
	/* This function initialises the ncurses stream.
	*/

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


void draw_ui(WINDOW *wui, int it, int h)
{
	/* This function draws the ui using ncurses.
	*/

	// Clean win

	wrefresh(wui);

	werase(wui);

	wattron(wui, COLOR_PAIR(0));

	// General info

	wmove(wui, h+1, 0);
	
	wprintw(wui, "Iteration: %d\n", it);

	wattroff(wui, COLOR_PAIR(0));

	wrefresh(wui);

	return;
}

void refreshU(char *b, int w, int h)
{
	/* This function draws the board using ncurses.
	*/

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

	refresh();

	return;
}
