# Pong-curses

This is a simple ncurses-based game written in C. The game involves controlling paddles to hit a ball back and forth, similar to Pong.

![Peek 2024-06-05 11-10](https://github.com/djeada/Pong-Curses/assets/37275728/3add03c8-3a09-4fb8-a9cc-7791651aea1e)

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

- Up Arrow: Move the left paddle up
- Down Arrow: Move the left paddle down
- q: Move the right paddle up
- a: Move the right paddle down
- p: Pause the game
- Esc: Exit the game

## How to Contribute

We encourage contributions that enhance the repository's value. To contribute:

1. Fork the repository.
2. Create your feature branch (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a Pull Request.

## License

This project is licensed under the [MIT License](LICENSE) - see the LICENSE file for details.

