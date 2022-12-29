#include <iostream>

#include "grid/grid.hpp"
#include "solver/solver.hpp"

int main(void)
{

    SudokuSolver sudoku(9, 4);
    sudoku.solve();
};