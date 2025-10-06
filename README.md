# Conway's Game of Life

A C++ implementation of Conway's Game of Life using the raylib graphics library. This project provides a real-time visual simulation of the famous cellular automaton.

## About Conway's Game of Life

Conway's Game of Life is a zero-player game, meaning its evolution is determined by its initial state, requiring no further input. It consists of a collection of cells which, based on a few mathematical rules, can live, die, or multiply.

### Rules
1. **Underpopulation**: Any live cell with fewer than two live neighbors dies
2. **Survival**: Any live cell with two or three live neighbors survives to the next generation
3. **Overpopulation**: Any live cell with more than three live neighbors dies
4. **Reproduction**: Any dead cell with exactly three live neighbors becomes a live cell

## Features

- 🎮 Real-time visual simulation with 750x750 window
- 🎲 Random initial cell distribution
- 🔄 Automatic generation updates at 12 FPS
- 🌍 Toroidal world (edges wrap around)
- 🎨 Green cells for alive, gray for dead
- 📐 10x10 pixel cell size (75x75 grid)

## Prerequisites

Before building this project, you need:

- **C++17 compatible compiler** (g++, clang++, etc.)
- **raylib graphics library** (version 5.0.0 or compatible)
- **Make** utility

### Installing raylib

#### Ubuntu/Debian:
```bash
sudo apt update
sudo apt install libraylib-dev
```

#### macOS (Homebrew):
```bash
brew install raylib
```

#### Windows:
Download raylib from [official website](https://www.raylib.com/) or use package managers like vcpkg.

## Building and Running

### Quick Start
```bash
# Clone the repository (if needed)
git clone <repository-url>
cd game-of-life

# Build the project
make

# Run the simulation
./game
```

### Build Options
- **Debug build**: `make BUILD_MODE=DEBUG`
- **Release build**: `make BUILD_MODE=RELEASE` (default)
- **Clean build files**: `make clean`

## Project Structure

```
game-of-life/
├── src/
│   ├── main.cpp          # Entry point and window management
│   ├── grid.hpp          # Grid class declaration
│   ├── grid.cpp          # Grid implementation (rendering, cell management)
│   ├── simulation.hpp    # Simulation class declaration
│   └── simulation.cpp    # Game logic and rules implementation
├── lib/                  # Windows DLL dependencies
├── Makefile             # Build configuration
├── .gitignore           # Git ignore rules
└── README.md            # This file
```

## Code Architecture

### Grid Class
- Manages the 2D cellular grid
- Handles cell rendering with raylib
- Provides cell state management (alive/dead)
- Generates random initial configurations

### Simulation Class
- Implements Conway's Game of Life rules
- Manages generation updates
- Uses double buffering with temporary grid
- Handles neighbor counting with toroidal topology

### Key Components
- **Cell Size**: 10x10 pixels
- **Grid Size**: 75x75 cells
- **Window Size**: 750x750 pixels
- **Update Rate**: 12 FPS
- **Colors**: Green (#00FF00) for alive, Dark Gray (#373737) for dead

## Customization

You can easily modify various parameters by editing the source files:

### Change Grid Size or Cell Size
Edit `main.cpp`:
```cpp path=/media/Programming/c++/game-of-life/src/main.cpp start=7
const int WINDOW_HEIGHT = 750;
const int WINDOW_WIDTH = 750;
const int CELL_SIZE = 10;
```

### Change Update Speed
Edit `main.cpp`:
```cpp path=/media/Programming/c++/game-of-life/src/main.cpp start=11
int FPS = 12;
```

### Modify Colors
Edit `grid.cpp`:
```cpp path=/media/Programming/c++/game-of-life/src/grid.cpp start=8
Color colorOfCell = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
```

### Change Initial Cell Distribution
Edit `grid.cpp` in the `fillRandomValues()` method:
```cpp path=/media/Programming/c++/game-of-life/src/grid.cpp start=35
int randomValue = GetRandomValue(0, 5);
cells[row][column] = (randomValue == 5) ? 1 : 0;
```
Currently, cells have a 1/6 chance of being alive initially.

## Controls

- **Close Window**: Click the X button or press Alt+F4
- The simulation runs automatically once started

## Technical Details

- **Language**: C++17
- **Graphics**: raylib 5.0.0
- **Build System**: Make
- **Platforms**: Cross-platform (Windows, Linux, macOS)
- **Topology**: Toroidal (edges wrap around)
- **Algorithm**: Standard Conway's Game of Life with double buffering

## License

This project uses raylib, which is licensed under an unmodified zlib/libpng license. Please refer to raylib's license for more information.

## Acknowledgments

- Created using [raylib](https://www.raylib.com/) graphics library
- Inspired by John Conway's Game of Life cellular automaton
- Build system based on raylib's standard Makefile template

## Contributing

Feel free to fork this project and submit pull requests for improvements or bug fixes.