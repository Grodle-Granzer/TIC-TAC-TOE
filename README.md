# TIC-TAC-TOE

Welcome to Tic-Tac-Toe — a minimalist, fast, and fun console implementation of the classic 3x3 game written in C++.

> Play against a friend or the computer. Simple rules, endless fun.

---

## Illustration

Here's a friendly ASCII illustration of the board and a sample move sequence:

  1 | 2 | 3
 ---+---+---
  4 | 5 | 6
 ---+---+---
  7 | 8 | 9

Example game (X starts):
- X -> 5
- O -> 1
- X -> 9
- O -> 2
- X -> 3  (X wins)

Visualized:

   O | O | X
  ---+---+---
     | X |
  ---+---+---
     |   | X

---

## Features

- 2-player local play (hotseat)
- Single-player mode with a simple computer opponent (optional)
- Clear console UI with numbered board positions
- Win / draw detection and match restart
- Lightweight: single-file build possible (typical for small C++ projects)

---

## Build

Make sure you have a C++ compiler (g++, clang++, MSVC) installed.

Example with g++ (Linux / macOS / WSL):

```bash
g++ -std=c++17 -O2 -Wall -o tictactoe main.cpp
```

If your project uses other filenames, replace `main.cpp` above with the actual source filename(s), for example:

```bash
g++ -std=c++17 -O2 -Wall -o tictactoe src/game.cpp src/ai.cpp src/main.cpp
```

On Windows with Visual Studio Developer Command Prompt:

```cmd
cl /EHsc /std:c++17 main.cpp /Fe:tictactoe.exe
```

---

## Run

```bash
./tictactoe
```

Sample session:

```
Welcome to Tic-Tac-Toe!
Choose mode:
1) Two-player
2) Play vs CPU
> 1

Player X, enter position (1-9): 5
Player O, enter position (1-9): 1
Player X, enter position (1-9): 9
Player O, enter position (1-9): 2
Player X, enter position (1-9): 3

Player X wins! 🎉
Play again? (y/n)
```

---

## How it works (high-level)

- The board is represented as an array of 9 cells (indices 0..8).
- Players take turns placing their mark (X or O) into an empty cell by entering a number 1–9.
- After each move, the game checks:
  - If any winning line (rows, columns, diagonals) is completed by the last player — declare winner.
  - If all cells are filled without a winner — declare draw.
- If single-player mode: a simple AI chooses a move (could be random, heuristic, or Minimax-based depending on your implementation).

If you paste the actual C++ file(s) I will:
- Replace the high-level explanation above with an exact overview of your functions and data structures.
- Add precise compile/run instructions matching your file names and required flags.
- Extract and show code snippets (e.g., main loop, AI function) and annotate them.
- Optionally generate a UML-like ASCII diagram of main classes/structs.

---

## Contributing

Contributions welcome! Please open issues for:
- Bugs
- Feature requests (e.g., improved AI, GUI, network play)
- Documentation fixes

Suggested workflow:
- Fork the repo
- Create a feature branch: `git checkout -b feat/your-feature`
- Commit and push
- Open a pull request describing the change

---

## Tests

If you have unit tests, add instructions here. For quick manual checks, try all winning lines and boundary moves.

---

## Possible enhancements

- Minimax AI for unbeatable play
- Graphical UI with SDL/ImGui
- 4x4 or NxN configurable board
- Networked multiplayer

---

## License

This project is provided under the MIT License. See LICENSE file for details.

---

## Credits

Created by Grodle-Granzer. Thanks for playing — have fun!
