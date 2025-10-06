#include "simulation.hpp"
#include "grid.hpp"
#include <vector>

const std::vector<std::pair<int,int>> d = {
    {0, -1}, {-1, 0}, {1, 0}, {0, 1}, 
    {-1, 1}, {1, -1}, {-1, -1}, {1, 1}
};

void Simulation::Draw() {
    grid.Draw();
}

void Simulation::setCellValue(int row, int column, int value) {
    grid.setValue(row, column, value);
}

int Simulation::countLiveNeighbours(int row, int column) {
    int count = 0;
    for(auto [nr, nc]: d) {
        int newRow = (row + nr + grid.getRows()) % grid.getRows();
        int newColumn = (column + nc + grid.getColumns()) % grid.getColumns();
        if(newRow >= 0 && newRow < grid.getRows() && newColumn >= 0 && newColumn < grid.getColumns()) {
            if(grid.getCells()[newRow][newColumn] == 1) {
                count++;
            }
        }
    }
    return count;
}

void Simulation::update() {
    for(int row = 0; row < grid.getRows(); row++) {
        for(int column = 0; column < grid.getColumns(); column++) {
            int liveNeighbours = countLiveNeighbours(row, column);
            int cellValue = grid.getCells()[row][column];

            if(cellValue == 1) {
                if(liveNeighbours > 3 || liveNeighbours < 2) {
                    tempGrid.setValue(row, column, 0);
                } else {
                    tempGrid.setValue(row, column, 1);
                }
            } else {
                if(liveNeighbours == 3) {
                    tempGrid.setValue(row, column, 1);
                } else {
                    tempGrid.setValue(row, column, 0);
                }
            }
        }
    }
    grid = tempGrid;
}