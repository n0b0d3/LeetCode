#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long int idx = 0;
        long long int m = x / 2;
        if(x <= 1) {
            return x;
        }
        while(idx <= m) {
            if(idx * idx > x) {
                break;
            }
            ++idx;
        }
        return idx - 1;
    }
};


int main() {
    Solution s;
    cout << s.mySqrt(2) << endl;
}
