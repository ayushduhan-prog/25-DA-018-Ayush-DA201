#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool found = false;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1, n))
                found = true;

            board[row][col] = 0;
        }
    }

    return found;
}

int main() {
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    if (n < 1) {
        cout << "Enter a positive number." << endl;
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    cout << "Possible solutions:\n";

    if (!solveNQueens(board, 0, n)) {
        cout << "No solution exists." << endl;
    }

    return 0;
}