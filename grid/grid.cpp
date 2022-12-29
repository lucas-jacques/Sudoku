#include "grid.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

Grid::Grid(int size)
{
    if (size < 1 || std::sqrt(size) != (int)sqrt(size))
    {
        std::cout << "Invalid size, size must be a perfect square" << std::endl;
        exit(1);
    }
    _size = size;
    _board = std::vector<int>(size * size, 0);
    generate();
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