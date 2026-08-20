class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
           unordered_map<string, int> indexOf; // restaurant name -> index in list1

        for (int i = 0; i < list1.size(); i++) {
            indexOf[list1[i]] = i;
        }

        vector<string> result;
        int minSum = INT_MAX;

        for (int j = 0; j < list2.size(); j++) {
            if (indexOf.find(list2[j]) != indexOf.end()) {
                int sum = indexOf[list2[j]] + j;

                if (sum < minSum) {
                    // Found a new smaller sum -> reset result
                    minSum = sum;
                    result.clear();
                    result.push_back(list2[j]);
                } else if (sum == minSum) {
                    // Tie -> add to result as well
                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
};