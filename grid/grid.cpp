#include "grid.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "../utils/fshelpers.hpp"

std::vector<std::string> split(std::string s, std::string delimiter) // split a string with a delimiter. Please see https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

Grid::Grid(std::string fileName)
{
    std::vector<int> board;
    std::string fileAsText = fshelpers::read(fileName);

    auto lines = split(fileAsText, "\n");

    int size = lines.size();
    if (size < 1 || std::sqrt(size) != (int)sqrt(size))
    {
        std::cout << "Invalid size, size must be a perfect square" << std::endl;
        exit(1);
    }

    for (std::string line : lines)
    {

        std::vector<std::string> numbers = split(line, " ");

        if (numbers.size() != size)
        {
            std::cout << "Invalid size, size must be a perfect square" << std::endl;
            exit(1);
        }

        for (std::string strNumber : numbers)
        {

            int parsedNumber = std::stoi(strNumber);
            std::cout << parsedNumber;

            board.push_back(parsedNumber);
        }
        std::cout << "\n";
    }

    _size = size;
    _board = board;

    std::cout
        << "Grid successfully loaded from files \n";
}

Grid::Grid(int size, int level)
{
    if (size < 1 || std::sqrt(size) != (int)sqrt(size))
    {
        std::cout << "Invalid size, size must be a perfect square" << std::endl;
        exit(1);
    }
    _size = size;
    _board = std::vector<int>(size * size, 0);
    generate(level);
}

void Grid::set(int x, int y, int value)
{
    _board[y * _size + x] = value;
}

int Grid::get(int x, int y) const
{
    return _board.at(y * _size + x);
}

void Grid::print()
{
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            std::cout << " " << get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int Grid::size() const
{
    return _size;
}

bool Grid::isPositionValid(int x, int y, int value)
{
    if (value == 0 || value > _size)
    {
        return false;
    }
    // Check if the value is already in the row or column
    for (int i = 0; i < _size; i++)
    {
        if (((get(x, i) == value) && i != y) || ((get(i, y) == value) && i != x))
            return false;
    }

    // Check if the value is already in the subsquare
    int subsquareSize = sqrt(_size);
    int subsquareX = (int)(x / subsquareSize) * subsquareSize;
    int subsquareY = (int)(y / subsquareSize) * subsquareSize;

    for (int i = 0; i < subsquareSize; i++)
    {
        for (int j = 0; j < subsquareSize; j++)
        {

            int sx = subsquareX + i;
            int sy = subsquareY + j;
            if (get(sx, sy) == value && !(sx == x && sy == y))
            {
                return false;
            }
        }
    }

    return true;
};