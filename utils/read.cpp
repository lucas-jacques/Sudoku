#include <iostream>
#include <fstream>
#include <string>
#include "utils.hpp"
#include <sstream>

/**
 * This function is used to read a file and return its content as a string.
 *
 * @param filename The path of the file to read.
 * @return The content of the file.
 *
 */
std::string utils::read(std::string filename)
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