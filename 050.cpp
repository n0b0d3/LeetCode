#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long int m = n;
        if(x == 0) {
            return 0;
        }
        if(m > 0) {
            return power(x, m);
        } else {
            return 1.0 / power(x, -m);
        }
    }
    double power(double x, long long int n) {
        if(n == 0) {
            return 1;
        }
        if(n == 1) {
            return x;
        }
        double p = power(x, n / 2);
        if((n & 1) == 0) {
            return p * p;
        } else {
            return p * p * x;
        }
    }
};

int main() {
    Solution s;
    cout << s.myPow(1.0, -2147483648) << endl;
}
