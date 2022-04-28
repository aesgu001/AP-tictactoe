# Compiler
CC = g++

# Compiler flags
CFLAGS = -g -Wall -Werror

# Target executable
TARGET = AP-tictactoe

# Object files
OBJ = main.o tictactoe-rules.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: tictactoe-rules.o main.cpp
	$(CC) $(CFLAGS) -c main.cpp

tictactoe-rules.o: tictactoe-rules.h tictactoe-rules.cpp
	$(CC) $(CFLAGS) -c tictactoe-rules.cpp

clean:
	$(RM) $(TARGET) $(OBJ)