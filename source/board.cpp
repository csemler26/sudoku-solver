#include "../include/board.h"
#include <iostream>
#include <vector>

SudokuBoard::SudokuBoard(const std::vector<std::vector<int>>& initialBoard) : board(initialBoard) {}

bool SudokuBoard::isValid(int row, int col, int num) {
    for (int i = 0; i < size; ++i) {
        if (board[row][i] == num || board[i][col] == num || board[row - row % 3 + i / 3][col - col % 3 + i % 3] == num) {
            return false;
        }
    }
    return true;
}

bool SudokuBoard::isSolved() {
    for (const auto& row : board) {
        for (int num : row) {
            if (num == 0) {
                return false;
            }
        }
    }
    return true;
}

void SudokuBoard::printBoard() {
    for (const auto& row : board) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int SudokuBoard::getCell(int row, int col) {
    return board[row][col];
}

void SudokuBoard::setCell(int row, int col, int num) {
    board[row][col] = num;
}

void SudokuBoard::clearCell(int row, int col) {
    board[row][col] = 0;
}