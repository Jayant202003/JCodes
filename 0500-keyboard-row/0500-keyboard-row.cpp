class Solution {
public:
    vector<string> findWords(vector<string>& words) {
         unordered_map<char, int> rowOf;
        string rows[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        for (int r = 0; r < 3; r++) {
            for (char c : rows[r]) {
                rowOf[c] = r;
            }
        }

        vector<string> result;

        for (string& word : words) {
            bool valid = true;
            int rowIndex = rowOf[tolower(word[0])];

            for (char c : word) {
                if (rowOf[tolower(c)] != rowIndex) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result.push_back(word);
            }
        }

        return result;
    }
};