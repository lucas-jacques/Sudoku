#include <vector>
#include <string>

#ifndef GRID_HPP
#define GRID_HPP

class Grid
{
public:
    Grid(int size);
    void print();
    void set(int x, int y, int value);
    int get(int x, int y) const;
    void fill(int n);
    int size() const;

private:
    int _size;
    std::vector<int> _board;
    void generate();
    void swapLines(int line1, int line2);
    void swapColumns(int column1, int column2);
    void swapDigits(int digit1, int digit2);
    bool isPositionValid(int x, int y, int value);
};

#endif