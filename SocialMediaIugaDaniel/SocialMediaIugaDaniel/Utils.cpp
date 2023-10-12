#include "Utils.h"
#include <sstream>

std::vector<std::string> splitLine(std::string linie, char delim)
{
    std::stringstream ss(linie);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

bool integer_validator(std::string x)
{
    try {
        int a = stoi(x);
    }
    catch (std::exception& exc) {
        return false;
    }
    return true;
}

