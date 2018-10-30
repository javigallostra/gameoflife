
#include <cell_functions.h>

int countNeighbors(char * b, int i, int j, int w, int h)
{
	/* This functions counts the live neighbors of a
	cell in board "b", which has width "w" and height "h".
	The area checked is the 8-connected bits around
	the cell located at position (i,j) in the board.
	It returns an int with the # of alive neighbours.
	*/

	// int to store the # of alive neighbours
	int counter = 0;

	// loop through the row above, the row of the cell and the row below
	for (int dj = -1; dj < 2; dj++)
	{
		// if row # not out of bounds
		if ((j + dj >= 0) && (j + dj < h))
		{
			// loop through the column before, the column of the cell and the next column
			for (int di = -1; di < 2; di++)
			{
				// if column # not out of bounds
				if ((i + di >= 0) && (i + di < w))
				{
					// avoid central cell
					if ((di != 0) || (dj != 0))
					{
						counter += checkCell(b, i + di, j + dj, w, h);
					}
				}
			}
		}
	}

	return counter;
}


void boardIteration(char * b, char * nb, int w, int h)
{
	/* This function iterates over the cells in
	board "b", which has width "w" and height "h",
	counting the alive neighbors of each cell.
	It then decides if the cell should revive,
	keep living or die, storing the result in the
	new board "nb", which is the same size as "b".
	"nb" needs to be a board of zeroes.
	*/

	// int to store the number of alive neighbours
	// of the queried cell
	int nalive = 0;

	// For each cell
	for (int j = 0; j < h; j++)
	{
		for (int i = 0; i < w; i++)
		{
			// 1 - Count neighbors
			nalive = countNeighbors(b, i, j, w, h);

			// 2 - Apply GOL rules

			// 2.1 - cell is alive
			if (checkCell(b, i, j, w, h))
			{
				// 2.1.1 - cell survives
				if ((nalive == 2) || (nalive == 3))
				{
					setCell(nb, i, j, w, h);
				}
				// 2.1.2 - cell dies (clear just in case)
				else
				{
					clearCell(nb, i, j, w, h);
				}
			}
			// 2.2 - cell is dead and revives
			else if (nalive == 3)
			{
				setCell(nb, i, j, w, h);
			}
		}
	}

	return;
}
