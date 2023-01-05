#include "solver.hpp"
#include "iostream"
#include "../types.hpp"

SudokuSolver::SudokuSolver(int size, int level) : _grid(size)
{
    std::cout << "Generated grid:\n";
    std::cout << _grid;
}

SudokuSolver::SudokuSolver(Grid grid) : _grid(grid)
{
    std::cout << "Initial grid:\n";
    std::cout << _grid;
}

bool backTrackingSolver(Grid &board, int x, int y)
{

    if (x == board.size())
    {
        return true;
    }
    else if (y == board.size())
    {
        return backTrackingSolver(board, x + 1, 0);
    }
    else if (board.get(x, y) != 0)
    {
        return backTrackingSolver(board, x, y + 1);
    }
    else
    {
        for (int i = 1; i <= board.size(); i++)
        {
            if (board.isPositionValid(x, y, i))
            {

                board.set(x, y, i);
                if (backTrackingSolver(board, x, y + 1))
                {
                    return true;
                }
                board.set(x, y, 0);
            }
        }
        return false;
    }
}

void SudokuSolver::solve()
{
    backTrackingSolver(_grid);

    std::cout << "Solved grid: \n";
    std::cout << _grid;
}