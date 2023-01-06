#include <iostream>

#include "grid/grid.hpp"
#include "solver/solver.hpp"

int main(int argc, char *argv[])
{

    SudokuSolver sudoku(9, 5);
    sudoku.solve();
};