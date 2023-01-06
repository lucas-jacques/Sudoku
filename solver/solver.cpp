#include "solver.hpp"
#include "iostream"
#include "../types.hpp"

SudokuSolver::SudokuSolver(int size, int level) : _grid(size, level)
{
    std::cout << "Generated grid:\n";
    std::cout << _grid;
}

SudokuSolver::SudokuSolver(Grid grid) : _grid(grid)
{
    std::cout << "Initial grid:\n";
    std::cout << _grid;
}
Positions getEmptyPositions(Grid &board) // Get positions of empty cells
{
    Positions positions;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board.get(i, j) == 0)
            {
                Position position({i, j});
                positions.push_back(position);
            }
        }
    }
    return positions;
}
std::vector<int> getCandidateValues(Grid &board, Position p)
{
    std::vector<int> availableValues;
    for (int i = 1; i <= board.size(); i++)
    {
        if (board.isPositionValid(p[0], p[1], i))
        {
            availableValues.push_back(i);
        }
    }
    return availableValues;
}

bool candidateReduction(Grid &board, Positions &changedPositions)
{
    bool changed = false;
    Positions emptyPositions = getEmptyPositions(board);
    for (auto position : emptyPositions)
    {
        int x = position[0];
        int y = position[1];
        std::vector<int> candidateValues = getCandidateValues(board, position);
        if (candidateValues.size() == 1)
        {
            board.set(x, y, candidateValues[0]);
            changedPositions.push_back({x, y});
            changed = true;
        }
    }

    return changed;
}

bool backTrackingSolver(Grid &board, int x, int y)
{
    Positions changedPositions;

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
        Position position({x, y});
        std::vector<int> candidates = getCandidateValues(board, position);

        for (int i : candidates)
        {
            if (board.isPositionValid(x, y, i))
            {

                board.set(x, y, i);
                if (backTrackingSolver(board, x, y + 1))
                {
                    return true;
                }
                for (auto p : changedPositions)
                {
                    board.set(p[0], p[1], 0);
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