#include "grid.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "../utils/utils.hpp"

Grid::Grid(std::string fileName)
{
    std::vector<int> board;
    std::string fileAsText = utils::read(fileName);

    auto lines = utils::split(fileAsText, "\n");

    int size = lines.size();
    if (size < 1 || std::sqrt(size) != (int)sqrt(size))
    {
        std::cout << "Invalid size, size must be a perfect square" << std::endl;
        exit(1);
    }

    for (std::string line : lines)
    {

        std::vector<std::string> numbers = utils::split(line, " ");

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

/**
 * Set a value in the grid.
 * @param x The x position.
 * @param y The y position.
 * @param value The value to set.
 */
void Grid::set(int x, int y, int value)
{
    _board[y * _size + x] = value;
}

int Grid::get(int x, int y) const
{
    return _board.at(y * _size + x);
}

int Grid::size() const
{
    return _size;
}

/**
 * Check if the value is valid in the position
 *
 * @param x The x position.
 * @param y The y position.
 * @param value The value to check.
 *
 * @return true if the value is valid, false otherwise.
 *
 */
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