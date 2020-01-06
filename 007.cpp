#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long z = 0;
        long long y = x;
        vector<int> result;

        if(x == 0) {
            return x;
        }
        if(y < 0) {
            y = -y;
        } else {
            y = y;
        }
        while(y != 0) {
            result.push_back(y%10);
            y = y / 10;
        }
        for(int i = result.size() - 1; i >= 0; --i) {
            z += result[i] * pow(10, result.size() - 1 - i);
        }
        if(x <= 0) {
            if(-z < INT_MIN) {
                return 0;
            }
            return -z;
        } else {
            if(z > INT_MAX) {
                return 0;
            }
            return z;
        }
    }
};

int main() {
    Solution s;
    cout << s.reverse(-2147483648) << endl;
}
