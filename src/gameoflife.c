#include <stdio.h>
#include <stdlib.h> // for calloc (allocate and set to 0)
#include <unistd.h> // for usleep (microseconds)
#include <string.h> // for memset

#include <cell_functions.h>
#include <board_functions.h>
#include <ncurses_functions.h>
#include <expand_functions.h>



// Pointers to the memory where the board info is located
char * board;
char * newBoard;
char * tempPointer;
int width;
int height;
int expandUp;
int expandDown;
int expandLeft;
int expandRight;
int figure;


// Sample program
int main()
{
	// Board size
	// (width must be divisible by 8 as we use char->1 byte->8 bits)
	int width = 16;
	int height = 16;
	int expandUp = 0;
	int expandDown = 0;
	int expandLeft = 0;
	int expandRight = 0;

	// 1 - Allocate memory and set to 0
	board = (char *) calloc(height, width/8);
	newBoard = (char *) calloc(height, width/8);

	// 2 - Select figure
	printf("Select figure:\n1.R-pentomino\n2.Diehard\n3.Acorn\n");
	scanf("%d", &figure);

	switch(figure)
	{
		// R-pentomino
		case(1):
			printf("Selected the R-pentomino\n");
			setCell(board, 2, 1, width, height);
			setCell(board, 3, 1, width, height);
			setCell(board, 1, 2, width, height);
			setCell(board, 2, 2, width, height);
			setCell(board, 2, 3, width, height);
		break;
		// Diehard
		case(2):
			printf("Selected Diehard\n");
			setCell(board, 1, 3, width, height);
			setCell(board, 2, 3, width, height);
			setCell(board, 7, 2, width, height);      
			setCell(board, 2, 4, width, height);
			setCell(board, 6, 4, width, height);
			setCell(board, 7, 4, width, height);
			setCell(board, 8, 4, width, height);
		break;
		// Acorn
		case(3):
			printf("Selected Acorn\n");
			setCell(board, 48, 49, width, height);
			setCell(board, 50, 50, width, height);
			setCell(board, 47, 51, width, height);
			setCell(board, 48, 51, width, height);
			setCell(board, 51, 51, width, height);
			setCell(board, 52, 51, width, height);
			setCell(board, 53, 51, width, height);
		break;
	}
	
	// Initialize NCURSES
	WINDOW *wui = init();

	// 3 - Print first board
	refreshU(board, width, height);
	draw_ui(wui,0);

	// 4 - Perform iterations
	for (int i = 0; i < 5250; i++)
	{
		// 4.1 - sleep for 0.125 seconds
		usleep(125000);
		// 4.2 - update the board and store it in newBoard
		boardIteration(board, newBoard, width, height);

		// 4.3 - switch the contents of board and newBoard
		tempPointer = board;
		board = newBoard;
		newBoard = tempPointer;
		memset(newBoard, 0, height*width/8);

		// 4.4 - Expand board edge if necessary
		int grow = checkBoardExpansion(board, width, height, &expandUp, &expandDown, &expandLeft, &expandRight);
		if (grow)
		{
			height = height + expandUp*8 + expandDown*8;
			width = width + expandLeft*8 + expandRight*8;
			free(newBoard);
			newBoard = (char *) calloc(height, width/8);
			BoardExpansion(board, newBoard, width, height, expandUp, expandDown, expandLeft, expandRight);
			tempPointer = board;
			board = newBoard;
			newBoard = tempPointer;
			free(newBoard);
			newBoard = (char *) calloc(height, width/8);
		}
		
		// 4.5 - print the updated board and the iteration #
		//       and sleep for 0.125 seconds
		usleep(125000);
    		refreshU(board, width, height);
		draw_ui(wui,i);
	}
	
	return 0;
}
