#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define N 8
using namespace std;

//Default langhkah kuda
int row[N] = {2, 1, -1, -2, -2, -1, 1, 2};
int col[N] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int r, int c, vector<vector<int>>& board) {
    return (r >= 0 && c >= 0 && r < N && c < N && board[r][c] == -1);
}

int countNeighbours(int r, int c, vector<vector<int>>& board) {
    int count = 0;
    for (int k = 0; k < N; k++) {
        int move_x = r + row[k];
        int move_y = c + col[k];
        if (isValid(move_x, move_y, board)) {
            count++;
        }
    }
    return count;
}

bool compareMoves(int r1, int c1, int r2, int c2, vector<vector<int>>& board) {
    return countNeighbours(r1, c1, board) < countNeighbours(r2, c2, board);
}

bool isClosedTour(int r, int c, int start_x, int start_y, vector<vector<int>>& board) {
    for (int k = 0; k < N; k++) {
        int move_x = r + row[k];
        int move_y = c + col[k];
        if (move_x == start_x && move_y == start_y && board[move_x][move_y] == 1) {
            return true;
        }
    }
    return false;
}

bool knight_tour(int r, int c, int move, int start_x, int start_y, vector<vector<int>>& board) {
    if (move == N * N) {
        if (isClosedTour(r, c, start_x, start_y, board)) {
            return true;
        }
        return false;
    }

    vector<pair<int, int>> nextMoves;

    for (int k = 0; k < N; k++) {
        int move_x = r + row[k];
        int move_y = c + col[k];
        if (isValid(move_x, move_y, board)) {
            nextMoves.push_back({move_x, move_y});
        }
    }

    sort(nextMoves.begin(), nextMoves.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return compareMoves(a.first, a.second, b.first, b.second, board);
    });

    for (const auto& nextMove : nextMoves) {
        int next_x = nextMove.first;
        int next_y = nextMove.second;

        board[next_x][next_y] = move + 1;
        if (knight_tour(next_x, next_y, move + 1, start_x, start_y, board)) {
            return true;
        } 
        else {
            board[next_x][next_y] = -1;
        }
    }

    return false;
}


int main() {
    vector<vector<int>> board(N, vector<int>(N, -1));
    int start_x = 0;
    int start_y = 1;
    board[start_x][start_y] = 1;

    if (knight_tour(start_x, start_y, 1, start_x, start_y, board)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << "  ";
            cout << endl;
        }
    } 
    else {
        cout << "Not possible\n";
    }

    return 0;
}