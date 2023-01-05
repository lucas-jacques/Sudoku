#include <string>

#ifndef FSHELPERS_HPP
#define FSHELPERS_HPP
namespace fshelpers
{
    std::string read(std::string filename);
    void write(std::string filename, std::string text);
}

#endif