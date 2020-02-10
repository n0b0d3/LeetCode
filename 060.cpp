#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        vector<int> capacity;
        if(n <= 0 || k <= 0) {
            return ret;
        }
        for(int i = 1; i <= n; ++i) {
            capacity.push_back(i);
        }
        int idx = n;
        --k;
        while(idx > 0) {
            int m = factorial(idx - 1);
            int k1 = k / m;
            ret += capacity[k1] + '0';
            capacity.erase(capacity.begin() + k1);
            k = k % m;
            --idx;
        }
        return ret;
    }
    int factorial(int n) {
        if(n == 0 || n == 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(1, 1) << endl;
}
