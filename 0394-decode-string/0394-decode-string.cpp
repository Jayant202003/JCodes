#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int currentNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            } else if (c == '[') {
                // Push current state onto stacks, then reset for the nested content
                countStack.push(currentNum);
                stringStack.push(currentString);
                currentNum = 0;
                currentString = "";
            } else if (c == ']') {
                // Pop and build the repeated string
                int repeatCount = countStack.top();
                countStack.pop();
                string prevString = stringStack.top();
                stringStack.pop();

                string repeated = "";
                for (int i = 0; i < repeatCount; i++) {
                    repeated += currentString;
                }

                currentString = prevString + repeated;
            } else {
                // Regular character
                currentString += c;
            }
        }

        return currentString;
    }
};