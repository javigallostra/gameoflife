CC = gcc
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses
# DEPS = interface.h
OBJ = try222.o #init.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

try222: $(OBJ)
	gcc  -o $@ $^  $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) try222
