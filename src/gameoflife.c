
/**
  ******************************************************************************
  * @file    gameoflife/src/gameoflife.c
  * @author  coder
  * @date    29-October-2018
  * @brief   This file corresponds to the main file of the game of life project.
  ******************************************************************************
**/

#include <stdio.h>
#include <stdlib.h> // for calloc (allocate and set to 0)
#include <unistd.h> // for usleep (microseconds)
#include <string.h> // for memset

#include "cell_functions.h"
#include "board_functions.h"
#include "ncurses_functions.h"
#include "expand_functions.h"


// Pointers to the memory where the board info is located
char * board;
char * newBoard;
char * tempPointer;
// Board size parameters
int width;
int height;
// Board edge expansion parameters
int expandUp;
int expandDown;
int expandLeft;
int expandRight;
// Simulation figure parameters
int iteration;
int figure;
int speed;
int valid_fig=0;
int valid_spd=0;
int key_press=0;
int wait_ms=0;

// Main function
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

	// 2.1 - Select figure
	printf("Select figure:\n1.R-pentomino\n2.Diehard\n3.Acorn\n");
	scanf("%d", &figure);

	while(valid_fig==0)
	{
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
				valid_fig=1;
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
				valid_fig=1;
			break;
			// Acorn
			case(3):
				printf("Selected Acorn\n");
				setCell(board, 1, 4, width, height);
				setCell(board, 2, 4, width, height);
				setCell(board, 2, 2, width, height);
				setCell(board, 4, 3, width, height);
				setCell(board, 5, 4, width, height);
				setCell(board, 6, 4, width, height);
				setCell(board, 7, 4, width, height);
				valid_fig=1;
			break;
			//Non valid figure
			default:
				printf("Sorry, not a valid option.\n");
				printf("Select figure:\n1.R-pentomino\n2.Diehard\n3.Acorn\n");
				scanf("%d", &figure);
			break;
		}
	}

	// 2.2 - Select speed
	printf("\nSelect speed:\n1.Very fast\n2.Fast\n3.Slow\n");
	scanf("%d", &speed);

	while(valid_spd==0)
	{
		switch(speed)
		{
			// R-pentomino
			case(1):
				printf("Selected Very Fast\n");
				wait_ms = 62500;
				valid_spd=1;
			break;
			// Diehard
			case(2):
				printf("Selected Fast\n");
				wait_ms = 125000;
				valid_spd=1;
			break;
			// Acorn
			case(3):
				printf("Selected Slow\n");
				wait_ms = 250000;
				valid_spd=1;
			break;
			//Non valid figure
			default:
				printf("Sorry, not a valid option.\n");
				printf("Select speed:\n1.Very fast\n2.Fast\n3.Slow\n");
				scanf("%d", &speed);
			break;
		}
	}
	
	printf("\n--- Start game of life ---\n");
	printf("---Press Escape to stop---\n");
	sleep(2);

	// Initialize NCURSES
	init();

	// 3 - Print first board
	refreshU(board, width, height, 0);
	sleep(1);

	// 4 - Perform iterations
	for (int i = 1; i < 5250; i++)
	{
		// 4.1 - sleep
		usleep(wait_ms);
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
    		refreshU(board, width, height, iteration);
		iteration=i;
		
		// 4.6 - if the escape key is pressed, stop the program
		if ((key_press = getch()) == 263)
		{  
			nodelay(stdscr, false);
			clear();
			break;
		}
	}

	// 5 - End ncurses
	endwin();
	printf("---Game of life ended at iteration %d---\n",iteration);

	// 6 - Free memory
	free(board);
	free(newBoard);
	return 0;
}
