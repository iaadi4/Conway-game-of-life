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
        int newRow = row+nr;
        int newColumn = column+nc;
        if(newRow >= 0 && newRow < grid.getRows() && newColumn >= 0 && newColumn < grid.getColumns()) {
            if(grid.getCells()[newRow][newColumn] == 1) {
                count++;
            }
        }
    }
    return count;
}