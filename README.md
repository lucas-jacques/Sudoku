# Sudoku solver

## Get started

To build and run:

```shell
make run
```

**Warning :** Don't chose a hard level for 16\*16 or 25\*25 grid. The algorithm could take several minutes to hours to end.

## Technical choices

### Data structure

The data structure used to represent the sudoku is a 1D vector of n+n integers line by line. I made an abstraction over this vector with the `Grid` class.

I should have used a more low level array like `std::array` or a native dynamic array to avoid the overhead of the `std::vector` class but the vector increase readability.

The `Grid` class is also handle the generation.

### Grid generation

### Backtracking

The algorithm used to solve the sudoku is a backtracking algorithm. It is a recursive algorithm that tries to find a solution by trying all the possible values for each cell. If the value is not valid, it tries the next one. If it reaches the end of the grid, it means that the sudoku is solved.

This implementation is a very naive and could be improved by using a more efficient algorithm like the Dancing Links algorithm.
Although, Sudoku is a NP-complete problem, so it is not possible to find a solution in polynomial time, so the best algorithm will always be a O(2^n) algorithm.

We could also have used deductive techniques to speed up the filling during backtracking or a mask to start backtracking on the cells with the fewest candidate values.

## Possible improvements

- Use a more efficient algorithm like the Dancing Links algorithm
- Use a more efficient data structure like a native array
- Use a more efficient way to represent the grid
- Use a more efficient way to represent the possible values for each cell. For example, a bitset could be used to represent the possible values for each cell. This would reduce the memory usage and the time to check if a value is valid. However, this would make the code more complex and less readable. But it could be interesting to implement this improvement to see the performance gain. I think that the performance gain would be very significant on larger grids.

## References
