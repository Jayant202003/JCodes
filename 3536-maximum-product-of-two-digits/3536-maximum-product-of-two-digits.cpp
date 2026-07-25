class Solution {
public:
    int maxProduct(int n) {
        int a = 0, b = 0; 

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit > a) {
                b = a;
                a = digit;
            } else if (digit > b) {
                b = digit;
            }
        }

        return a * b;
    }
};