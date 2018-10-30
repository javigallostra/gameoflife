CC = gcc
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses
DEPS = cell_functions.h ncurses_functions.h board_functions.h expand_functions.h
OBJ = gameoflife.o cell_functions.o ncurses_functions.o board_functions.o expand_functions.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

gameoflife: $(OBJ)
	gcc  -o $@ $^  $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) gameoflife
