#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result(m * n);

        int row = 0, col = 0;
        bool goingUp = true; // true = moving up-right, false = moving down-left

        for (int i = 0; i < m * n; i++) {
            result[i] = mat[row][col];

            if (goingUp) {
                // Moving up-right: try to go to (row-1, col+1)
                if (col == n - 1) {
                    // Hit right wall -> move down, switch direction
                    row++;
                    goingUp = false;
                } else if (row == 0) {
                    // Hit top wall -> move right, switch direction
                    col++;
                    goingUp = false;
                } else {
                    // Normal up-right move
                    row--;
                    col++;
                }
            } else {
                // Moving down-left: try to go to (row+1, col-1)
                if (row == m - 1) {
                    // Hit bottom wall -> move right, switch direction
                    col++;
                    goingUp = true;
                } else if (col == 0) {
                    // Hit left wall -> move down, switch direction
                    row++;
                    goingUp = true;
                } else {
                    // Normal down-left move
                    row++;
                    col--;
                }
            }
        }

        return result;
    }
};