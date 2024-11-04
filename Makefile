CC = gcc
CFLAGS = -Iinclude -Wall
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

obd1_suite: $(OBJ)
    $(CC) -o $@ $^

clean:
    rm -f $(OBJ) obd1_suite