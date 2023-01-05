#include <iostream>

#include "grid/grid.hpp"
#include "solver/solver.hpp"

int main(void)
{

    SudokuSolver sudoku(25, 1);
    sudoku.solve();
};