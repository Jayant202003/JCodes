#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> nums;

    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int count = 0;
        int result = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                count++;
                // Replace result with probability 1/count
                if (rand() % count == 0) {
                    result = i;
                }
            }
        }

        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */