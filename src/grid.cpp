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