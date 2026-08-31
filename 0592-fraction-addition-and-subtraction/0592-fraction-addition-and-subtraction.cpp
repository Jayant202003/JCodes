#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        long long numResult = 0;
        long long denResult = 1;

        int i = 0;
        int n = expression.size();

        while (i < n) {
            // Parse sign
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '-') ? -1 : 1;
                i++;
            }

            // Parse numerator
            long long num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;

            // Skip '/'
            i++; // expression[i] should be '/'

            // Parse denominator
            long long den = 0;
            while (i < n && isdigit(expression[i])) {
                den = den * 10 + (expression[i] - '0');
                i++;
            }

            // Add this fraction to the running result: numResult/denResult + num/den
            numResult = numResult * den + num * denResult;
            denResult = denResult * den;

            // Reduce the fraction to keep numbers manageable
            long long g = gcd(abs(numResult), denResult);
            if (g > 0) {
                numResult /= g;
                denResult /= g;
            }
        }

        return to_string(numResult) + "/" + to_string(denResult);
    }

private:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};