#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1) ||
                (dividend == INT_MAX && divisor == 1)) {
            return INT_MAX;
        }
        if(!dividend) {
            return 0;
        }
        long long int result = 0;
        bool sign = bool(dividend > 0) == bool(divisor > 0);
        long long int dividendabs = labs(dividend);
        long long int divisorabs = labs(divisor);
        while(divisorabs <= dividendabs) {
            long long int doubles = 1;
            long long int tmp = divisorabs;
            while(tmp <= dividendabs) {
                tmp <<= 1;
                doubles <<= 1;
            }
            tmp >>= 1;
            doubles >>= 1;
            result += doubles;
            dividendabs -= tmp;
        }
        if(sign) {
            return result;
        } else {
            return -result;
        }
    }
};

int main() {
    Solution s;
    cout << s.divide(-2147483648, 1) << endl;
}
