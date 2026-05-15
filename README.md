# Sudoku Solver

A backtracking Sudoku solver written in C. Given a 9×9 grid with some cells pre-filled, it recursively tries digit placements and backtracks on constraint violations until the puzzle is solved.

## How it works

For each empty cell, the solver tries digits 1–9 and checks validity against the cell's row, column, and 3×3 box. If a digit leads to a dead end, it resets the cell and tries the next one. This continues until the board is fully solved or no solution exists.

## Usage

```bash
gcc sudoku.c -o sudoku
./sudoku
```

The puzzle is defined in `main()`. Edit the `mat[9][9]` array to change the input — use `0` for empty cells.

## Example output

```
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9
```
