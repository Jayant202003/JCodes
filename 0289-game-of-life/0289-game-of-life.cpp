#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Encoding: 
        // 0 = was dead, still dead
        // 1 = was live, still live
        // 2 = was live, now dead
        // 3 = was dead, now live

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = countLiveNeighbors(board, i, j, m, n);

                if (board[i][j] == 1) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = 2; // live -> dead
                    }
                } else {
                    if (liveNeighbors == 3) {
                        board[i][j] = 3; // dead -> live
                    }
                }
            }
        }

        // Decode final states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = (board[i][j] == 2) ? 0 : (board[i][j] == 3 ? 1 : board[i][j]);
            }
        }
    }

private:
    int countLiveNeighbors(vector<vector<int>>& board, int row, int col, int m, int n) {
        int count = 0;
        int directions[8][2] = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},        {0,1},
            {1,-1}, {1,0}, {1,1}
        };

        for (auto& dir : directions) {
            int r = row + dir[0];
            int c = col + dir[1];

            if (r >= 0 && r < m && c >= 0 && c < n) {
                // Treat both 1 (still live) and 2 (was live) as "originally live"
                if (board[r][c] == 1 || board[r][c] == 2) {
                    count++;
                }
            }
        }

        return count;
    }
};