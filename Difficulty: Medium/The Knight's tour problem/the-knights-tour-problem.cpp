class Solution {
  private:
    int N;
    const int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool solveTour(vector<vector<int>>& board, int currX, int currY, int step) {
        if (step == N * N) {
            return true;
        }

        for (int i = 0; i < 8; i++) {
            int nextX = currX + moveX[i];
            int nextY = currY + moveY[i];

            if (isSafe(nextX, nextY, board)) {
                board[nextX][nextY] = step;

                if (solveTour(board, nextX, nextY, step + 1)) {
                    return true;
                }

                board[nextX][nextY] = -1;
            }
        }

        return false;
    }

    bool isSafe(int x, int y, const vector<vector<int>>& board) {
        return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
    }

public:
    vector<vector<int>> knightTour(int n) {
        N = n;
        vector<vector<int>> board(N, vector<int>(N, -1));

        if (N == 4) {
            return {};
        }
        
        board[0][0] = 0;

        if (solveTour(board, 0, 0, 1)) {
            return board;
        } else {
            return {};
        }
    }
};