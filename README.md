# Game of life project

This project is part of the course avaluation of the subject Embedded & real time systems from the Master's degree in Automatic Control and Robotics. It implements the game of life with C language.
Authors:
* Javier Gallostra      (javier.gallostra@estudiant.upc.edu)
* Irene Garcia Camacho  (irene.garcia.camacho@estudiant.upc.edu)
* Olmo Vigil            (olmo.vigil@estudiant.upc.edu)
* David Reixach         (david.reixach@estudiant.upc.edu)

## About the game
The universe of the Game of Life is an infinite two-dimensional orthogonal grid of square cells, where each cell can be in one of two possible states, alive or dead, depending on its eight neigbour cells.

At each step in time, the following transitions occur:
* Any live cell withfewer than two live neighbours dies, as if caused by
under-population.
* Any live cell with two or three live neighbours lives on to the next
generation.
* Any live cell with more than three live neighbours dies, as if by
over-population.
* Any dead cell with exactly three live neighbours becomes a live cell, as if by
reproduction.

## Folder structure
- *README.txt* : this file.
- *Makefile* : Compilation file.
- *src/* : contains the source files.
    - **gameoflife.c** : Main of the project. Executes 5250 iterations.
    - *board_functions.c* : Contains the functions concerning game of life rules.
    - *cell_functions.c* : Contains the functions to set or check values of cells.
    - *expand_functions.c* : Contains the functions dedicated to the expansion of the board.
    - *ncurses_functions.c* : Contains the functions related with the ncurses library.
- *include/* : contains the header files. Have the function declarations
   - *board_functions.h*
    - *cell_functions.h*
    - *expand_functions.h*
    - *ncurses_functions.h*
- *obj/* : Folder where the object files will be saved.

## Dependencies

In order to execute the game, the library ncurses must be downloaded for visualization purposes.
```
sudo apt-get install libncurses5-dev libncurses5
```

## Build instructions

Create a **obj** directory where the object files will be saved and compile by running the following commands:

```
    mkdir obj
    make clean
    make
```

## Execution

In the root of the project, execute:
```
./gameoflife
```

it will ask to select the starting simulation figure. The options are:

1. The R-pentomino
2. Diehard
3. Acorn

once the figure has been selected, the game will start.
Enjoy!

