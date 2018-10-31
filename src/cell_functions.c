
/**
  ******************************************************************************
  * @file    gameoflife/src/cell_functions.c
  * @author  coder 1
  * @date    29-October-2018
  * @brief   This file contains the functions to set or check values of cells.
  ******************************************************************************
**/

// Set the value of a cell (i, j) -> set it to 1
void setCell (char * b, int i, int j, int w, int h)
{
	/* This function sets the value of a cell (bit) to 1
	in the board "b", which has width "w" and height "h".
	The bit set is at position (i,j) in the board.
	*/

	if (i < 0 || w-1 < i)
	{
		// For debugging
		// perror("Array index i out of bounds.");
	}
	else if (j < 0 || h-1 < j)
	{
		// For debugging
		// perror("Array index j out of bounds."); 
	}
	else
	{
		b[j*w/8 + i/8] |= ((char) 1 << (i%8));
	}

	return;
}


void clearCell (char * b, int i, int j, int w, int h)
{
	/* This function sets the value of a cell (bit) to 0
	in the board "b", which has width "w" and height "h".
	The bit set is at position (i,j) in the board.
	*/

	if (i < 0 || w-1 < i)
	{
		// For debugging
		// perror("Array index i out of bounds.");
	}
	else if (j < 0 || h-1 < j)
	{
		// For debugging
		// perror("Array index j out of bounds."); 
	}
	else
	{
		b[j*w/8 + i/8] &= ~((char) 1 << (i%8));
	}

	return;
}


int checkCell (char * b, int i, int j, int w, int h)
{	
	/* This function returns the value of a cell (bit)
	in the board "b", which has width "w" and height "h".
	The bit checked is at position (i,j) in the board.
	*/

	if (i < 0 || w-1 < i)
	{
		// For debugging
		// perror("Array index i out of bounds.");
		return 0;
	}
	else if (j < 0 || h-1 < j)
	{
		// For debugging
		// perror("Array index j out of bounds."); 
		return 0;
	}
	else
	{
		return (int) (b[j*w/8+i/8] & ((char) 1 << (i%8))) != 0;
	}
	return 0;
}
