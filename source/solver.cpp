#include "../include/solver.h"

SudokuSolver::SudokuSolver(SudokuBoard& b) : board(b) {}

bool SudokuSolver::solve() {
    int row, col;
    if (!findEmptyCell(row, col)) {
        return true; // Solved
    }

    for (int num = 1; num <= 9; ++num) {
        if (isSafe(row, col, num)) {
            board.setCell(row, col, num);

            if (solve()) {
                return true;
            }

            board.clearCell(row, col);
        }
    }
    return false;
}

bool SudokuSolver::findEmptyCell(int& row, int& col) {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (board.getCell(row, col) == 0) {
                return true;
            }
        }
    }
    return false;
}

bool SudokuSolver::isSafe(int row, int col, int num) {
    return board.isValid(row, col, num);
}