# So-Long

A small **2D top-down adventure game** developed with **MiniLibX**, the graphics library of [42School](https://42.fr/). Navigate through maps, collect items, and find your way to the exit in this classic arcade-style game.

## 🎮 About the Game

So-Long is a simple 2D game where the player controls a character that must:
- **Collect all items** scattered throughout the map
- **Navigate to the exit** to complete the level
- **Avoid walls** and stay within map boundaries
- **Complete the level** in the minimum number of moves

The game features a top-down perspective with tile-based movement and retro-style graphics.

### Game Rules

- 🏃 **Movement**: Use `W`, `A`, `S`, `D` or arrow keys to move
- 💎 **Objective**: Collect all collectibles before reaching the exit
- 🚪 **Exit**: The exit only opens when all collectibles are gathered
- 📊 **Score**: Track your moves - try to complete with minimum steps!
- ❌ **Constraints**: You cannot move through walls or outside the map

## 🛠️ Technical Implementation

This project demonstrates:
- **2D Graphics Programming** with MiniLibX
- **Event Handling** for keyboard input
- **Map Parsing and Validation** from `.ber` files
- **Pathfinding Algorithms** (DFS) for map validation
- **Memory Management** in C
- **Error Handling** and input validation

### Key Features

- ✅ **Custom Graphics Engine**: Built with MiniLibX from scratch
- ✅ **Map Validation**: Ensures maps are solvable and properly formatted
- ✅ **Sprite Management**: Efficient loading and rendering of game assets
- ✅ **Real-time Movement**: Smooth character movement with collision detection
- ✅ **Move Counter**: Displays current move count in real-time
- ✅ **Cross-platform**: Works on Linux and macOS

## 🏗️ Project Structure

```
so-long/
├── ft_printf/          # Custom printf implementation
├── get_next_line/      # Line-by-line file reading utility
├── minilibx/           # MiniLibX graphics library
├── game_images/        # Sprite assets and textures
├── maps/               # Game level files (.ber format)
├── src/
│   ├── main.c          # Main game loop and initialization
│   ├── map.c           # Map parsing and validation
│   ├── images.c        # Sprite loading and rendering
│   ├── dfs.c           # Depth-first search for path validation
│   └── so_long.h       # Header file with structures and prototypes
├── Makefile            # Build configuration
└── README.md           # This file
```

## 🚀 Getting Started

### Prerequisites

- **GCC compiler** or compatible C compiler
- **Make** build tool
- **MiniLibX dependencies**:
  - Linux: `sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev`
  - macOS: Xcode command line tools

### Building the Game

```bash
# Clone the repository
git clone https://github.com/Selmand42/So-Long.git
cd So-Long

# Compile the game
make

# Clean build artifacts (optional)
make clean

# Remove all generated files
make fclean

# Recompile everything
make re
```

### Running the Game

```bash
# Run with a map file
./so_long maps/map1.ber

# Try different maps
./so_long maps/simple.ber
./so_long maps/complex.ber
```

## 🗺️ Map Format

Maps are stored in `.ber` files with the following format:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

### Map Components

| Character | Description |
|-----------|-------------|
| `1` | Wall - impassable terrain |
| `0` | Empty space - walkable area |
| `P` | Player starting position (exactly 1 required) |
| `C` | Collectible item (at least 1 required) |
| `E` | Exit door (exactly 1 required) |

### Map Requirements

- ✅ **Rectangular shape**: All rows must have the same length
- ✅ **Surrounded by walls**: Map must be enclosed by walls (`1`)
- ✅ **Valid path**: Player must be able to reach all collectibles and the exit
- ✅ **Required elements**: Exactly 1 player, exactly 1 exit, at least 1 collectible
- ✅ **File extension**: Must be `.ber`

## 🎯 Game Controls

| Key | Action |
|-----|--------|
| `W` or `↑` | Move Up |
| `A` or `←` | Move Left |
| `S` or `↓` | Move Down |
| `D` or `→` | Move Right |
| `ESC` | Exit Game |
| `X` (window) | Close Game |

## 🎨 Graphics and Assets

The game uses sprite-based graphics with the following assets:
- **Player sprite**: Animated character
- **Wall tiles**: Stone/brick textures
- **Floor tiles**: Ground textures
- **Collectibles**: Gems, coins, or items
- **Exit door**: Goal marker

Assets are stored in the `game_images/` directory in XPM format for compatibility with MiniLibX.

## 🧠 Algorithm Details

### Map Validation (DFS)
The game uses **Depth-First Search** to validate that:
1. All collectibles are reachable from the player's starting position
2. The exit is accessible after collecting all items
3. The map has a valid solution path

### Collision Detection
- **Boundary checking**: Prevents movement outside map bounds
- **Wall collision**: Blocks movement into wall tiles
- **Item collection**: Automatically picks up collectibles on contact
- **Exit validation**: Only allows exit when all items are collected

## 🧪 Testing

Test the game with various map configurations:

```bash
# Test basic functionality
./so_long maps/simple.ber

# Test complex pathfinding
./so_long maps/maze.ber

# Test edge cases
./so_long maps/minimal.ber
./so_long maps/large.ber

# Test error handling
./so_long invalid_map.ber
./so_long maps/unsolvable.ber
```

## ⚠️ Error Handling

The game handles various error conditions:
- **Invalid map format**: Non-rectangular maps, missing walls
- **Missing elements**: No player, exit, or collectibles
- **Unsolvable maps**: No valid path to complete the game
- **File errors**: Missing files, permission issues
- **Memory allocation**: Proper cleanup on allocation failures

## 🎓 Learning Objectives

This project teaches:
- **Graphics Programming**: Working with pixel buffers and sprite rendering
- **Game Development**: Game loops, state management, user input
- **Algorithm Implementation**: Pathfinding and graph traversal
- **File I/O**: Reading and parsing game data files
- **Memory Management**: Dynamic allocation and proper cleanup
- **Event-Driven Programming**: Handling keyboard and window events

## 🏆 42School Evaluation

This project is part of the 42School common core curriculum and is evaluated on:
- **Functionality**: Game works as specified
- **Code Quality**: Clean, readable, and well-structured code
- **Error Handling**: Robust handling of edge cases
- **Memory Management**: No leaks or segmentation faults
- **Norm Compliance**: Follows 42 coding standards

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📚 Additional Resources

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [42School So-Long Subject](https://projects.intra.42.fr/projects/so_long)
- [Game Development Patterns](https://gameprogrammingpatterns.com/)
- [2D Graphics Programming](https://learnopengl.com/Getting-started/Hello-Triangle)

## 📝 License

This project is part of the 42 School curriculum. Feel free to use it for educational purposes.

---

**Note**: This implementation follows 42School's strict coding standards and is designed to demonstrate fundamental game development concepts in C.
