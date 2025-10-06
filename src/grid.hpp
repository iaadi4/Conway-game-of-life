#pragma once
#include <vector>

class Grid {
    public:
        Grid(int width, int height, int cellSize)
        : rows(height/cellSize), columns(width/cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {};
        void Draw();
        void setValue(int row, int column, int value);
        int getRows();
        int getColumns();
        std::vector<std::vector<int>> getCells();
        void fillRandomValues();

    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<int>> cells;
};