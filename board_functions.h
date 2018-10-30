#ifndef BOARD_FUNCS
#define BOARD_FUNCS

#ifndef CELL_FUNCS
#define CELL_FUNCS
#include <cell_functions.h> // cell functions: set, clear, check
#endif /* CELL_FUNCS */

int countNeighbors(char *, int, int, int, int);

void boardIteration(char *, char *, int, int);

#endif /* BOARD_FUNCS */
