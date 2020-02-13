#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() <= 0 || obstacleGrid[0].size() <= 0) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long int>> nums(m, vector<long long int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(obstacleGrid[i][j] == 1) {
                    nums[i][j] = 0;
                } else if(i == 0 && j == 0){
                    nums[i][j] = 1;
                } else if(i == 0) {
                    nums[i][j] = nums[i][j-1];
                } else if(j == 0) {
                    nums[i][j] = nums[i-1][j];
                } else {
                    nums[i][j] = nums[i][j-1] + nums[i-1][j];
                }
            }
        }
        return nums[m-1][n-1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << s.uniquePathsWithObstacles(nums) << endl;
}
