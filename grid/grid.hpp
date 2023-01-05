#include <vector>
#include <string>

#ifndef GRID_HPP
#define GRID_HPP

class Grid
{
public:
    Grid(int size);
    Grid(std::string fileName);

    int size() const;
    int get(int x, int y) const;
    bool isPositionValid(int x, int y, int value);

    void set(int x, int y, int value);

    void fill(int n);
    void draw();
    void print();

private:
    int _size;
    std::vector<int> _board;
    void generate();
    void swapLines(int line1, int line2);
    void swapColumns(int column1, int column2);
    void swapDigits(int digit1, int digit2);
};

std::ostream &operator<<(std::ostream &os, Grid &s);

#endif