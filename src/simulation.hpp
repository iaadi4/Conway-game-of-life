#pragma once
#include "grid.hpp"

class Simulation {
    public:
        Simulation(int width, int height, int cellSize)
        :   grid(width, height, cellSize) {};
        void Draw();
        void setCellValue(int row, int column, int value);
        int countLiveNeighbours(int row, int column);
    
    private:
        Grid grid;
};