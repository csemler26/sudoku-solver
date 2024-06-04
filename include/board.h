#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <vector>

class SudokuBoard {
private:
    std::vector<std::vector<int>> board;
    const int size = 9;

public:
    SudokuBoard(const std::vector<std::vector<int>>& initialBoard);
    bool isValid(int row, int col, int num);
    bool isSolved();
    void printBoard();
    int getCell(int row, int col);
    void setCell(int row, int col, int num);
    void clearCell(int row, int col);
};

#endif // SUDOKUBOARD_H