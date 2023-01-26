#include "solver.hpp"
#include "iostream"
#include "../types.hpp"
#include <chrono>
/**
 * SudokuSolver constructor.
 * It generate a grid with the given size and level.
 *
 * @param size The size of the grid.
 * @param level The level of difficulty of the grid between 1 and 5.
 *
 */
SudokuSolver::SudokuSolver(int size, int level) : _grid(size, level)
{
    std::cout << "Generated grid:\n";
    std::cout << _grid;
}

/**
 * SudokuSolver constructor.
 * Load an existing grid.
 *
 * @param grid A pre-existing grid.
 *
 */

SudokuSolver::SudokuSolver(Grid grid) : _grid(grid)
{
    std::cout << "Initial grid:\n";
    std::cout << _grid;
}

/**
 * This function take a grid and return a vector of all the empty positions.
 *
 * @param board The grid to scan.
 */
Positions getEmptyPositions(Grid &board)
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

/**
 * This function take a grid and a position and return a vector of all the possible values for this position.
 *
 * @param board The grid to scan.
 * @param p The position to scan.
 */
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

/**
 * This function take a grid and fill all the empty positions with the only possible value.
 * It return true if the grid has changed.
 * It fill the changedPositions vector with the positions that have changed.
 *
 * @param board The grid to scan.
 * @param changedPositions The vector to fill with the positions that have changed.
 *
 */
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

/**
 * This function solve  a grid using the backtracking algorithm.
 * It return true if the grid is solved.
 * It fill the grid with the solution.
 * It return false if the grid is unsolvable.
 *
 * @param board The grid to solve.
 * @param x The x position of the current position.
 * @param y The y position of the current position.
 *
 */
bool backTrackingSolver(Grid &board, int x, int y, int &count)
{
    count++;
    Positions changedPositions;

    if (x == board.size())
    {
        return true;
    }
    else if (y == board.size())
    {
        return backTrackingSolver(board, x + 1, 0, count);
    }
    else if (board.get(x, y) != 0)
    {
        return backTrackingSolver(board, x, y + 1, count);
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
                if (backTrackingSolver(board, x, y + 1, count))
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

/**
 * Solve the grid using the backtracking algorithm.
 *
 */
void SudokuSolver::solve()
{
    int count = 0;
    auto time1 = std::chrono::high_resolution_clock::now();
    backTrackingSolver(_grid, 0, 0, count);
    auto time2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1).count();
    std::cout << "Solved in " << duration << " milliseconds.\n";
    std::cout << "Solved in " << count << " iterations.\n";
    std::cout << "Solved grid: \n";
    std::cout << _grid;
}