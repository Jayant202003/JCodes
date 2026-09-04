#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();

        // Early exit: lengths must add up
        if (m + n != s3.size()) return false;

        // dp[i][j] = true if s3[0..i+j-1] can be formed by interleaving
        //            s1[0..i-1] and s2[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // Fill first row (using only s2)
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        // Fill first column (using only s1)
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        // Fill the rest
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // s3's current character (index i+j-1) can come from either
                // s1[i-1] (if dp[i-1][j] was true, meaning the state before taking this s1 char was valid)
                // or s2[j-1] (if dp[i][j-1] was true similarly)
                bool fromS1 = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
                bool fromS2 = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);
                dp[i][j] = fromS1 || fromS2;
            }
        }

        return dp[m][n];
    }
};