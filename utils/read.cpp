#include <iostream>
#include <fstream>
#include <string>
#include "fshelpers.hpp"
#include <sstream>

std::string fshelpers::read(std::string filename)
{
    std::ifstream file;
    file.open(filename);

    if (file.is_open())
    {
        std::string text;
        std::stringstream buffer;
        buffer << file.rdbuf();
        text = buffer.str();

        return text;
    }
    else
    {
        file.close();
        std::cout << "Unable to open file";
        exit(1);
    }
}