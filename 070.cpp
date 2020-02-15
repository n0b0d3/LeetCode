#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> result(n+1, 0);
        for(int i = 1; i <= n; ++i) {
            if(i == 1) {
                result[i] = 1;
            } else if (i == 2){
                result[i] = 2;
            } else {
                result[i] = result[i-1] + result[i-2];
            }
        }
        return result[n];
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(3) << endl;
}
