#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() <= 0 || matrix[0].size() <= 0) {
            return false;
        }
        int idx = 0; int jdx = 0;
        while(idx < matrix.size() && matrix[idx][0] <= target) {
            if(matrix[idx][0] == target) {
                return true;
            }
            ++idx;
        }
        --idx;
        if(idx < 0) {
            return false;
        }
        while(jdx < matrix[idx].size()) {
            if(matrix[idx][jdx] == target) {
                return true;
            }
            ++jdx;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1},
    };
    cout << s.searchMatrix(matrix, 1) << endl;
    return 0;
}
