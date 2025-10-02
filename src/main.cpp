#include <raylib.h>
#include "grid.hpp"

int main() {
    Color GREY = {29, 29 , 29 ,255};

    const int WINDOW_HEIGHT = 750;
    const int WINDOW_WIDTH = 750;
    const int CELL_SIZE = 25;

    int FPS = 12;

    Grid grid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conway game of life");
    SetTargetFPS(FPS);

    // simulation window
    while(WindowShouldClose() == false) {
        // Drawing
        BeginDrawing();
        ClearBackground(GREY);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
}