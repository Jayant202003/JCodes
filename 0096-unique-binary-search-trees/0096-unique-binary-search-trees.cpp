class Solution {
public:
    int numTrees(int n) {
          vector<int> dp(n + 1, 0);
        dp[0] = 1; // empty tree is one valid "shape"
        dp[1] = 1; // single node is one valid tree

        for (int nodes = 2; nodes <= n; nodes++) {
            for (int root = 1; root <= nodes; root++) {
                int leftCount = root - 1;        // nodes in left subtree
                int rightCount = nodes - root;    // nodes in right subtree
                dp[nodes] += dp[leftCount] * dp[rightCount];
            }
        }

        return dp[n];
    }
};