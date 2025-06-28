#include <iostream>
#include <cmath>

using namespace std;

bool promising(int i, int* board) {
    for (int j = 0; j < i; j++) {
        if (board[i] == board[j] || abs(board[i] - board[j]) == i - j)
            return false;
    }

    return true;
}

int queens(int i, int n, int* board) {
    int count = 0;
    if (i == n) {
        return ++count;
    }

    for (int j = 0; j < n; j++) {
        board[i] = j;
        if (promising(i, board)) {
            count += queens(i+1, n, board);
        }
    }

    return count;
}

int main() {
    int n, board[15];
    cin >> n;
    cout << queens(0, n, board);
    return 0;
}