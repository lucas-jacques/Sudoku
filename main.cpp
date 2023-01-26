#include <iostream>
#include "math.h"
#include "grid/grid.hpp"
#include "solver/solver.hpp"
#include "utils/getControlledInput.cpp"
#include <filesystem>

int main(void)
{

    // Give to the user the choice to generate a grid or to load a grid from a file
    //
    // If the user choose to generate a grid, ask him the size of the grid and the level of difficulty
    //
    // If the user choose to load a grid, ask him the path of the file
    //
    // Then, solve the grid and print the solution.

    std::cout << "Welcome to SudokuSolver!" << std::endl
              << "Please choose an option:" << std::endl
              << "1. Generate a grid" << std::endl
              << "2. Load a grid from a file" << std::endl
              << "3. Exit" << std::endl;

    int option = getControlledInput<int>([](int option)
                                         { return option == 1 || option == 2 || option == 3; });
    if (option == 1)
    {
        std::cout << "Please enter the size of the grid:" << std::endl;
        int size = getControlledInput<int>([](int option)
                                           {
                                               if (sqrt(option) != (int)sqrt(option))
                                               {
                                                   std::cout << "The size must be a perfect square integer" << std::endl;
                                                   return false;
                                               }

                                               return true; });

        std::cout << "Please enter the level of difficulty:" << std::endl
                  << "1: Very easy" << std::endl
                  << "2: Easy" << std::endl
                  << "3: Medium" << std::endl
                  << "4: Hard" << std::endl
                  << "5: Inhuman" << std::endl;

        int level = (int)getControlledInput<int>([](int option)
                                                 { return option > 0 && option < 6; });

        SudokuSolver sudoku(size, level);
        sudoku.solve();
    }
    else if (option == 2)
    {
        std::cout << "Please enter the path of the file:" << std::endl;
        std::string path = getControlledInput<std::string>([](std::string path)
                                                           {
                                                               if (!std::filesystem::exists(path))
                                                               {
                                                                   std::cout << "The file doesn't exist" << std::endl;
                                                                   return false;
                                                               }

                                                               return true; });

        Grid grid(path);
        SudokuSolver sudoku(grid);
        sudoku.solve();
    }
    else if (option == 3)
    {
        return 0;
    }
};