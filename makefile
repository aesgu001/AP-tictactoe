# Compiler
CC = g++

# Compiler flags
CFLAGS = -g -Wall -Werror

# Target executable
TARGET = AP-tictactoe

# Object files
OBJ = ttt-main.o ttt-input.o ttt-rules.o ttt-ai.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

ttt-main.o: ttt-input.o ttt-rules.o ttt-ai.o ttt-main.h ttt-main.cpp
	$(CC) $(CFLAGS) -c ttt-main.cpp

ttt-input.o: ttt-input.h ttt-input.cpp
	$(CC) $(CFLAGS) -c ttt-input.cpp

ttt-ai.o: ttt-rules.o ttt-ai.h ttt-ai.cpp
	$(CC) $(CFLAGS) -c ttt-ai.cpp

ttt-rules.o: ttt-rules.h ttt-rules.cpp
	$(CC) $(CFLAGS) -c ttt-rules.cpp

clean:
	$(RM) $(TARGET) $(OBJ)