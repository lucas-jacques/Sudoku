#include <iostream>

#include "grid/grid.hpp"
#include "solver/solver.hpp"

int main(void)
{

    Grid grid("inkala.txt");
    SudokuSolver sudoku(grid);
    sudoku.solve();
};