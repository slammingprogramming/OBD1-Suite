CC = gcc
CFLAGS = -Wall `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`
SRC = main.c obd1_interface.c data_parser.c report_generator.c gui.c
OBJ = $(SRC:.c=.o)
EXEC = obd1_debugger

all: $(EXEC)

$(EXEC): $(OBJ)
    $(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

clean:
    rm -f $(OBJ) $(EXEC)