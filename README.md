# Pong-curses

This is a simple ncurses-based game written in C. The game involves controlling paddles to hit a ball back and forth, similar to Pong.

## Directory Structure

```
.
├── Makefile
└── src
    ├── main.c
    ├── game.c
    └── game.h
```

## Files

- **Makefile**: Builds the project.
- **README.md**: This file, containing project information.
- **src/main.c**: Contains the main function and game loop.
- **src/game.c**: Contains the game logic and functions.
- **src/game.h**: Contains the declarations for the game functions and structures.

## Prerequisites

- gcc (GNU Compiler Collection)
- ncurses library

## Building the Project

To build the project, follow these steps:

1. Ensure you have `gcc` and `ncurses` installed on your system.
2. Open a terminal in the parent directory where the `Makefile` is located.
3. Run the following command:

 ```sh
 make
```

This will compile the source files and create an executable in the bin directory.

### Running the Game

After building the project, you can run the game by executing the following command in the terminal:

```sh
./bin/game
```

### Cleaning Up

To remove the compiled files, run:

```sh
make clean
```

## Controls

    Up Arrow: Move the left paddle up
    Down Arrow: Move the left paddle down
    q: Move the right paddle up
    a: Move the right paddle down
    p: Pause the game
    Esc: Exit the game
