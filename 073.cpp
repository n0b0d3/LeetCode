#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false;
        bool col = false;
        for(int i = 0; i < matrix.size(); ++i) {
            if(matrix[i][0] == 0) {
                col = true;
                break;
            }
        }
        for(int i = 0; i < matrix[0].size(); ++i) {
            if(matrix[0][i] == 0) {
                row = true;
                break;
            }
        }
        for(int i = 1; i < matrix.size(); ++i) {
            for(int j = 1; j < matrix[i].size(); ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); ++i) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < matrix[i].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix[0].size(); ++i) {
            if(matrix[0][i] == 0) {
                for(int j = 1; j < matrix.size(); ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        if(row) {
            for(int i = 0; i < matrix[0].size(); ++i) {
                matrix[0][i] = 0;
            }
        }
        if(col) {
            for(int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> nums = {
        {1, 1, 2, 1},
        {3, 0, 5, 2},
        {1, 3, 1, 5},
    };
    Solution s;
    s.setZeroes(nums);
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = 0; j < nums[i].size(); ++j) {
            cout << nums[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
