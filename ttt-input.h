#include <iostream> // std::cin, std::getline

/*
*   Reads a string line from standard input.
*
*   @return A string of 1 or more words.
*/
std::string readLine();

/*
*   Stores an integer read from standard input if converted from string.
*
*   @param strInt variable to store the integer value.
*
*   @return True if the function converts the string successfully.
*/
bool readInteger(int &);