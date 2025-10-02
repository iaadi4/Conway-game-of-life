#include "simulation.hpp"

void Simulation::Draw() {
    grid.Draw();
}

void Simulation::setCellValue(int row, int column, int value) {
    grid.setValue(row, column, value);
}