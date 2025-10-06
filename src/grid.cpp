#include <raylib.h>
#include "grid.hpp"

void Grid::Draw() {
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            // grey if cell is dead and green if they are alive
            Color colorOfCell = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(column*cellSize, row*cellSize, cellSize-1, cellSize-1, colorOfCell);
        }
    }
}

void Grid::setValue(int row, int column, int value) {
    if(row >= 0 && row < rows && column >= 0 && column < columns) {
        cells[row][column] = value;
    }
}

int Grid::getRows() {
    return rows;
}

int Grid::getColumns() {
    return columns;
}

std::vector<std::vector<int>> Grid::getCells() {
    return cells;
}

void Grid::fillRandomValues() {
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            int randomValue = GetRandomValue(0, 5);
            cells[row][column] = (randomValue == 5) ? 1 : 0;
        }
    }
}