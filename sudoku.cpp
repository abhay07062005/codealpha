#include <iostream>

using namespace std;

// A Sudoku board is a 9x9 grid of integers
const int N = 9;

// Check if a number is valid in a given row, column, and box
bool isValid(int board[N][N], int row, int col, int num) {
  // Check row
  for (int i = 0; i < N; i++) {
    if (board[row][i] == num) {
      return false;
    }
  }

  // Check column
  for (int i = 0; i < N; i++) {
    if (board[i][col] == num) {
      return false;
    }
  }

  // Check box
  int boxRow = row / 3;
  int boxCol = col / 3;
  for (int i = boxRow * 3; i < boxRow * 3 + 3; i++) {
    for (int j = boxCol * 3; j < boxCol * 3 + 3; j++) {
      if (board[i][j] == num) {
        return false;
      }
    }
  }

  // If we reach here, the number is valid
  return true;
}

// Solve the Sudoku board using backtracking
bool solve(int board[N][N]) {
  // Find the next empty cell
  int row, col;
  for (row = 0; row < N; row++) {
    for (col = 0; col < N; col++) {
      if (board[row][col] == 0) {
        // Try all possible numbers for this cell
        for (int num = 1; num <= N; num++) {
          if (isValid(board, row, col, num)) {
            // Place the number in the cell and recursively solve the rest of the board
            board[row][col] = num;
            if (solve(board)) {
              return true;
            }
            // If the board cannot be solved with this number, backtrack and try the next number
            board[row][col] = 0;
          }
        }
        // If we reach here, there is no solution for this board
        return false;
      }
    }
  }

  // If we reach here, the board is solved
  return true;
}

// Print the Sudoku board
void printBoard(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  // Create a Sudoku board
  int board[N][N] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0} 
  };

  // Solve the board
  if (solve(board)) {
    // Print the solution
    printBoard(board);
  } else {
    // The board cannot be solved
    cout << "No solution found" << endl;
  }

  return 0;
}