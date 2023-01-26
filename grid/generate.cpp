#include <math.h>
#include "grid.hpp"
#include <iostream>
#include <math.h>
#include <array>
#include <vector>
#include "../types.hpp"

/**
 * Swap two columns of the grid.
 * @param x1 The index of the first column.
 * @param x2 The index of the second column.
 */
void Grid::swapColumns(int x1, int x2)
{
    for (int i = 0; i < _size; i++)
    {
        int temp = get(x1, i);
        set(x1, i, get(x2, i));
        set(x2, i, temp);
    }
}

/**
 * Swap two lines of the grid.
 * @param y1 The index of the first line.
 * @param y2 The index of the second line.
 */
void Grid::swapLines(int y1, int y2)
{
    for (int i = 0; i < _size; i++)
    {
        int temp = get(i, y1);
        set(i, y1, get(i, y2));
        set(i, y2, temp);
    }
}

/**
 * Swap two digits of the grid. It replaces all the occurences of d1 by d2 and all the occurences of d2 by d1.
 *
 * @param d1 The first digit.
 * @param d2 The second digit.
 *
 */
void Grid::swapDigits(int d1, int d2)
{
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            if (get(i, j) == d1)
            {
                set(i, j, d2);
            }
            else if (get(i, j) == d2)
            {
                set(i, j, d1);
            }
        }
    }
}

/**
 * Generate a random Sudoku grid with a given level of difficulty.
 *
 * @param level The level of difficulty. Must be between 1 and 5.
 */
void Grid::generate(int level)
{

    if (level < 1 || level > 5)
    {
        std::cout << "Invalid level value. Level must be between 1 and 5 \n";
        exit(1);
    }
    int value = 0;

    for (int i = 0; i < _size * _size; i++)
    {
        int x = i % _size;
        int y = i / _size;

        do
        {
            value++;
            if (value > _size)
            {
                value = 1;
            }
        } while (!isPositionValid(x, y, value));
        set(x, y, value);
    }

    std::srand(time(NULL));

    int subSize = (int)sqrt(_size);

    // Randomly swap columns, lines and digits
    for (int i = 0; i < _size * _size; i++)
    {
        int action = rand() % 3;

        if (action == 0)
        {
            int x1 = rand() % subSize;
            int x2 = rand() % subSize;
            swapColumns(x1, x2);
        }
        else if (action == 1)
        {
            int y1 = rand() % subSize;
            int y2 = rand() % subSize;
            swapLines(y1, y2);
        }
        else
        {
            int d1 = rand() % _size;
            int d2 = rand() % _size;
            swapDigits(d1, d2);
        }
    }

    std::vector<Position> whitelist;

    // Fill whitelist
    for (int i = 0; i < _size * _size; i++)
    {
        int x = i % _size;
        int y = i / _size;
        whitelist.push_back(Position({x, y}));
    }

    // Randomly remove numbers
    std::array<double, 5> levels{{0.25, 0.4, 0.5, 0.6, 0.75}};
    int numToRemove = levels[level - 1] * (_size * _size);

    while (numToRemove > 0)
    {
        if (whitelist.size() == 0)
            break;
        int index = rand() % whitelist.size();
        int x = whitelist[index][0];
        int y = whitelist[index][1];
        int temp = get(x, y);
        set(x, y, 0);
        numToRemove--;
        whitelist.erase(whitelist.begin() + index);
    }
}
