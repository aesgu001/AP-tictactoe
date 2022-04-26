# Compiler
CC = g++

# Compiler flags
CFLAGS = -g -Wall -Werror

# Target executable
TARGET = AP-tictactoe

all: $(TARGET)

$(TARGET): main.cpp
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp

clean:
	$(RM) $(TARGET)