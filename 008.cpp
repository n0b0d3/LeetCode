#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int c = 1;
        long long sum = 0;
        vector<int> result;
        while(i < str.size() && str[i] == ' ') {
            ++i;
        }
        if(i == str.size()) {
            return 0;
        }
        if(str[i] == '-') {
            c = -1;
            ++i;
        } else if(str[i] == '+') {
            c = 1;
            ++i;
        }
        while(i < str.size() && isNumber(str[i])) {
            result.push_back(str[i] - '0');
            ++i;
        }
        reverse(result.begin(), result.end());
        for(int i = 0; i < result.size(); ++i) {
            if(sum + result[i] * pow(10, i) > 2147483648) {
                sum = 2147483648;
            } else {
                sum = sum + result[i] * pow(10, i);
            }
        }
        sum = c * sum;
        if(sum > INT_MAX) {
            return INT_MAX;
        }
        if(sum < INT_MIN) {
            return INT_MIN;
        }
        return sum;
    }
    bool isNumber(char c) {
        if(c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("-91283472332") << endl;
}
