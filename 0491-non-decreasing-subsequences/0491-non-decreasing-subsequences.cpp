#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, 0, path, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() >= 2) {
            result.push_back(path);
        }

        // Track which values we've already used at THIS level of recursion,
        // to avoid picking the same value twice at the same decision point (duplicate subsequences)
        unordered_set<int> used;

        for (int i = start; i < nums.size(); i++) {
            // Skip if this would break non-decreasing order
            if (!path.empty() && nums[i] < path.back()) {
                continue;
            }

            // Skip if we've already tried this exact value at this level (avoids duplicate subsequences)
            if (used.count(nums[i])) {
                continue;
            }

            used.insert(nums[i]);

            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};