#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include "grid.hpp"

void drawFirstLine(int size, int subsquareSize)
{
    std::cout << "┏━━";
    for (int k = 0; k < size - 1; k++)
    {
        if ((k + 1) % subsquareSize == 0)
        {
            std::cout << "━━┳━━";
            continue;
        }
        else
        {
            std::cout << "━━┯━━";
        }
    }
    std::cout << "━━┓" << std::endl;
}

void drawLastLine(int size, int subsquareSize)
{
    std::cout << "┗━━";
    for (int k = 0; k < size - 1; k++)
    {
        if ((k + 1) % subsquareSize == 0)
        {
            std::cout << "━━┻━━";
            continue;
        }
        else
        {
            std::cout << "━━┷━━";
        }
    }
    std::cout << "━━┛" << std::endl;
}

void drawMiddleLine(int size, int subsquareSize, int line)
{
    bool isSubsquareLastLine = ((line + 1) % subsquareSize == 0 && line != 0);
    bool isEndOfLine = line == size - 1;

    std::string lineStart = isSubsquareLastLine ? "┣" : "┠";
    std::string lineEnd = isSubsquareLastLine ? "━━━━┫" : "────┨";

    std::string boldLinePart = "━━━━";
    std::string thinLinePart = "────";

    std::string linePart = isSubsquareLastLine ? boldLinePart : thinLinePart;

    std::cout << lineStart;

    for (int k = 0; k < size; k++)
    {
        bool isSubsquareLastColumn = ((k + 1) % subsquareSize == 0 && k != 0);
        std::string boldLineIntersection = isSubsquareLastColumn ? "━━━━╋" : "━━━━┿";
        std::string thinLineIntersection = isSubsquareLastColumn ? "────╂" : "────┼";
        std::string lineIntersection = isSubsquareLastLine ? boldLineIntersection : thinLineIntersection;

        if (k == size - 1)
        {
            std::cout << lineEnd;
        }
        else
        {
            std::cout << lineIntersection;
        }
    }
    std::cout << std::endl;
}

void Grid::draw()
{
    int subsquareSize = (int)sqrt(_size);
    drawFirstLine(_size, subsquareSize);
    for (int i = 0; i < _size; i++)
    {

        std::cout << "┃";
        for (int j = 0; j < _size; j++)

        {
            int value = get(j, i);
            std::string tile = value == 0 ? " " : std::to_string(value);
            int tileLength = tile.length();
            std::string space = std::string(3 - tileLength, ' ');
            if ((j + 1) % subsquareSize == 0 && j != 0)
            {
                std::cout << space << tile << " ┃";
            }
            else
            {
                std::cout << space << tile << " │";
            }
        }

        std::cout << std::endl;
        if (i == _size - 1)
        {
            break;
        }
        drawMiddleLine(_size, subsquareSize, i);
    }

    drawLastLine(_size, subsquareSize);
}

std::ostream &
operator<<(std::ostream &out, Grid &grid)
{
    grid.draw();
    return out;
}