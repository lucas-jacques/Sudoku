#include <iostream>
#include <fstream>
#include <string>
#include "fshelpers.hpp"

void fshelpers::write(std::string filename, std::string text)
{
    std::ofstream file;
    file.open(filename);
    file.clear();
    if (file.is_open())
    {
        file << text;
    }
    else
    {
        std::cout << "Unable to write file";
        exit(1);
    }
    file.close();
}