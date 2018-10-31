SRC_PATH = ./src
INCLUDE_DIRS = -I./include
OBJ_PATH = ./obj

CC = gcc
CFLAGS = -Wall $(INCLUDE_DIRS) -I.
LDFLAGS = -lncurses
DEPS = cell_functions.h ncurses_functions.h board_functions.h expand_functions.h #Dependencies
OBJ1 = gameoflife.o cell_functions.o ncurses_functions.o board_functions.o expand_functions.o #Targets
OBJ = $(patsubst %,$(OBJ_PATH)/%,$(OBJ1))

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

gameoflife: $(OBJ)
	$(CC) -o $@ $^  $(LDFLAGS) $(CFLAGS) -pg

clean:
	rm -f $(OBJ) gameoflife
