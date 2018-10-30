#ifndef EXPAND_FUNCS
#define EXPAND_FUNCS

#ifndef CELL_FUNCS
#define CELL_FUNCS
#include <cell_functions.h> // cell functioncs: set, clear, check
#endif /* CELL_FUNCS */

int checkBoardExpansion(char *, int, int , int *, int *, int *, int *);

int BoardExpansion(char *, char *, int, int, int, int, int, int);

#endif /* EXPAND_FUNCS */
