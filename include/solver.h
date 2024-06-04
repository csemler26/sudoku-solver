#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include "board.h"

class SudokuSolver {
private:
    SudokuBoard& board;

public:
    SudokuSolver(SudokuBoard& b);
    bool solve();
    bool findEmptyCell(int& row, int& col);
    bool isSafe(int row, int col, int num);
};

#endif // SUDOKUSOLVER_H