#include "../grid/grid.hpp"

class SudokuSolver
{
public:
    SudokuSolver(int size, int level);
    SudokuSolver(Grid grid);
    void solve();

private:
    Grid _grid;
};