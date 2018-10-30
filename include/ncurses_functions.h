#ifndef NCURSES_FUNCS
#define NCURSES_FUNCS

#include <ncurses.h>

WINDOW *init(void);

void draw_ui(WINDOW *,int);

void refreshU(char *, int, int);

#endif /* NCURSES_FUNCS */
