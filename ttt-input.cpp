#include "ttt-input.h"

std::string readLine()
{
    std::string line;
    std::getline(std::cin, line, '\n');

    return line;
}

bool readInteger(int &stInt)
{
    std::string numStr;
    do
    {
        numStr = readLine();
    } while (numStr.empty());
    
    for (char c : numStr)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    stInt = std::stoi(numStr);

    return true;
}