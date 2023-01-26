#include <string>
#include <vector>

#ifndef FSHELPERS_HPP
#define FSHELPERS_HPP
namespace utils
{
    std::string read(std::string filename);
    std::vector<std::string> split(std::string s, std::string delimiter);
}

#endif
