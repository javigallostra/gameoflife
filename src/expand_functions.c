
/**
  ******************************************************************************
  * @file    gameoflife/src/expand_functions.c
  * @author  coder
  * @date    29-October-2018
  * @brief   This file contains the functions dedicated to the expansion
  *	     of the board.
  ******************************************************************************
**/

#include <cell_functions.h>

int checkBoardExpansion(char * b, int w, int h, int * expandUp, int * expandDown, int * expandLeft, int * expandRight)
{
	/* This function checks if there is any live cell
	in the borders of board "b", which has width "w"
	and height "h", for allocating more memory if
	necessary.
	The function stores if the board has to grow in
	any direction in the variables expandUp/Down/Left/Right.
	It also returns an int which is 1 if the board
	has to grow in any direction and 0 otherwise.
	*/
	
	*expandUp = 0;
	*expandDown = 0;
	*expandLeft = 0;
	*expandRight = 0;
	
	int maxh = 64;
	int maxw = 64;

	// Check expandUp (i = [0, width], j = 0)
	for (int i = 0; i < w; i++)
	{
		if (checkCell(b, i, 0, w, h) && h < maxh)
		{
			*expandUp = 1;
			break;
		}

	}
	// Check expandDown (i = [0, width], j = height)
	for (int i = 0; i < w; i++)
	{	
		if (checkCell(b, i, h-1, w, h) && h < maxh)
		{
			*expandDown = 1;
			break;
		}	
	}

	// Check expandLeft (i = 0, j = [0, height])
	for (int j = 0; j < h; j++)
	{
		if (checkCell(b, 0, j, w, h) && w < maxw)
		{
			*expandLeft = 1;
			break;
		}	
	}

	// Check expandRight (i = width, j = [0, height])
	for (int j = 0; j < h; j++)
	{
		if (checkCell(b, w-1, j, w, h) && w < maxw)
		{
			*expandRight = 1;
			break;
		}
	}

	// Return if the board needs to grow or not
	if (*expandUp || *expandDown || *expandLeft || *expandRight)
	{	
		return 1;
	}
	else
	{
		return 0;
	}	
}


void BoardExpansion(char * b, char * nb, int w, int h, int expandUp, int expandDown, int expandLeft, int expandRight)
{
	/* This function takes a board "b" and a board "nb".
	"nb" has width "w" and height "h", and "b" is smaller
	than "nb".
	The function copies the contents of "b" into "nb" at
	the right position, taking into account in which
	direction(s) "nb" has expanded: up, down, left, right.
	*/

	// Loop through the cells of nb which must be updated
	for (int j = expandUp*8; j < (h - expandDown*8); j++) 
	{
		for (int i = expandLeft*8; i < (w - expandRight*8); i++) 
		{
			// Here we compute the w,h values of b (smalles than nb)
			int bw = w - expandRight*8 - expandLeft*8;
			int bh = h - expandDown*8 - expandUp*8;
			// Get value of cell in b and set it in nb
			if (checkCell(b, (i - expandLeft*8), (j - expandUp*8), bw, bh))
			{
				setCell(nb, i, j, w, h);
			}
		}
	}
}
