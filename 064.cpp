#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() <= 0 || grid[0].size() <= 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) {
                    continue;
                } else if(i == 0) {
                    grid[i][j] += grid[i][j-1];
                } else if(j == 0) {
                    grid[i][j] += grid[i-1][j];
                } else {
                    grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
                }
            }
        }
        return grid[m-1][n-1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };
    cout << s.minPathSum(nums) << endl;
}
