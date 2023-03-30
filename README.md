# Sudoku solver

A basic C++ school project.

## Get started

**Requirement :** g++ >= 12.0.0
**Warning :** The program has been only tested on linux.

Build and run the SudokuSolver:

```shell
make run
```

To build only :

```shell
make build
```

To debug only :

```shell
make debug
```

**Warning :** Don't chose a hard level for 16\*16 or 25\*25 grid. The algorithm could take several minutes to hours to end.

## Technical choices

### Data structure

The data structure used to represent the sudoku is a 1D vector of n+n integers line by line. I made an abstraction over this vector with the `Grid` class.

I should have used a more low level array like `std::array` or a native dynamic array to avoid the overhead of the `std::vector` class but the vector increase readability.

The `Grid` class is also handle the generation.

### Grid generation

The generation is made in three steps:

1. First it fill an empty grid with the trivial solution: the first row is filled with the numbers from 1 to n:

```
 ┏━━━━┯━━━━┯━━━━┳━━━━┯━━━━┯━━━━┳━━━━┯━━━━┯━━━━┓
 ┃  1 │  2 │  3 ┃  4 │  5 │  6 ┃  7 │  8 │  9 ┃
 ┠────┼────┼────╂────┼────┼────╂────┼────┼────┨
 ┃  4 │  5 │  6 ┃  7 │  8 │  9 ┃  1 │  2 │  3 ┃
 ┠────┼────┼────╂────┼────┼────╂────┼────┼────┨
 ┃  7 │  8 │  9 ┃  1 │  2 │  3 ┃  4 │  5 │  6 ┃
 ┣━━━━┿━━━━┿━━━━╋━━━━┿━━━━┿━━━━╋━━━━┿━━━━┿━━━━┫
 ┃  8 │  9 │  1 ┃  2 │  3 │  4 ┃  5 │  6 │  7 ┃
 ┠────┼────┼────╂────┼────┼────╂────┼────┼────┨
 ┃  2 │  3 │  4 ┃  5 │  6 │  7 ┃  8 │  9 │  1 ┃
 ┠────┼────┼────╂────┼────┼────╂────┼────┼────┨
 ┃  5 │  6 │  7 ┃  8 │  9 │  1 ┃  2 │  3 │  4 ┃
 ┣━━━━┿━━━━┿━━━━╋━━━━┿━━━━┿━━━━╋━━━━┿━━━━┿━━━━┫
 ┃  6 │  7 │  8 ┃  9 │  1 │  2 ┃  3 │  4 │  5 ┃
 ┠────┼────┼────╂────┼────┼────╂────┼────┼────┨
 ┃  9 │  1 │  2 ┃  3 │  4 │  5 ┃  6 │  7 │  8 ┃
 ┠────┼────┼────╂────┼────┼────╂────┼────┼────┨
 ┃  3 │  4 │  5 ┃  6 │  7 │  8 ┃  9 │  1 │  2 ┃
 ┗━━━━┷━━━━┷━━━━┻━━━━┷━━━━┷━━━━┻━━━━┷━━━━┷━━━━┛
```

2. Then it shuffle randomly the rows and columns of the grid and it swap numbers.
3. Finally it remove some numbers to make the sudoku harder. The number of removed numbers depends on the difficulty level.

With this way, the sudoku is always solvable but for the hardest level, it could be very hard to solve and the solution may not be unique.

### Backtracking

The algorithm used to solve the sudoku is a backtracking algorithm. It is a recursive algorithm that tries to find a solution by trying all the possible values for each cell. If the value is not valid, it tries the next one. If it reaches the end of the grid, it means that the sudoku is solved.

This implementation is a very naive and could be improved by using a more efficient algorithm like the Dancing Links algorithm.
Although, Sudoku is a NP-complete problem, so it is not possible to find a solution in polynomial time, so the best algorithm will always be a O(2^n) algorithm.

We could also have used deductive techniques to speed up the filling during backtracking or a mask to start backtracking on the cells with the fewest candidate values.

**Note :** I've not implemented uniqueness check because it is not necessary for the purpose of this project and it would have considerably slowed down the programm.

## Possible improvements

- Use a more efficient algorithm like the Dancing Links algorithm.
- Use a more efficient data structure like a native array.
- Use a more efficient way to represent the grid. For example, a bitset could be used to represent the grid. This would reduce the memory usage and the time to check if a value is valid. However, this would complexify the code but it could bring a significant performance gain.

## References

- [Sudoku | Backtracking-7 - GeeksforGeeks](https://www.geeksforgeeks.org/sudoku-backtracking-7/)

- [Backtracking Algorithm for Sudoku](https://iq.opengenus.org/backtracking-sudoku/)
