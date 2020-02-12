#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < 1 || n < 1) {
            return 0;
        }
        vector<vector<int>> nums(m, vector<int>(n, 0));

        for(int i = 0; i < m; ++i) {
            nums[i][0] = 1;
        }
        for(int j = 0; j < n; ++j) {
            nums[0][j] = 1;
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                int x = 0; int y = 0;
                if(i - 1 >= 0) {
                    x = nums[i - 1][j];
                }
                if(j - 1 >= 0) {
                    y = nums[i][j - 1];
                }
                nums[i][j] = x + y;
            }
        }
        return nums[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(7, 3) << endl;
}
