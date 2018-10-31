#File: Makefile
#Author: Coder 2
#Date: 20-October-2018

#source directory
SRC_PATH = ./src
#Include directory
INCLUDE_DIRS = -I./include
#Object directory
OBJ_PATH = ./obj

#Compiler to use
CC = gcc
#Compilation options
CFLAGS = -Wall $(INCLUDE_DIRS) -I.
#Linker flags
LDFLAGS = -lncurses
#Dependencies
DEPS = cell_functions.h ncurses_functions.h board_functions.h expand_functions.h
#Targets
OBJ1 = gameoflife.o cell_functions.o ncurses_functions.o board_functions.o expand_functions.o
OBJ = $(patsubst %,$(OBJ_PATH)/%,$(OBJ1))

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

gameoflife: $(OBJ)
	$(CC) -o $@ $^  $(LDFLAGS) $(CFLAGS) -pg

clean:
	rm -f $(OBJ) gameoflife
